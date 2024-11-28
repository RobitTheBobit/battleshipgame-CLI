// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: initializeSea
// Date: 12/11/2024  (European Dates Are Awesome)
// Description: Wipes board for new game start
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include <iomanip>
#include <iostream>
#include <cstring>
#include <array>
#include "battleship.h"
using namespace std;

void initializeSea(char sea[arrayBound][arrayBound], bool hitOrMiss, bool newGame) //Passes a char array by reference so it can be void
{
	if (newGame == true) //Clears the board
	{
		for (int i = 0; i < arrayBound; i++)
		{
			for (int j = 0; j < arrayBound; j++)
			{
				sea[i][j] = ' '; //TODO - Implement empty firing tiles
				//cout << sea[i][j]; //TODO - Test this outputs map
			}
		}
		newGame = false;
	}
}