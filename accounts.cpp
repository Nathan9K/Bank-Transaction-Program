/*

accounts.cpp

contains the class functions for menu options. each function gets called depending on the menu option in main.cpp

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "accounts.h"

using namespace std;

Accounts::Accounts()
{
	accountName = "";	// initial value for accountName
	accountNumber = "";	// intiial value for accountNumber
}

Accounts::Accounts(string name, string number)
{
	accountName = name;	// store accountName value -- correlates to sets and gets
	accountNumber = number;	// store accountNumber value -- correlates to seta and gets
}

// set/get names and numbers 
void Accounts::setName(string name) 		{accountName = name;}
void Accounts::setNumber(string number)		{accountNumber = number;}
string Accounts::getName()			{return accountName;}
string Accounts::getNumber()			{return accountNumber;}

// addAccount function (option 1) will prompt user to enter in a name and account number to add to the list of accounts in account_data.dat
void Accounts::addAccount()
{
	string name;		// store name that the user enters
	bool option = 0;	// boolean variable for while condition
	
	cout << "Enter your name: ";
	while (option == 0)
	{
		getline(cin, name);	// prompt user to enter name
		
		// make sure that the user only entered in letters or spaces for the name. if not, prompt to enter again
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name.at(i)) || isspace(name.at(i)))
			{
				option = 1;
			}
			else
			{
				option = 0;
				cout << "Name must contain only letters. Please enter again: "; 
				getline(cin, name);
			}
		}
	}
	
	setName(name);	// call set name function: accountName = name
	
	option = 0;	// reset boolean condition for next loop
	string number;
	
	cout << "Enter your account number: "; getline(cin, number);	// prompt user to enter account number
	// check if user only enters digits of length 6. if not, prompt to enter again
	while (option == 0)
	{
		for (int i = 0; i < number.length(); i++)
		{
			if (isdigit(number.at(i)) && number.length() == 6)
			{
				option = 1;
			}
			else 
			{
				option = 0;
				cout << "Account number must be a 6-digit number. Please enter again: ";
				cin >> number;
			}
		}
	}
	
	setNumber(number);	// set account number. accountNumber = number
	
	ofstream appendFile;	// initialize ofstream variable for writing user data to account_data.dat
	appendFile.open("account_data.dat", ios::app);	// open account_data.dat for writing
	
	appendFile << getName() << "," << getNumber() << endl;	// write the following output to account_data.dat
	appendFile.close(); // close file
	
	cout << "Account added (check 'account_data.dat' to confirm)" << endl << endl; // check with user to confirm input is in account_data.dat
	
}

// removeAccount function (option 2) prompts user to enter account name and number and removes associated account
void Accounts::removeAccount()
{
	ifstream fin;	// initialize ifstream variable for reading account_data.dat
	fin.open("account_data.dat");	// open account_data.dat
	
	int accounts = 0; 	// initial value for number of accounts
	string buffer;		// variable to store account_data.dat data when reading file
	
	// read account_data.dat and update number of accounts according to each line in the file
	while (getline(fin, buffer))
	{
		istringstream sstr(buffer);
		while (getline(sstr, buffer, '\n') && ++accounts)
			;
	}
	
	bool option = 0;	// boolean variable for another while loop condition
	string name, number;	// store name and number from user input again
	
	string removeAccount;	// to store full line of data that contains account name and number (will concatenate)
	string lineRemove;	// used to match line with removeAccount variable
	
	fin.close();	// close account_data.dat
	
	ofstream temp;	// temporary ofstream variable for overwiting account_data.dat 
	fin.open("account_data.dat");	// open account_data.dat again for reading
	temp.open("temp.dat");		// creates and opens temporary data file for overwriting
		
	cout << "Enter the account name: ";	// prompt user for account name
	while (option == 0)
	{
		getline(cin, name);
		
		// checks for letters and spaces in account name again. if it has anything else, prompt user to enter again
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name.at(i)) || isspace(name.at(i)))
			{
				option = 1;
			}
			else
			{
				option = 0;
				cout << "Name must contain only letters. Please enter again: "; 
				getline(cin, name);
			}
		}
	}
	
	cout << "Enter the account number: "; getline(cin, number); // prompt user for account number
	while (option == 0)
	{
		
		// checks user input for digits and length 6 again. if anything else, prompt user to enter again
		for (int i = 0; i < number.length(); i++)
		{
			if (isdigit(number.at(i)) && number.length() == 6)
			{
				option = 1;
			}
			else 
			{
				option = 0;
				cout << "Account number must be a 6-digit number. Please enter again: ";
				cin >> number;
			}
		}
	}
	
	removeAccount = name + "," + number;	// concatenate strings to store line similar to format in data file
	
	// if removeAcount is a match, remove the line associated with the account
	while (getline(fin, lineRemove))
	{
		if (lineRemove != removeAccount)
		{
			temp << lineRemove << endl;
		}
	}
	
	// ***need to check if account name and number do not match user input -- must have output 
	
	// close files and overwrite account_data.dat
	temp.close();
	fin.close();
	remove("account_data.dat");
	rename("temp.dat", "account_data.dat");
	
}

// getBalance function (option 3) processes account transactions. *** this function needs to be renamed or split into multiple functions for option 3
void Accounts::getBalance()
{
	string 		accountNumber;		// store account number
	string		accountType;		// store account type
	string		dataFile;		// stores data file name (concat)
	bool 		option = 0;		// while loop condition
	bool 		accOption = 0;		// while loop condition
	double 		transactionAmount;	// stores transaction amount user wants to enter
	
	ifstream 	fin;		// for opening transaction files
	ofstream 	appendFile;	// for appending transactions to transaction files
	
	while (option == 0)
	{
		cout << "Enter the account number to process: "; cin >> accountNumber; // prompt for account number
		while (accOption == 0)
		{
			
			// checks account number conditions again
			for (int i = 0; i < accountNumber.length(); i++)
			{
				if (isdigit(accountNumber.at(i)) && accountNumber.length() == 6)
				{
					accOption = 1;
				}
				else 
				{
					accOption = 0;
					cout << "Account number must be a 6-digit number. Please enter again: ";
					cin >> accountNumber;
				}
			}
		}
		cout << "What is your account type? 0 for Business, 1 for Personal: "; cin >> accountType;	// prompt for business or personal account
		
		
		// conditional statements for checking and storing dataFile concatenation 
		if (accountType == "0")
		{
			dataFile = accountNumber + "b" + ".dat";
		}
		else if (accountType == "1")
		{
			dataFile = accountNumber + "p" + ".dat";
		}
		else 
		{
			cout << "Account type must be entered as 0 for Business or 1 for Personal. Exiting ...";
			exit(1);
		}
		
		fin.open(dataFile);	// open dataFile 
		
		// check if file successfully opened
		if (fin.fail())
		{
			cout << "Unable to open account. Verify if information was entered correctly. Exiting ..." << endl;
			exit(1);
		}
		else 
		{
			option = 1;
		}
	}
	
	// prompt user to enter their transaction. append it to data in dataFile
	if (!fin.fail())
	{
		cout << "Enter your transaction: "; cin >> transactionAmount;
		
		appendFile.open(dataFile, ios::app);
		
		appendFile << transactionAmount << endl;
		appendFile.close();
	}
	
	// initilaize and declare variable to compute sum of transactions
	float x = 0;
	float sum = 0;
	
	// compute the sum of the transactions 
	while (!fin.fail())
	{
		fin >> x;
		if (fin)
		{
			sum += x;
		}
	}
	
	cout << "Total Balance: $" << sum << endl << endl; // display total balance
	
	// close files
	fin.close();
	appendFile.close();
	
}

// displayAccounts function (option 4) is similar to processing accounts statements except it outputs all of the transaction instead of the total balance
void Accounts::displayAccount()
{
	string 		accountNumber;		// store account number
	string		accountType;		// store account type
	string		dataFile;		// store dataFile (concatenation)
	string     	getData;		// used to display account transactions in while loop when reading file
	bool 		option = 0;		// for while loop condition
	bool 		accOption = 0;		// for while loop condition
	double 		transactionAmount;	// stores user transaction amount *** not needed at the moment in this function?
	
	ifstream 	fin;			// for opening file
	
	while (option == 0)
	{
		cout << "Enter the account number to process: "; cin >> accountNumber;	// prompt for account number
		while (accOption == 0)
		{
			// check account number conditions again
			for (int i = 0; i < accountNumber.length(); i++)
			{
				if (isdigit(accountNumber.at(i)) && accountNumber.length() == 6)
				{
					accOption = 1;
				}
				else 
				{
					accOption = 0;
					cout << "Account number must be a 6-digit number. Please enter again: ";
					cin >> accountNumber;
				}
			}
		}
		cout << "Which account to display? 0 for Business, 1 for Personal: "; cin >> accountType;	// prompt for business/personal account
		
		// conditions for concatenating the right strings for dataFile
		if (accountType == "0")
		{
			dataFile = accountNumber + "b" + ".dat";
		}
		else if (accountType == "1")
		{
			dataFile = accountNumber + "p" + ".dat";
		}
		else 
		{
			cout << "Account type must be entered as 0 for Business or 1 for Personal. Exiting ...";
			exit(1);
		}
		
		// open dataFile and check if it was successfully opened
		fin.open(dataFile);
		if (fin.fail())
		{
			cout << "Unable to open account. Verify if information was entered correctly. Exiting ..." << endl;
			exit(1);
		}
		else 
		{
			option = 1;
		}
	}	
	
	// display account transactions
	while (!fin.eof())
	{
		getline(fin, getData);
		cout << getData << endl;
	}
}
