#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Accounts
{
	private:
		string accountName;
		string accountNumber;
		
	public:
		Accounts();
		Accounts(string name, string number);
		
		void setName(string name);
		void setNumber(string number);
		
		string getName();
		string getNumber();
		
		void addAccount();
		void removeAccount();
		void getBalance();
		void writeTransactions();
		void displayAccount();
};