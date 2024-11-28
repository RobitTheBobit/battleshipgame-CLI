// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: printSea
// Date: 12/11/2024  (European Dates Are Awesome)
// Description: Prints sea for a game of battleship
//				Uses ARRAYS; not VECTORS
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "battleship.h"
//#include "functions.h"
using namespace std;

void printSea(char sea[arrayBound][arrayBound], bool hitOrMiss, bool newGame) //Prints current sea configuration. If (newgame == true), wipe the board clean.
{
	char fillChar = '|';
	string fillString = " --+---+---+---+---+---+---+---+---+";
	string gapString = "  |   |   |   |   |   |   |   |   |"; //TODO - replace with for loop that outputs from array alongside the empty spaces.

	cout << "   ";
	for (int i = 0; i < (arrayBound); i++) // 
	{
		cout << "| " << i << " ";
	}
	cout << '|';
	cout << endl;
	cout << fillString << endl; //TODO - replace with array for loop
	for (int i = 0; i < arrayBound; i++)
	{
		cout << " ";
		cout << i << " ";
		for (int j = 0; j < arrayBound; j++)
		{
			cout << "| " << sea[i][j] << " ";
			//cout << i << gapString << endl; //outputs line num && array dots.
		}
		cout << "|" << endl;
		cout << fillString << endl; //TODO - replace with array for loop
	}
	cout << endl;
}
/*
if (newGame = true) //Wipe the SLATE CLEAN for a BRAND NEW GAME of Battleship (Single Player Edition by RIT student)
{
	for (int i = 0; i < arrayBound; i++)
	{
		for (int j = 0; j < arrayBound; j++)
		{
			sea[i][j] = ' '; //TODO - Implement empty firing tiles
			cout << sea[i][j]; //TODO - Test this outputs map
		}
	}
	newGame = false;
}
*/
//else
//{
//updateSea(hitOrMiss); //Print sea that has changed in the process of playing the game
//}

/* TODO
create ocean
create mechanism to display ocean
*/
