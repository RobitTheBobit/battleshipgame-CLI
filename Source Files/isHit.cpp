// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: isHit
// Date: 12/11/2024  (European Dates Are Awesome)
// Description: Determines if ship is hit 
//
//				Uses ARRAYS; not VECTORS
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstring>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include "battleship.h"

bool isHit(shipCoordinate battleshipPosition[battleshipHP], shipCoordinate destroyerPosition[destroyerHP], shipCoordinate submarinePosition[submarineHP], shipCoordinate patrolboatPosition[patrolboatHP], int userCoordinate1, int userCoordinate2, int& currBattleshipHP, int& currDestroyerHP, int& currSubmarineHP, int& currpatrolBoatHP)
{
	bool hit = false;
	for (int i = 0; i < battleshipHP; i++) //tests for battleship
	{
		if ((battleshipPosition[i].iCoordinate == userCoordinate1) && (battleshipPosition[i].jCoordinate == userCoordinate2))
		{
			hit = true;
			currBattleshipHP--;
		}
	}
	for (int i = 0; i < destroyerHP; i++) //tests for destroyer && submarine
	{
		if ((destroyerPosition[i].iCoordinate == userCoordinate1) && (destroyerPosition[i].jCoordinate == userCoordinate2))
		{
			hit = true;
			currDestroyerHP--;
		}
		else if ((submarinePosition[i].iCoordinate == userCoordinate1) && (submarinePosition[i].jCoordinate == userCoordinate2))
		{
			hit = true;
			currSubmarineHP--;
		}
	}
	for (int i = 0; i < patrolboatHP; i++) //tests for battleship
	{
		if ((patrolboatPosition[i].iCoordinate == userCoordinate1) && (patrolboatPosition[i].jCoordinate == userCoordinate2))
		{
			hit = true;
			currpatrolBoatHP--;
		}
	}
	return hit;
}