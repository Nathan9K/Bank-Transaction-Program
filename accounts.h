/*

accounts.h

initializes accounts class with variables for name, account number, and process functions for the menu in main.cpp

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Accounts
{
	private:
		string accountName;	// store account name
		string accountNumber;	// store account number
		
	public:
		// constructor and class function to optain name and number
		Accounts();					
		Accounts(string name, string number);
		
		// initialize set functions for name and number 
		void setName(string name);
		void setNumber(string number);
		
		// initialize get functions for name and number
		string getName();
		string getNumber();
		
		void addAccount();		// menu option 1
		void removeAccount();		// menu option 2
		void getBalance();		// for processing accounts in option 3	
		void writeTransactions();	// for processing accounts in option 3
		void displayAccount();		// menu option 4
};
