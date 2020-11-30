/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game;
class Organism;
class Doodlebug;
class Ant;

//valid moves for each organism
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int UP = 4;

const int WORLD_DIMENSION = 10;

//the number of each critter we initialize the world with
const int INIT_DOODLEBUG_COUNT = 5;
const int INIT_ANT_COUNT = 0;

//the time steps it takes for each critter to breed
const int DOODLEBUG_BREED_TIME = 8;
const int ANT_BREED_TIME = 3;

//the time steps it takes for a doodlebug to starve
const int DOODLEBUG_STARVE_TIME = 3;

//number to indicate the type of each critter
const int DOODLEBUG = 1;
const int ANT = 2;

typedef Organism* OrganismPtr;
typedef Game* GamePtr;

class Game {

    friend class Organism;
    friend class Ant;
    friend class Doodlebug;

private:
    OrganismPtr world[WORLD_DIMENSION][WORLD_DIMENSION];
    int timeStepCount;
    int generateRandomNumber(int startRange, int endRange) const;

public:
    Game();
    void startGame();
    void takeTimeStep();
    void printWorld() const;

};

class Organism {

protected:
    GamePtr currGame;
    int x;
    int y;
    int timeTillBreed;
    int organismLifeTime;
    //given a coordinate of the cell (x,y),
    //returns a list of valid moves to adjacent empty cells
    vector<int> getMovesToEmptyCells(int x, int y) const;
    bool isValidCoordinate(int x, int y) const;
    //given a valid move from grid[x][y],
    //updates x and y according to the move
    void getCoordinate(int& x, int& y, int move) const;

public:
    Organism(): currGame(nullptr), x(0), y(0), timeTillBreed(0), organismLifeTime(0){}
    Organism(GamePtr currGame, int x, int y);
    virtual void breed() = 0;
    virtual void move();
    virtual int getType() = 0;
    virtual bool starves() { return false; }

};

class Doodlebug: public Organism {

private:
    int timeTillStarve;
    //given a coordinate of the cell (x,y),
    //returns a list of valid moves to adjacent ants
    vector<int> getMovesToAnts(int x, int y) const;

public:
    Doodlebug(): Organism(), timeTillStarve(0){}
    Doodlebug(GamePtr currGame, int x, int y);
    void breed();
    void move();
    int getType(){ return DOODLEBUG; }
    bool starves(){ return timeTillStarve == 0; }

};

class Ant: public Organism {

public:
    Ant(): Organism(){}
    Ant(GamePtr currGame, int x, int y);
    void breed();
    int getType(){ return ANT; }


};

int Game::generateRandomNumber(int startRange, int endRange) const {
    return rand() % (endRange - startRange + 1) + startRange;
}

Game::Game(){
    srand(time(NULL));
    timeStepCount = 0;
    for (int x = 0; x < WORLD_DIMENSION; x++)
        for (int y = 0; y < WORLD_DIMENSION; y++)
            world[x][y] = nullptr;
}

void Game::startGame(){
    int x,y;
    int doodlebugCount = 0;
    int antCount = 0;

    while (doodlebugCount < INIT_DOODLEBUG_COUNT){
        x = generateRandomNumber(0, WORLD_DIMENSION - 1);
        y = generateRandomNumber(0, WORLD_DIMENSION - 1);
        if (world[x][y] != nullptr) continue;
        world[x][y] = new Doodlebug(this, x, y);
        doodlebugCount++;
    }

    while (antCount < INIT_ANT_COUNT){
        x = generateRandomNumber(0, WORLD_DIMENSION - 1);
        y = generateRandomNumber(0, WORLD_DIMENSION - 1);
        if (world[x][y] != nullptr) continue;
        world[x][y] = new Ant(this, x, y);
        antCount++;
    }
}

void Game::takeTimeStep(){
    timeStepCount++;

    for (int x = 0; x < WORLD_DIMENSION; x++){
        for (int y = 0; y < WORLD_DIMENSION; y++){
            if (world[x][y] == nullptr) continue;
            if (world[x][y]->getType() == DOODLEBUG)
                world[x][y]->move();
        }
    }

    for (int x = 0; x < WORLD_DIMENSION; x++){
        for (int y = 0; y < WORLD_DIMENSION; y++){
            if (world[x][y] == nullptr) continue;
            if (world[x][y]->getType() == ANT)
                world[x][y]->move();
        }
    }

    for (int x = 0; x < WORLD_DIMENSION; x++){
        for (int y = 0; y < WORLD_DIMENSION; y++){
            if (world[x][y] == nullptr) continue;
            world[x][y]->breed();
        }
    }

    for (int x = 0; x < WORLD_DIMENSION; x++){
        for (int y = 0; y < WORLD_DIMENSION; y++){
            if (world[x][y] == nullptr) continue;
            if (world[x][y]->starves()){
                delete world[x][y];
                world[x][y] = nullptr;
            }
        }
    }
}

void Game::printWorld() const {
    for (int x = 0; x < WORLD_DIMENSION; x++){
        for (int y = 0; y < WORLD_DIMENSION; y++){
            if (world[x][y] == nullptr)
                cout << '-';
            else if (world[x][y]->getType() == ANT)
                cout << 'o';
            else  //world[x][y]->getType() == DOODLEBUG
                cout << 'X';
        }
        cout << endl;
    }
}

vector<int> Organism::getMovesToEmptyCells(int x, int y) const {
    vector<int> movesToEmptyCells;
    int tempX, tempY;
    for (int move = LEFT; move <= UP; move++){
        tempX = x;
        tempY = y;
        getCoordinate(tempX, tempY, move);
        if (!isValidCoordinate(tempX, tempY)) continue;
        if (currGame->world[tempX][tempY] == nullptr)
            movesToEmptyCells.push_back(move);
    }
    return movesToEmptyCells;
}

bool Organism::isValidCoordinate(int x, int y) const {
    if (x < 0 || x >= WORLD_DIMENSION || y < 0 || y >= WORLD_DIMENSION)
        return false;
    return true;
}

void Organism::getCoordinate(int& x, int& y, int move) const {
    if (move == LEFT) x--;
    if (move == RIGHT) x++;
    if (move == DOWN) y--;
    if (move == UP) y++;
}

Organism::Organism(GamePtr currGame, int x, int y){
    this->currGame = currGame;
    this->x = x;
    this->y = y;
    timeTillBreed = 0;
    organismLifeTime = currGame->timeStepCount;
}

void Organism::move(){
    if (organismLifeTime == currGame->timeStepCount) return;
    organismLifeTime++;
    timeTillBreed--;
    int randomMove = currGame->generateRandomNumber(LEFT, UP);
    int newX = x;
    int newY = y;
    getCoordinate(newX, newY, randomMove);
    if (isValidCoordinate(newX, newY)){
        if (currGame->world[newX][newY] != nullptr) return;
        currGame->world[x][y] = nullptr;
        currGame->world[newX][newY] = this;
        x = newX;
        y = newY;
    }
}

vector<int> Doodlebug::getMovesToAnts(int x, int y) const {
    vector<int> movesToAnts;
    int tempX, tempY;
    for (int move = LEFT; move <= UP; move++){
        tempX = x;
        tempY = y;
        getCoordinate(tempX, tempY, move);
        if (!isValidCoordinate(tempX, tempY)) continue;
        if (currGame->world[tempX][tempY] == nullptr) continue;
        if (currGame->world[tempX][tempY]->getType() == ANT)
            movesToAnts.push_back(move);
    }
    return movesToAnts;
}

Doodlebug::Doodlebug(GamePtr currGame, int x, int y): Organism(currGame, x, y){
    timeTillStarve = DOODLEBUG_STARVE_TIME;
    timeTillBreed = DOODLEBUG_BREED_TIME;
}

void Doodlebug::breed(){
    if (timeTillBreed > 0) return;
    vector<int> validMoves = getMovesToEmptyCells(x, y);
    if (validMoves.size() == 0) return;
    int randomMove = validMoves[currGame->generateRandomNumber(0, validMoves.size() - 1)];
    int newX = x;
    int newY = y;
    getCoordinate(newX, newY, randomMove);
    currGame->world[newX][newY] = new Doodlebug(currGame, newX, newY);
    timeTillBreed = DOODLEBUG_BREED_TIME;
}

void Doodlebug::move(){
    if (organismLifeTime == currGame->timeStepCount) return;
    vector<int> movesToAnts = getMovesToAnts(x, y);
    if (movesToAnts.size() == 0){
        Organism::move();
        timeTillStarve--;
        return;
    }
    organismLifeTime++;
    timeTillStarve = DOODLEBUG_STARVE_TIME;
    int randomMove = movesToAnts[currGame->generateRandomNumber(0, movesToAnts.size() - 1)];
    int antX = x;
    int antY = y;
    getCoordinate(antX, antY, randomMove);
    delete currGame->world[antX][antY];
    currGame->world[antX][antY] = this;
    currGame->world[x][y] = nullptr;
    x = antX;
    y = antY;
}

Ant::Ant(GamePtr currGame, int x, int y): Organism(currGame, x, y){
    timeTillBreed = ANT_BREED_TIME;
}

void Ant::breed(){
    if (timeTillBreed > 0) return;
    vector<int> validMoves = getMovesToEmptyCells(x, y);
    if (validMoves.size() == 0) return;
    int randomMove = validMoves[currGame->generateRandomNumber(0, validMoves.size() - 1)];
    int newX = x;
    int newY = y;
    getCoordinate(newX, newY, randomMove);
    currGame->world[newX][newY] = new Ant(currGame, newX, newY);
    timeTillBreed = ANT_BREED_TIME;
}

int main(){
    char userInput;
    Game g;

    cout << "WELCOME TO DOODLEBUG VS. ANTS GAME" << endl;
    cout << "Please enter to start the game, anything else to end" << endl;
    cin.get(userInput);

    if (userInput != '\n'){
        cout << "Ending Program..." << endl;
        exit(0);
    }

    g.startGame();
    cout << "This is your randomly generated game board!" << endl << endl;
    g.printWorld();
    cout << endl;

    cout << "Please enter to generate a timestep, anything else to abort: " << endl;
    cin.get(userInput);

    while(userInput == '\n'){
        g.takeTimeStep();
        g.printWorld();
        cout << endl;
        cout << "Please enter to generate a timestep, anything else to abort: " << endl;
        cin.get(userInput);
    }

    cout << "Ending Program..." << endl;

    return 0;
}*/
