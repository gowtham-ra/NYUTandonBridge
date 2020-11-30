//File Name: gr2180_hw9.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw9
//Description: Program that implements a simple two-dimensional predator-prey simulation.
//Last Changed: Sep 17, 2020

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
    //Fetches a random number within the given range
    int getRandomNumber(int range, int optional = 0) {return ((rand() % range) + optional);}

    World() : totalDoodleBugs(NO_OF_DOODLEBUGS), totalAnts(NO_OF_ANTS), timeStepCount(0) {this->initialise();}
    World(int doodleBugsCount, int antsCount) : totalDoodleBugs(doodleBugsCount), timeStepCount(0),
                                                totalAnts(antsCount) {this->initialise();}

    void initialise(); //Initialise the grid and randomly position the given organisms
    void play(); //The function where the actual simulation is played
    void printWorld(); //Prints the simulation
    int getTimeStepCount() const;

    //Destructor
    virtual ~World();

private:
    int totalDoodleBugs;
    int totalAnts;
    int timeStepCount;
};

class Organism {
public:
    Organism() : world(nullptr), positionRow(0), positionColumn(0),
                 breedingTime(0), organismLifeTime(0), moved(false) {}

    Organism(World* theWorld, int row, int column, bool isMoved = false) : world(theWorld),
    positionRow(row), positionColumn(column), breedingTime(0),
    organismLifeTime(theWorld->getTimeStepCount()), moved(isMoved) {}

    virtual void move() = 0;
    virtual void jump();
    virtual void breed() = 0;
    virtual bool starving() {return false;};
    virtual int getType() = 0;
    bool isMoved() {return moved;}
    void setMoved(bool isMoved) {moved = isMoved;}
protected:
    World* world;
    int positionRow;
    int positionColumn;
    int breedingTime;
    int organismLifeTime;
    bool moved;
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
    Ant(World* theWorld, int row, int column, bool isMoved = false) : Organism(theWorld, row, column, isMoved) {}
    virtual int getType() {return ANT;}
    virtual void breed();
    virtual void move();
};

class DoodleBug : public Organism {
public:
    DoodleBug() : Organism(), starvingTime(0) {}
    DoodleBug(World* theWorld, int row, int column, bool isMoved = false) :
    Organism(theWorld, row, column, isMoved), starvingTime(0) {}

    void eat();
    virtual void move();
    virtual void breed();
    virtual bool starving() {return (starvingTime == DOODLEBUG_STARVE_TIME);}
    virtual int getType() {return DOODLEBUG;}

private:
    int starvingTime;
};

void World::initialise() {
    int totalOrganisms = totalAnts + totalDoodleBugs;
    int totalCells = GRID_SIZE * GRID_SIZE;
    if (totalOrganisms > totalCells) {
        cout <<"\nNumber of organisms are higher than available cells in the grid\n";
        exit(1);
    }

    //Pointing all the pointers to null in the grid initially
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++)
            grid[row][column] = nullptr;
    }

    srand(time(0));
    int row, column;
    int doodleBugsCount = 0;
    int antsCount = 0;

    //Assign random empty cells in the grid for DoodleBug objects
    while (doodleBugsCount < totalDoodleBugs) {
        row = getRandomNumber(GRID_SIZE);
        column = getRandomNumber(GRID_SIZE);

        if (grid[row][column] != nullptr) continue;
        grid[row][column] = new DoodleBug(this, row, column, false);
        doodleBugsCount++;
    }

    //Assign random empty cells in the grid for Ant objects
    while (antsCount < totalAnts){
        row = getRandomNumber(GRID_SIZE);
        column = getRandomNumber(GRID_SIZE);

        if (grid[row][column] != nullptr) continue;
        grid[row][column] = new Ant(this, row, column, false);
        antsCount++;
    }
    printWorld();
}

void World::play() {
    char c;
    cout << "\nPlease press the enter key to move to the next time step";
    cin.get(c);

    //Check for any key pressed apart from Enter
    if (c != '\n') {
        cout << "\nThe simulation is ended now because a key other than enter is pressed\n";
        exit(1);
    }

    while (c == '\n') {
        timeStepCount++;
        //Initiate move action for Doodlebugs
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int column = 0; column < GRID_SIZE; column++) {
                if (grid[row][column] == nullptr) continue;
                if (grid[row][column]->getType() == DOODLEBUG) {
                    grid[row][column]->move();

                    //Kill the starving Doodlebugs
                    /*if (grid[row][column]->starving()) {
                        delete grid[row][column];
                        grid[row][column] = nullptr;
                    }*/
                }
            }
        }
        //Initiate move action for Ants
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int column = 0; column < GRID_SIZE; column++) {
                if (grid[row][column] == nullptr)
                    continue;
                if (grid[row][column]->getType() == ANT)
                    grid[row][column]->move();
            }
        }
        //Reset the moved status
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int column = 0; column < GRID_SIZE; column++) {
                if (grid[row][column]->isMoved())
                    grid[row][column]->setMoved(false);
            }
        }
        printWorld(); //Prints the current timeStep
        cin.get(c); //Trigger next timeStep
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

World::~World() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++) {
            if (grid[row][column] != nullptr)
                delete grid[row][column];
        }
    }
}

int World::getTimeStepCount() const {
    return timeStepCount;
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

    for (int direction = 1; direction <= TOTAL_DIRECTIONS; direction++) {
        int tempRow = row;
        int tempColumn = column;
        getTheCell(direction, tempRow, tempColumn);

        if ((isOnTheGrid(tempRow, tempColumn)) && (world->grid[tempRow][tempColumn] == nullptr))
            adjEmptyCells.push_back(direction);
    }
    return adjEmptyCells;
}

void Organism::jump() {
    organismLifeTime++;
    breedingTime++;
    int newRow = positionRow;
    int newColumn = positionColumn;
    int direction = world->getRandomNumber(TOTAL_DIRECTIONS,1);
    getTheCell(direction, newRow, newColumn);

    if (isOnTheGrid(newRow, newColumn)) {
        if (world->grid[newRow][newColumn] != nullptr)
            return;
        else {
            world->grid[newRow][newColumn] = this;
            world->grid[positionRow][positionColumn] = nullptr;
            positionRow = newRow;
            positionColumn = newColumn;
            moved = true;
        }
    }
}

void Ant::move() {
    if (this->organismLifeTime == world->getTimeStepCount())
        return;
    Organism::jump();
    this->breed();
}

void Ant::breed() {
    if (this->breedingTime >= ANT_BREED_PERIOD) {
        int row = positionRow;
        int column = positionColumn;
        vector<int> adjEmptyCells = getEmptyCells(row, column);

        if (!(adjEmptyCells.empty())) {
            int randomIndex = world->getRandomNumber(adjEmptyCells.size());
            int direction = adjEmptyCells[randomIndex];
            getTheCell(direction, row, column);
            world->grid[row][column] = new Ant(world, row, column, true);
            breedingTime = 0;
        }
    }
}

void DoodleBug::move() {
    //Check if the object already moved for this round
    if (this->organismLifeTime == world->getTimeStepCount())
        return;
    //Find adjacent ant and eat
    eat();
    //Normal jump to adjacent cell if not eaten
    if (!(isMoved())) {
        Organism::jump();
        starvingTime++;
    }
    //Breed new DoodleBugs
    breed();
}

void DoodleBug::breed() {
    if (breedingTime >= DOODLEBUG_BREED_PERIOD) {
        int row = positionRow;
        int column = positionColumn;
        vector<int> adjEmptyCells = getEmptyCells(row, column);

        if (!(adjEmptyCells.empty())) {
            int randomIndex = world->getRandomNumber(adjEmptyCells.size());
            int direction = adjEmptyCells[randomIndex];
            getTheCell(direction, row, column);
            world->grid[row][column] = new DoodleBug(world, row,column, true);
            breedingTime = 0;
        }
    }
}

void DoodleBug::eat() {
    vector<int> adjacentAnts;

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

    if (!(adjacentAnts.empty())) {
        int randomIndex = world->getRandomNumber(adjacentAnts.size());
        int direction = adjacentAnts[randomIndex];
        getTheCell(direction, row, column);

        //Eating the ant and moving to that cell
        delete world->grid[row][column];
        world->grid[row][column] = this;
        world->grid[positionRow][positionColumn] = nullptr;
        positionRow = row;
        positionColumn = column;
        starvingTime = 0;
        organismLifeTime++;
        breedingTime++;
        moved = true;
    }
}


int main() {
    World game(5, 100);
    game.play();
    return 0;
}