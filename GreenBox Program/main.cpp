/*
main.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include "movie.h"
#include "transaction.h"
#include "entitem.h"
#include "customers.h"
#include "movies.h"
#include "games.h"
#include "transactions.h"
using namespace std;

int main()
{
	bool menu = 0;
	bool menuTwo = 0;
	int choice;
	int choiceTwo;
	
	vector<customer> 	customerInfo(10);
	vector<movie> 		movieInfo(10); 
	vector<game>		gameInfo(10);
	vector<transaction> 	loanInfo(1);
	
	customers custs;
	movies movie;
	transactions transaction;
	games game;
	
	custs.loadCustomers(customerInfo);
	movie.loadMovies(movieInfo);
	transaction.loadLoans(customerInfo, movieInfo, loanInfo);
	
	cout << "GREENBOX ENTERTAINMENT" << endl;
	while (menu == 0)
	{
		cout << "0 - Employee Menu Access"			<< endl;
		cout << "1 - Add Customer Info" 			<< endl;
		cout << "2 - Remove Customer Info" 			<< endl;
		cout << "3 - Rent Movie"				<< endl;
		cout << "4 - Rent Game"					<< endl;
		cout << "5 - Display Customer Info" 			<< endl;
		cout << "6 - Display Movie Availability" 		<< endl;
		cout << "7 - Display Loan Info"				<< endl;
		cout << "8 - Quit" 					<< endl;
		
		cout << "Choose an option: "; cin >> choice;

		switch (choice)
		{
			case 0:				
				while (menuTwo == 0)
				{
					cout << "1 - Add Movie" << endl;
					cout << "2 - Add Game" << endl;
					cout << "3 - Back out to main menu" << endl;
					cout << "Choose an option: "; cin >> choiceTwo;
					
					switch (choiceTwo)
					{
						case 1:
							movie.addMovie(movieInfo);
							menuTwo = 1;
							break;
						case 2:
							game.addGame(gameInfo);
							menuTwo = 1;
							break;
						case 3:
							menuTwo = 1;
							break;
					}
				}
				if (menuTwo = 1){menuTwo = 0;}
				menu = 0;
				break;
				
			case 1:
				custs.addCustomer(customerInfo);
				menu = 0;
				break;
				
			case 2:
				custs.removeCustomer(customerInfo);
				menu = 0;
				break;
				
			case 3:
				transaction.rentMovie(customerInfo, movieInfo, loanInfo); 
				menu = 0;
				break;
				
			case 4:
				transaction.rentGame(customerInfo, movieInfo, loanInfo, gameInfo);
				menu = 0;
				break;
				
			case 5:
				custs.printCustomers(customerInfo);
				menu = 0;
				break;
				
			case 6:
				movie.printMovies(movieInfo);
				menu = 0;
				break;
				
			case 7:
				transaction.printLoans(customerInfo, movieInfo, loanInfo);
				menu = 0;
				break;
				
			case 8:
				menu = 1;
				break;
		}	
	}
	
	custs.storeCustomers(customerInfo);
	movie.storeMovies(movieInfo);
	transaction.storeLoans(customerInfo, movieInfo, loanInfo);
	
	return 0;
}
