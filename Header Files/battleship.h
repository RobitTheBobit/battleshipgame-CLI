#pragma once
/* VARIABLES */

// Array Square Size
const int arrayBound = 8;

// Health Values
const int battleshipHP = 4;
const int destroyerHP = 3;
const int submarineHP = 3;
const int patrolboatHP = 2;

// The struct below holds the coordinates of the points on our ships.
typedef struct shipCoordinate
{
	int iCoordinate;
	int jCoordinate;
}
shipCoordinate;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

/* Functions */

void initializeSea(char sea[arrayBound][arrayBound], bool hitOrMiss, bool newGame);
void printSea(char sea[arrayBound][arrayBound], bool hitOrMiss, bool newGame);
void updateSea(char sea[arrayBound][arrayBound], bool hitOrMiss, int userCoordinate1, int userCoordinate2);

bool isHit(shipCoordinate battleshipPosition[battleshipHP], shipCoordinate destroyerPosition[destroyerHP], shipCoordinate submarinePosition[submarineHP], shipCoordinate patrolboatPosition[patrolboatHP], int userCoordinate1, int userCoordinate2, int& currBattleshipHP, int& currDestroyerHP, int& currSubmarineHP, int& currpatrolBoatHP);
void placeShip(shipCoordinate battleshipPosition[battleshipHP], shipCoordinate destroyerPosition[destroyerHP], shipCoordinate submarinePosition[submarineHP], shipCoordinate patrolboatPosition[patrolboatHP]);
//void placeShip(int arrayBound, );
// int shipHealth();//TODO - Setup function