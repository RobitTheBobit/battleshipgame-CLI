// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: updateSea
// Date: 12/11/2024  (European Dates Are Awesome)
// Description: Updates the sea via updating arrays;
//				Handles all sea updates including board wipes;
//				Uses ARRAYS; not VECTORS
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include <iomanip>
#include <iostream>
#include <cstring>
#include <array>
#include "battleship.h"
using namespace std;

void updateSea(char sea[arrayBound][arrayBound], bool hitOrMiss, int userCoordinate1, int userCoordinate2)
{
	char missChar = 'M';
	char hitChar = 'H';
// Update Sea with H or M that is then fed into printSea (the updated sea-map)

	if (hitOrMiss == false)
	{
		sea[userCoordinate1][userCoordinate2] = missChar; //TODO - Implement empty firing tiles
	}
	else
	{
		sea[userCoordinate1][userCoordinate2] = hitChar; //TODO - Implement empty firing tiles
		hitOrMiss = false;
	}
	//Update with 'M' for Miss, 'H' for Hit.
	//NOTE - This necessitates the implementation of things called "Entries"

	//Include logic that will catch if you try to hit a spot you already hit, throwing an error msg.
}