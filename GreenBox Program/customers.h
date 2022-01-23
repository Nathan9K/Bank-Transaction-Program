/*
customers.h
*/

#include <vector>
using namespace std;

class customers
{
	private:
		int activeMovies;
	
	public:
		customers();
		customers(int movies);
		
		void addCustomer(vector<customer> &customerInfo);
		void removeCustomer(vector<customer> &customerInfo);
		void printCustomers(vector<customer> &customerInfo);
		void storeCustomers(vector<customer> &customerInfo);
		void loadCustomers(vector<customer> &customerInfo);
};
