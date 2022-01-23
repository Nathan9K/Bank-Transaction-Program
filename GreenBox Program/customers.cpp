/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 4 - GreenBox Program

customers.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "customer.h"
#include "customers.h"
using namespace std;

customers::customers()
{
	activeMovies = 0;
}

customers::customers(int movies)
{
	activeMovies = movies;
}

void customers::addCustomer(vector<customer> &customerInfo)	
{
	string name;		// store customer name
	string cardExp;		// store credit card expiration
	char custChoice;	// store user's menu choice
	long long card;		// store credit card info
	int id;				// store id
	int key;			// store validation key
	int movies;			// store number of movies
	
	int size = 10;		// max number for count intially set to 10
	
	cout << endl;
	
	if (customerInfo.size() != 10)	// size of customer vector is initially 10 so this loop is not meant to execute the first time
	{
		for (unsigned int i = customerInfo.size()+1; i < size; i++)
		{
			// collect and store user inputs 
			cout << "Enter customer data for customer " << i << ": " << endl; 		cin.ignore();
			cout << "Name: "; 								getline(cin, name);   //cin.ignore();
			cout << "ID: "; 								cin >> id; 				cin.ignore();
			cout << "Credit Card Number: "; 				cin >> card; 			cin.ignore();
			cout << "Credit Card Validation Number: "; 		cin >> key; 			cin.ignore();
			cout << "Credit Card Expiration: "; 			getline(cin, cardExp);
			//cout << "Number of Active Movies: "; 			cin >> movies;
			
			// resize vector to store additional customers
			customerInfo.resize(i+1);
			
			// use variables which have user inputs stored to set each function within class 
			customerInfo.at(i).setCustomerName(name);
			customerInfo.at(i).setCustomerID(id);
			customerInfo.at(i).setCustomerCard(card);
			customerInfo.at(i).setCustomerKey(key);
			customerInfo.at(i).setCustomerExpiration(cardExp);
			//customerInfo.at(i).setCustMovies(movies);
		
			// check if user wants to add additional customers
			cout << endl;
			cout << "Add another customer? (y/n): "; cin >> custChoice;
			if (custChoice == 'y')			{continue;}
			else if (custChoice == 'n')		{size = customerInfo.size();}
			else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
		}
	}
	else	// this loop executes the first time the user chooses to add a customer
	{
		for (unsigned int i = 0; i < customerInfo.size(); i++)
		{
			cout << "Enter customer data for customer " << i+1 << ": " << endl; 	cin.ignore();
			cout << "Name: "; 								getline(cin, name);   //cin.ignore();
			cout << "ID: "; 								cin >> id; 				cin.ignore();
			cout << "Credit Card Number: "; 				cin >> card; 			cin.ignore();
			cout << "Credit Card Validation Number: "; 		cin >> key; 			cin.ignore();
			cout << "Credit Card Expiration: "; 			getline(cin, cardExp);
			//cout << "Number of Active Movies: "; 			cin >> movies;
		
			// set each function with variables that stored user input
			customerInfo.at(i).setCustomerName(name);
			customerInfo.at(i).setCustomerID(id);
			customerInfo.at(i).setCustomerCard(card);
			customerInfo.at(i).setCustomerKey(key);
			customerInfo.at(i).setCustomerExpiration(cardExp);
			//customerInfo.at(i).setCustMovies(movies);
		
		
			// check if user wants to add additional customers 
			cout << endl;
			cout << "Add another customer? (y/n): "; cin >> custChoice;
			if (custChoice == 'y')			{continue;}
			else if (custChoice == 'n')		{customerInfo.resize(i+1);}
			else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
		}		
	}
}

void customers::removeCustomer(vector<customer> &customerInfo)
{
	int idSearch;
	
	cout << "Enter customer ID: "; cin >> idSearch;
	
	for (unsigned int i = 0; i < customerInfo.size(); i++)
	{
		if (customerInfo.at(i).getCustomerID() == idSearch)
		{
			customerInfo.erase(customerInfo.begin() + i);
			cout << "Customer removed" << endl;
		}
	}
	cout << endl;
}

void customers::printCustomers(vector<customer> &customerInfo)
{
	cout << "Customer Data" << endl; cout << endl;
	for (unsigned int i = 0; i < customerInfo.size(); i++)
	{
		cout << "Customer " << i+1 											<< endl;
		cout << "Name: " << customerInfo.at(i).getCustomerName() 			<< endl;
		cout << "ID: " << customerInfo.at(i).getCustomerID() 				<< endl;
		cout << endl;
	}
}

void customers::storeCustomers(vector<customer> &customerInfo)
{
	
	ofstream fout;
	fout.open("customers.dat");
	
	for (unsigned int i = 0; i < customerInfo.size(); i++)
	{
		fout << customerInfo.at(i).getCustomerID() << " " << customerInfo.at(i).getCustomerName() << endl;
	}		
	
	fout.close();
}

void customers::loadCustomers(vector<customer> &customerInfo)
{
	
	ifstream fin;
	int id;
	string name;
	
	fin.open("customers.dat");
	
	for (unsigned int i = 0; i < customerInfo.size(); i++)
	{
		fin >> id >> name;
		customerInfo.at(i).setCustomerID(id);
		customerInfo.at(i).setCustomerName(name);
	}
	
	fin.close();
	
}