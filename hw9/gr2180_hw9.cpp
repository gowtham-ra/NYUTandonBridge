//File Name: gr2180_hw9.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw9
//Description: Program that implements a simple two-dimensional predator-prey simulation.
//Last Changed: Sep 18, 2020

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

const int GRID_SIZE = 20; //Size x Size Grid
const int NO_OF_DOODLEBUGS = 5; //Default no of doodlebugs
const int NO_OF_ANTS = 100; //Default no of ants

//Types of organisms
const int DOODLEBUG = 1;
const int ANT = 2;

//Breeding Period for organisms
const int DOODLEBUG_BREED_PERIOD = 8;
const int ANT_BREED_PERIOD = 3;

const int DOODLEBUG_STARVE_TIME = 3; //Doodlebug starvation period before death

//Directions for movement
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
const int TOTAL_DIRECTIONS = 4;

class World;
class Organism;
class Ant;
class DoodleBug;

class World {
public:
    Organism* grid[GRID_SIZE][GRID_SIZE];
    //Generates a random number within the given range
    int getRandomNumber(int range, int optional = 0) {return ((rand() % range) + optional);}

    //Constructors
    World() : totalDoodleBugs(NO_OF_DOODLEBUGS), totalAnts(NO_OF_ANTS), timeStepCount(0) {this->initialise();}
    World(int doodleBugsCount, int antsCount) : totalDoodleBugs(doodleBugsCount), timeStepCount(0),
    totalAnts(antsCount) {this->initialise();}

    void initialise(); //Initialise the grid and randomly position the given organisms
    void play(); //Starts the play
    void printWorld(); //Prints the objects and empty spaces

    //Destructor
    virtual ~World();

private:
    int totalDoodleBugs;
    int totalAnts;
    int timeStepCount;
public:
    int getTimeStepCount() const;
};

class Organism {
public:
    Organism() : world(nullptr), positionRow(0), positionColumn(0),
                 breedingTime(0), organismLifeTime(0) {}
    Organism(World* theWorld, int row, int column) : world(theWorld),
    positionRow(row), positionColumn(column), breedingTime(0), organismLifeTime(theWorld->getTimeStepCount()) {}

    virtual void move(); //Moves the organism to adjacent cell
    virtual void breed() = 0; //Pure virtual function for organism breeding
    virtual bool starving() {return false;}; //Check if the doodlebug organism is starving
    virtual int getType() = 0; //Pure virtual function to get the type of animal

protected:
    World* world;
    int positionRow;
    int positionColumn;
    int breedingTime;
    int organismLifeTime;
    //Fetches the neighbouring cell for the given direction
    void getTheCell(int direction, int& newRow, int& newColumn);
    //Checks if the row and column are within the grid
    bool isOnTheGrid(int row, int column);
    //Fetches the neighbouring empty cell locations in an array
    vector<int> getEmptyCells(int row, int column);
};

class Ant : public Organism {
public:
    Ant() : Organism(){};
    Ant(World* theWorld, int row, int column) : Organism(theWorld, row, column) {}

    virtual int getType() {return ANT;} //Returns the type of organism
    virtual void breed(); //Breeds the ant if it reaches the breeding time
    virtual void move(); //Redefined move function to model the movement of Ant
};

class DoodleBug : public Organism {
public:
    DoodleBug() : Organism(), starvingTime(0) {}
    DoodleBug(World* theWorld, int row, int column) : Organism(theWorld, row, column), starvingTime(0) {}

    virtual int getType() {return DOODLEBUG;} //Returns the type of organism
    virtual void move(); //Redefined move function to model the movement of Doodlebug
    virtual void breed(); //Breeds the doodlebug if it reaches the breeding time
    virtual bool starving() {return starvingTime == DOODLEBUG_STARVE_TIME;} //Check if the doodlebug is starving

private:
    int starvingTime;
};

void World::initialise() {
    //Check for more organisms initialised than cells available.
    int totalOrganisms = totalAnts + totalDoodleBugs;
    int totalCells = GRID_SIZE * GRID_SIZE;
    if (totalOrganisms > totalCells) {
        cout <<"\nNo of organisms are higher than available cells in the grid\n";
        exit(1);
    }

    //Pointing all the cells in the grid to null initially
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++)
            grid[row][column] = nullptr;
    }

    srand(time(0));
    int row, column;
    int doodleBugsCount = 0;
    int antsCount = 0;

    //Assign random empty cells in the grid for DoodleBugs
    while (doodleBugsCount < totalDoodleBugs) {
        row = getRandomNumber(GRID_SIZE);
        column = getRandomNumber(GRID_SIZE);

        if (grid[row][column] != nullptr) continue;
        grid[row][column] = new DoodleBug(this, row, column);
        doodleBugsCount++;
    }

    //Assign random empty cells in the grid for Ants
    while (antsCount < totalAnts){
        row = getRandomNumber(GRID_SIZE);
        column = getRandomNumber(GRID_SIZE);

        if (grid[row][column] != nullptr) continue;
        grid[row][column] = new Ant(this, row, column);
        antsCount++;
    }
    printWorld(); //Displays the grid in the current time step to screen.
}

void World::play() {
    cout << "\nPlease press the enter key to move to the next time step";
    char c;
    cin.get(c);

    if (c != '\n') {
        cout << "\nThe simulation is ended now because a key other than enter is pressed\n";
        exit(1);
    }

    while (c == '\n') {
        timeStepCount++;

        //Move the doodlebugs
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int column = 0; column < GRID_SIZE; column++) {
                if (grid[row][column] == nullptr)
                    continue;
                if (grid[row][column]->getType() == DOODLEBUG)
                    grid[row][column]->move();
            }
        }

        //Move the ants
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int column = 0; column < GRID_SIZE; column++) {
                if (grid[row][column] == nullptr)
                    continue;
                if (grid[row][column]->getType() == ANT)
                    grid[row][column]->move();
            }
        }

        //Breed the organisms
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int column = 0; column < GRID_SIZE; column++) {
                if (grid[row][column] == nullptr)
                    continue;
                grid[row][column]->breed();
            }
        }

        //Kill the starving doodlebugs
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int column = 0; column < GRID_SIZE; column++) {
                if (grid[row][column] == nullptr)
                    continue;
                if (grid[row][column]->starving()) {
                    delete grid[row][column];
                    grid[row][column] = nullptr;
                }
            }
        }
        printWorld(); //Displays the grid in the current time step to screen.

        //Trigger next time step
        cin.get(c);
        if (c != '\n') {
            cout << "\nThe simulation is ended now because a key other than enter is pressed\n";
            exit(1);
        }
    }
}

void World::printWorld() {
    cout << endl;
    for (auto & row : grid) {
        for (auto organism : row) {
            if (organism == nullptr)
                cout << '-';
            else if (organism->getType() == DOODLEBUG)
                cout << 'X';
            else
                cout << 'o';
        }
        cout << endl;
    }
}

int World::getTimeStepCount() const {
    return timeStepCount;
}

World::~World() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++) {
            if (grid[row][column] != nullptr)
                delete grid[row][column];
        }
    }
}

void Organism::move() {
    organismLifeTime++;
    breedingTime++;
    int newRow = positionRow;
    int newColumn = positionColumn;
    //Choose a random direction to move
    int direction = world->getRandomNumber(TOTAL_DIRECTIONS,1);
    //Get the coordinates of the chosen cell
    getTheCell(direction, newRow, newColumn);

    if (isOnTheGrid(newRow, newColumn)) {
        //Don't move if the selected cell is not empty
        if (world->grid[newRow][newColumn] != nullptr)
            return;
        //Move if the selected cell is empty
        else {
            world->grid[newRow][newColumn] = this;
            world->grid[positionRow][positionColumn] = nullptr;
            positionRow = newRow;
            positionColumn = newColumn;
        }
    }
}

void Organism::getTheCell(int direction, int& newRow, int& newColumn) {
    switch (direction) {
        case UP:
            newRow--;
            break;
        case DOWN:
            newRow++;
            break;
        case LEFT:
            newColumn--;
            break;
        case RIGHT:
            newColumn++;
            break;
        default:
            cout <<"Random number generation error -> Wrong direction\n";
            exit(1);
    }
}

bool Organism::isOnTheGrid(int row, int column) {
    return ((row >= 0) && (row < GRID_SIZE) && (column >= 0) && (column < GRID_SIZE));
}

vector<int> Organism::getEmptyCells(int row, int column) {
    vector<int> adjEmptyCells;

    //Iterate each direction and add the cell to the vector if it's empty
    for (int direction = 1; direction <= TOTAL_DIRECTIONS; direction++) {
        int tempRow = row;
        int tempColumn = column;
        getTheCell(direction, tempRow, tempColumn);

        if ((isOnTheGrid(tempRow, tempColumn)) && (world->grid[tempRow][tempColumn] == nullptr))
            adjEmptyCells.push_back(direction);
    }
    return adjEmptyCells;
}

void Ant::move() {
    //Check if the ant is moved already for the current time step
    if (this->organismLifeTime == world->getTimeStepCount())
        return;
    else
        Organism::move();
}

void Ant::breed() {
    if (this->breedingTime >= ANT_BREED_PERIOD) {
        int row = positionRow;
        int column = positionColumn;
        vector<int> adjEmptyCells = getEmptyCells(row, column);

        //Breed if empty cell is available
        if (!(adjEmptyCells.empty())) {
            int randomIndex = world->getRandomNumber(adjEmptyCells.size());
            int direction = adjEmptyCells[randomIndex];
            getTheCell(direction, row, column);
            world->grid[row][column] = new Ant(world, row, column);
            breedingTime = 0;
        }
    }
}

void DoodleBug::move() {
    //Check if the doodlebug is moved already for the current time step
    if (this->organismLifeTime == world->getTimeStepCount())
        return;

    vector<int> adjacentAnts;

    //Find all the adjacent adds
    for (int direction = 1; direction <= TOTAL_DIRECTIONS; direction++) {
        int row = positionRow;
        int column = positionColumn;

        getTheCell(direction, row, column);

        if ((isOnTheGrid(row, column)) && (world->grid[row][column] != nullptr)
        && (world->grid[row][column]->getType() == ANT))
            adjacentAnts.push_back(direction);
    }

    int row = positionRow;
    int column = positionColumn;

    //If there are ants, choose random one and eat it
    if (!(adjacentAnts.empty())){
        int randomIndex = world->getRandomNumber(adjacentAnts.size());
        int direction = adjacentAnts[randomIndex];
        getTheCell(direction, row, column);

        //Move to the cell and eat the ant
        delete world->grid[row][column];
        world->grid[row][column] = this;
        world->grid[positionRow][positionColumn] = nullptr;
        positionRow = row;
        positionColumn = column;
        starvingTime = 0;
        organismLifeTime++;
        breedingTime++;
    }
    //Move to an empty cell if no adjacent ants
    else {
        Organism::move();
        starvingTime++;
    }
}

void DoodleBug::breed() {
    if (breedingTime >= DOODLEBUG_BREED_PERIOD) {
        int row = positionRow;
        int column = positionColumn;
        vector<int> adjEmptyCells = getEmptyCells(row, column);

        //Breed if empty cell is available
        if (!(adjEmptyCells.empty())) {
            int randomIndex = world->getRandomNumber(adjEmptyCells.size());
            int direction = adjEmptyCells[randomIndex];
            getTheCell(direction, row, column);
            world->grid[row][column] = new DoodleBug(world, row,column);
            breedingTime = 0;
        }
    }
}

int main() {
    World game(5, 100);
    game.play();
    return 0;
}
