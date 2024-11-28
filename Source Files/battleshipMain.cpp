// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: battleshipMain
// Date: 12/11/2024  (European Dates Are Awesome)
// Description: Main file for game battleship
// 
//				A group of functions masquerading as a single one
//				under the guise of a trenchcoat
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstring>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include "battleship.h"
using namespace std;

int main(void)
{
	bool newGame = true;
	bool endOfSetupPhase = false; // Checks if board has been setup or not
	bool endOfGame = false;
	bool hitOrMiss = false; //when true, indicates a hit

	bool battleshipSunk = false;
	bool destroyerSunk = false;
	bool submarineSunk = false;
	bool patrolboatSunk = false;

	// Tests for Win
	bool gameOver = false; // Redundant?
	bool victory = false;

	int userCoordinate1, userCoordinate2;
	int memeCounter = 0;

	const int maxBoardHP = (battleshipHP + destroyerHP + submarineHP + patrolboatHP);
	int hitCountDown = maxBoardHP;

	int currBattleshipHP = battleshipHP;
	int currDestroyerHP = destroyerHP;
	int currSubmarineHP = submarineHP;
	int currpatrolBoatHP = submarineHP;

	char playAgain = 'y';

	char sea[arrayBound][arrayBound];
	shipCoordinate battleshipPosition[battleshipHP]; //TODO - IMPLEMENT SHIPS
	shipCoordinate destroyerPosition[destroyerHP];
	shipCoordinate submarinePosition[submarineHP];
	shipCoordinate patrolboatPosition[patrolboatHP]; // TODO -- IMPLEMENT SHIPS
	do
	{
		initializeSea(sea, hitOrMiss, newGame);
		while (endOfGame == false)
		{
			if (endOfSetupPhase == false) //Allows for setting up ships before the game 'starts'
			{
				//placeShip(); //TODO - Implement placeShip
				placeShip(battleshipPosition, destroyerPosition, submarinePosition, patrolboatPosition);
				printSea(sea, hitOrMiss, newGame);
				endOfSetupPhase = true;
			}
			else if (endOfSetupPhase == true) //'Starts' the game for normal play
			{
				do
				{
					cout << "Where would the general like to strike?" << endl;	// START OF USER INPUT
					cout << "Input horizontal coordinate: ";
					cin >> userCoordinate1;
					cout << "Input lateral coordinate: ";
					cin >> userCoordinate2;
					system("pause");
					system("cls"); // Only works for windows machines. Linux users can cry themselves to hibernate.
					if ((userCoordinate1 == 'f') || (userCoordinate2 == 'f'))
					{
						cout << "Deposing General in a military coup-de-tat. Goodbye, General." << endl;
						return 1;
					} // flavor text
					if (((userCoordinate1 > 7) || (userCoordinate1 < 0)) || (userCoordinate2 > 7) || (userCoordinate2 < 0)) // Flavor Text
					{
						if (memeCounter < 1)
						{
							cout << "Please try again" << endl;
						}
						memeCounter++;
						if (memeCounter >= 2)
						{
							cout << "The stupid general has provided a coordinate that is not on the map. Please try again or forfit the game by pressing 'f'" << endl;
						}
						cout << endl;
						printSea(sea, hitOrMiss, newGame);
					}
					else
					{
						hitOrMiss = isHit(battleshipPosition, destroyerPosition, submarinePosition, patrolboatPosition, userCoordinate1, userCoordinate2, currBattleshipHP, currDestroyerHP, currSubmarineHP, currpatrolBoatHP); // Function Call
						if ((hitOrMiss == true) && (sea[userCoordinate1][userCoordinate2] == ' '))
						{
							hitCountDown--; //Lower cumulative hitpoints
							cout << "THE GENERAL HAS HIT A SHIP!" << endl;
						}
						else if ((hitOrMiss == false) && (sea[userCoordinate1][userCoordinate2] == ' '))
						{
							cout << endl;
							cout << "THE GENERAL HAS WASTED VALUABLE AMMO! (MISS)" << endl;
						}
						else
						{
							cout << "We already tried that square General!" << endl;
						}
						if (hitCountDown <= 0) //When there are no more hitpoints left
						{
							victory = true;
						}
					}

				} while (((userCoordinate1 > 7) || (userCoordinate1 < 0)) || (userCoordinate2 > 7) || (userCoordinate2 < 0));
				cout << endl;												// END OF USER INPUT

				updateSea(sea, hitOrMiss, userCoordinate1, userCoordinate2);
				printSea(sea, hitOrMiss, newGame);
				if ((currBattleshipHP <= 0) && (battleshipSunk == false))	// START OF HANDLING SINK EVENT
				{
					cout << "You have sunk my Battleship" << endl;
					battleshipSunk = true;
				}
				else if ((currDestroyerHP <= 0) && (destroyerSunk == false))
				{
					cout << "You have sunk my Destroyer" << endl;
					destroyerSunk = true;
				}
				else if ((currSubmarineHP <= 0) && (submarineSunk == false))
				{
					cout << "You have sunk my Submarine" << endl;
					submarineSunk = true;
				}
				else if ((currpatrolBoatHP <= 0) && (patrolboatSunk == false))
				{
					cout << "You have sunk my Patrol Boat" << endl;
					patrolboatSunk = true;
				}	// END OF HANDLING SINK EVENT
				if (victory == true)
				{
					cout << endl;
					cout << "Would you like to play again? (Enter 'Y' or 'y' for yes, anything else for no)" << endl;
					cout << endl;
					cin >> playAgain;
					if (tolower(playAgain) == 'y')
					{
						hitOrMiss = false;
						initializeSea(sea, hitOrMiss, newGame);
						victory = false;
						endOfGame = false;
						endOfSetupPhase = false;
						hitCountDown = maxBoardHP;

						currBattleshipHP = battleshipHP;
						currDestroyerHP = destroyerHP;
						currSubmarineHP = submarineHP;
						currpatrolBoatHP = patrolboatHP;

						battleshipSunk = false;
						destroyerSunk = false;
						submarineSunk = false;
						patrolboatSunk = false;
					}
					else
					{
						endOfGame = true;
					}
					//TODO - Exit loop and ask to play again.
				}
			}
		}
	} while ((playAgain == tolower('Y') || (playAgain == toupper('y'))));
}