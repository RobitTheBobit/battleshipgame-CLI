// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: placeShip
// Date: 12/11/2024  (European Dates Are Awesome)
// Description: Determines where the ships will be held in relation
//				to the board matrix. 
//
//				Uses ARRAYS; not VECTORS
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstring>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include "battleship.h"
using namespace std;

bool isHorizontal(void)
{
	bool coinFlipValue = (rand() % 2);
	return coinFlipValue;
}

void placeShip(shipCoordinate battleshipPosition[battleshipHP], shipCoordinate destroyerPosition[destroyerHP], shipCoordinate submarinePosition[submarineHP], shipCoordinate patrolboatPosition[patrolboatHP])
{
	int battleshipStartPointHori;
	int battleshipStartPointVerti; // Battleships
	int destroyerStartPointHori;
	int destroyerStartPointVerti; // Destroyers
	int submarineStartPointHori;
	int submarineStartPointVerti; //Subway Subs
	int patrolboatStartPointHori;
	int patrolboatStartPointVerti; // Fishing Boats

	bool collisionDetect = false;



	if (isHorizontal() == true)
	{
		battleshipStartPointHori = rand() % 8;
		battleshipStartPointVerti = rand() % 4;

		for (int i = 0; i < battleshipHP; i++) // TEMP STATIC VALUES
		{
			battleshipPosition[i].iCoordinate = battleshipStartPointHori;
			battleshipPosition[i].jCoordinate = battleshipStartPointVerti + i;
		}
	}
	else
	{
		battleshipStartPointHori = rand() % 4;
		battleshipStartPointVerti = rand() % 8;

		for (int i = 0; i < battleshipHP; i++) // TEMP STATIC VALUES
		{
			battleshipPosition[i].iCoordinate = battleshipStartPointHori + i;
			battleshipPosition[i].jCoordinate = battleshipStartPointVerti;
		}
	}
	while (true)
	{
		collisionDetect = false;
		if (isHorizontal() == true)
		{
			destroyerStartPointHori = rand() % 8;
			destroyerStartPointVerti = rand() % 4;

			for (int i = 0; i < destroyerHP; i++) // TEMP STATIC VALUES
			{
				destroyerPosition[i].iCoordinate = destroyerStartPointHori;
				destroyerPosition[i].jCoordinate = destroyerStartPointVerti + i;
			}
		}
		else
		{
			destroyerStartPointHori = rand() % 4;
			destroyerStartPointVerti = rand() % 8;

			for (int i = 0; i < destroyerHP; i++) // TEMP STATIC VALUES
			{
				destroyerPosition[i].iCoordinate = battleshipStartPointHori + i;
				destroyerPosition[i].jCoordinate = battleshipStartPointVerti;
			}
		}
		for (int i = 0; i < battleshipHP; i++)
		{
			for (int j = 0; j < destroyerHP; j++)
			{
				if ((battleshipPosition[i].iCoordinate == destroyerPosition[j].iCoordinate) && (battleshipPosition[i].jCoordinate == destroyerPosition[j].jCoordinate))
				{
					collisionDetect = true;
				}
			}
		}
		if (collisionDetect == false)
		{
			break;
		}
	}
	while (true)
	{
		collisionDetect = false;
		if (isHorizontal() == true)
		{
			submarineStartPointHori = rand() % 8;
			submarineStartPointVerti = rand() % 4;

			for (int i = 0; i < submarineHP; i++) // TEMP STATIC VALUES
			{
				submarinePosition[i].iCoordinate = submarineStartPointHori;
				submarinePosition[i].jCoordinate = submarineStartPointVerti + i;
			}
		}
		else
		{
			submarineStartPointHori = rand() % 4;
			submarineStartPointVerti = rand() % 8;

			for (int i = 0; i < submarineHP; i++) // TEMP STATIC VALUES
			{
				submarinePosition[i].iCoordinate = submarineStartPointHori + i;
				submarinePosition[i].jCoordinate = submarineStartPointVerti;
			}
		}
		for (int i = 0; i < battleshipHP; i++)
		{
			for (int j = 0; j < destroyerHP; j++)
			{
				for (int k = 0; k < submarineHP; k++)
				{
					if ((battleshipPosition[i].iCoordinate == submarinePosition[k].iCoordinate) && (battleshipPosition[i].jCoordinate == submarinePosition[k].jCoordinate))
					{
						collisionDetect = true;
					}
					else if ((destroyerPosition[j].iCoordinate == submarinePosition[k].iCoordinate) && (destroyerPosition[j].jCoordinate == submarinePosition[k].jCoordinate))
					{
						collisionDetect = true;
					}
				}
			}
		}
		if (collisionDetect == false)
		{
			break;
		}
	}
	while (true)
	{
		collisionDetect = false;
		if (isHorizontal() == true)
		{
			patrolboatStartPointHori = rand() % 8;
			patrolboatStartPointVerti = rand() % 4;

			for (int i = 0; i < patrolboatHP; i++) // TEMP STATIC VALUES
			{
				patrolboatPosition[i].iCoordinate = patrolboatStartPointHori;
				patrolboatPosition[i].jCoordinate = patrolboatStartPointVerti + i;
			}
		}
		else
		{
			patrolboatStartPointHori = rand() % 4;
			patrolboatStartPointVerti = rand() % 8;

			for (int i = 0; i < patrolboatHP; i++) // TEMP STATIC VALUES
			{
				patrolboatPosition[i].iCoordinate = patrolboatStartPointHori + i;
				patrolboatPosition[i].jCoordinate = patrolboatStartPointVerti;
			}
		}
		for (int i = 0; i < battleshipHP; i++)
		{
			for (int j = 0; j < destroyerHP; j++)
			{
				for (int k = 0; k < submarineHP; k++)
				{
					for (int l = 0; l < patrolboatHP; l++)
					{
						if ((battleshipPosition[i].iCoordinate == patrolboatPosition[l].iCoordinate) && (battleshipPosition[i].jCoordinate == patrolboatPosition[l].jCoordinate))
						{
							collisionDetect = true;
						}
						else if ((destroyerPosition[j].iCoordinate == patrolboatPosition[l].iCoordinate) && (destroyerPosition[j].jCoordinate == patrolboatPosition[l].jCoordinate))
						{
							collisionDetect = true;
						}
						else if ((submarinePosition[k].iCoordinate == patrolboatPosition[l].iCoordinate) && (submarinePosition[k].jCoordinate == patrolboatPosition[l].jCoordinate))
						{
							collisionDetect = true;
						}
					}
				}
			}
		}
		if (collisionDetect == false)
		{
			break;
		}
	}
	/*
	if (isHorizontal == true)
	{
		int horizontalStartingPoint[4] = (rand() % 8);
	}
	else if (isHorizontal == false)
	{
		int verticalStartingPoint[4] = (rand() % 8); // Uses array so that values within array can be compared to one another to ensure no intersection occurs
	}
	*/
}
/*
TODO - implement ship location(an array of elements,
prefixed by ship type which is hard-coded to have a 
certain length of continuous locations via their respective vectors/arrays 
I WANT TO HAVE A 2 array/vector. One bool, one int. Then, I will have a function read in my bools, and if 1 then H else M.
*/


/* 
I could store my values into a few resource files (HDD/SSD), or I could more efficently hold them in RAM of the pc.
*/



/* PSEUDOCODE */
/*

if (coinFlip == 0) //TODO - define coinFlip
{
	ship goes horizontally; //TODO - fix the vertical variable of this 2D array;
}
else if (coinFlip == 1) //TODO - define coinFlip
{
	ship goes vertically; //TODO - fix the horizontal variable of this 2D array;
}
fetch (shipType)

startingPosition = //TODO - implement rand function with % to limit between 0 and const int arrayBound;



*/