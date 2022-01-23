#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "accounts.h"

using namespace std;

Accounts::Accounts()
{
	accountName = "";
	accountNumber = "";
}

Accounts::Accounts(string name, string number)
{
	accountName = name;
	accountNumber = number;
}

void Accounts::setName(string name) 		{accountName = name;}
void Accounts::setNumber(string number)		{accountNumber = number;}
string Accounts::getName()					{return accountName;}
string Accounts::getNumber()				{return accountNumber;}

void Accounts::addAccount()
{
	string name;
	bool option = 0;
	
	cout << "Enter your name: ";
	while (option == 0)
	{
		getline(cin, name);
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
	
	setName(name);
	
	option = 0;
	string number;
	
	cout << "Enter your account number: "; getline(cin, number);
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
	
	setNumber(number);
	
	ofstream appendFile;
	appendFile.open("account_data.dat", ios::app);
	
	appendFile << getName() << "," << getNumber() << endl;
	appendFile.close();
	
	cout << "Account added (check 'account_data.dat' to confirm)" << endl << endl;
	
}

void Accounts::removeAccount()
{
	ifstream fin;
	fin.open("account_data.dat");
	
	int accounts = 0;
	string buffer;
	
	while (getline(fin, buffer))
	{
		istringstream sstr(buffer);
		while (getline(sstr, buffer, '\n') && ++accounts)
			;
	}
	
	bool option = 0;
	string name, number;
	
	string removeAccount;
	string lineRemove;
	
	fin.close();
	
	ofstream temp;
	fin.open("account_data.dat");
	temp.open("temp.dat");
	
	cout << "Enter the account name: ";
	while (option == 0)
	{
		getline(cin, name);
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
	
	cout << "Enter the account number: "; getline(cin, number);
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
	
	removeAccount = name + "," + number;
	
	while (getline(fin, lineRemove))
	{
		if (lineRemove != removeAccount)
		{
			temp << lineRemove << endl;
		}
	}
	
	// ***need to check if account name and number do not match user input -- must have output 
	
	temp.close();
	fin.close();
	remove("account_data.dat");
	rename("temp.dat", "account_data.dat");
	
}

void Accounts::getBalance()
{
	string 		accountNumber;
	string		accountType;
	string		dataFile;
	bool 		option = 0;
	bool 		accOption = 0;
	double 		transactionAmount;
	
	ifstream 	fin;
	ofstream 	appendFile;
	
	while (option == 0)
	{
		cout << "Enter the account number to process: "; cin >> accountNumber;
		while (accOption == 0)
		{
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
		cout << "What is your account type? 0 for Business, 1 for Personal: "; cin >> accountType;
		
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
	
	if (!fin.fail())
	{
		cout << "Enter your transaction: "; cin >> transactionAmount;
		
		appendFile.open(dataFile, ios::app);
		
		appendFile << transactionAmount << endl;
		appendFile.close();
	}
	
	float x = 0;
	float sum = 0;
	
	while (!fin.fail())
	{
		fin >> x;
		if (fin)
		{
			sum += x;
		}
	}
	
	cout << "Total Balance: $" << sum << endl << endl;
	
	fin.close();
	appendFile.close();
	
}

void Accounts::displayAccount()
{
	string 		accountNumber;
	string		accountType;
	string		dataFile;
	string      getData;
	bool 		option = 0;
	bool 		accOption = 0;
	double 		transactionAmount;
	
	ifstream 	fin;
	
	while (option == 0)
	{
		cout << "Enter the account number to process: "; cin >> accountNumber;
		while (accOption == 0)
		{
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
		cout << "Which account to display? 0 for Business, 1 for Personal: "; cin >> accountType;
		
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
	
	while (!fin.eof())
	{
		getline(fin, getData);
		cout << getData << endl;
	}
}

/*class Accounts
{
	private:
		string accountName;
		string accountNumber;
		int	   accountType;
		
	public:
		Accounts();
		Accounts(string name, string number, string type);
		
		void setName(string name);
		void setNumber(string number);
		
		string getName();
		string getNumber();
		
		void addAccount();
		void removeAccount();
		void getBalance();
		void writeTransactions();
		void displayAccount();
};*/