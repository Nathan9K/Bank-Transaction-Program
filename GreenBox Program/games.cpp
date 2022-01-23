
/*
games.cpp
*/

#include <string>
#include <iostream>
#include "entitem.h"
#include "games.h"
using namespace std;


void games::addGame(vector<game> &gameInfo)
{
	int 	id;
	string 	title;
	string 	rating;
	string 	release;
	float 	cost		= 6.00;
	float 	replace		= 40.00;
	
	char gameChoice;
	
	int size = 10;
	
	cout << endl;
	
	if (gameInfo.size() != 10)
	{
		for (unsigned int i = gameInfo.size()+1; i < size; i++)
		{
			cout << "Enter info to add games to possible rental list" << endl;		cin.ignore();
			cout << "Game Title: "; 					getline(cin, title);	  //cin.ignore();
			cout << "Game Rating(x/10): "; 			cin >> rating;				cin.ignore();
			cout << "Game Release Date: "; 			getline(cin, release);    //cin.ignore();
		
			gameInfo.resize(i+1);

			gameInfo.at(i).setGameTitle(title);
			gameInfo.at(i).setGameRating(rating);
			gameInfo.at(i).setGameRelease(release);
			gameInfo.at(i).setGameCost(cost);
			gameInfo.at(i).setGameReplacement(replace);
		
			cout << endl;
			cout << "Add another game? (y/n): "; cin >> gameChoice;
		
			if (gameChoice == 'y')			{continue;}
			else if (gameChoice == 'n')	{size = gameInfo.size(); break;}
			else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
		}
	}
	else
	{
		for (unsigned int i = 0; i < gameInfo.size(); i++)
		{
			cout << "Enter info to add games to possible rental list" << endl;		cin.ignore();
			cout << "Game Title: "; 					getline(cin, title);	  //cin.ignore();
			cout << "Game Rating(x/10): "; 			cin >> rating;				cin.ignore();
			cout << "Game Release Date: "; 			getline(cin, release);    //cin.ignore();
		
			gameInfo.at(i).setGameTitle(title);
			gameInfo.at(i).setGameRating(rating);
			gameInfo.at(i).setGameRelease(release);
			gameInfo.at(i).setGameCost(cost);
			gameInfo.at(i).setGameReplacement(replace);
		
			cout << endl;
			cout << "Add another game? (y/n): "; cin >> gameChoice;
		
			if (gameChoice == 'y')			{continue;}
			else if (gameChoice == 'n')	{gameInfo.resize(i+1); break;}
			else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
		}		
	}	
}
