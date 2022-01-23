/*

Author: Nathan Kevil

Transaction Management
--can add user account data (name, type of account (business or personal), transaction processing)
--can remove user account data 
--can process transactions from already existing data taken from files in the program folder 

*/

// main.cpp
// contains the display menu and calls functions according to the user's choice

#include <iostream>
#include <string>
#include <fstream>		
#include <sstream>
#include "accounts.h"

using namespace std;

int main()
{	
	string menuChoice;	// stored user input for menu choice
	bool menu = 0;		// declaration of boolean var for menu loop
	
	Accounts accounts;	// class initialization of accounts
	
	cout << endl; cout << "Welcome to your Transaction Processing System" << endl;
	cout << "Refer to the README file before using" << endl << endl;
	
	while (menu == 0)	// condition for menu loop
	{
		cout << "Select from the list of options below" << endl;
		
		// menu options. user must only be able to enter any integer from 1-5
		cout << "1. Add Account" << endl;
		cout << "2. Remove Account" << endl;
		cout << "3. Process Accounts" << endl;
		cout << "4. Display Account Information" << endl;
		cout << "5. Quit" << endl;
		
		// user enters choice
		cout << "Enter your choice: "; cin >> menuChoice;
		
		// conditions for menu choices. if user doesn't enter a valid input, prompt to enter again and loop
		// keep looping until the user decides to quit program
		if 	(menuChoice == "1") {accounts.addAccount(); menu = 0;}
		else if (menuChoice == "2") {accounts.removeAccount(); menu = 0;}
		else if (menuChoice == "3") {accounts.getBalance(); menu = 0;}
		else if (menuChoice == "4") {accounts.displayAccount(); menu = 0;}
		else if (menuChoice == "5") {cout << endl << "Exiting ..." << endl; menu = 1;}	
		else 	{cout << "Not a valid option, please enter again..." << endl; menu = 0;}	
	}
	
	return 0;
}
