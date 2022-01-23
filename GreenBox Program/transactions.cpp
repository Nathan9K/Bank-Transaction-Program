/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 3 - GreenBox Program

CSCE 1040.022
*/

// transactions.cpp

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

#include "customer.h"
#include "movie.h"
#include "entitem.h"
#include "transaction.h"
#include "customers.h"
#include "movies.h"
#include "transactions.h"

using namespace std;

void transactions::rentMovie(vector<customer> &customerInfo, vector<movie> &movieInfo, vector<transaction> &loanInfo)
{
	int 	m_id;		// store movie id
	int 	c_id;		// store customer id
	int 	l_id;		// store loan id
	string  m_title;	// store movie name
	string 	date;		// store due date
	
	string 	titleSearch;	// used to match title 
	int 	idSearch;		// used to match customer id
	int 	movieSearch;	// used to match movie id
	
	char 	userChoice;		// for menu choice
	
	// randomize loan id
	srand(time(NULL));
	long randomizedID = (rand() % 900001) + 100000;
	
	cout << endl;
	cout << "Enter your customer ID: "; cin >> idSearch; cin.ignore();
	
	// this loop will check user information and let them rent movies 
	for (unsigned int i = 0; i < loanInfo.size(); i++)
	{
		if (customerInfo.at(i).getCustomerID() == idSearch)
		{
			
			cout << "Enter the title of the movie you would like to rent: "; getline(cin, titleSearch);
			cout << "Enter the the movie ID: "; cin >> movieSearch;
			
			if ( (movieInfo.at(i).getMovieID() == movieSearch) && (movieInfo.at(i).getMovieTitle() == titleSearch) )
			{
				l_id 	= randomizedID;
				c_id 	= customerInfo.at(i).getCustomerID();
				m_id 	= movieInfo.at(i).getMovieID();
				m_title = movieInfo.at(i).getMovieTitle();
				
				loanInfo.at(i).setLoanID(l_id);
				loanInfo.at(i).setMovieID(m_id);
				loanInfo.at(i).setCustID(c_id);
				loanInfo.at(i).setMovieTitle(m_title);
				
				cout << "Would you like to rent an additional movie?(y/n): "; cin >> userChoice;
				if (userChoice == 'y')			{loanInfo.resize(i+2);}
				else if (userChoice == 'n')		{break;}
				else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
				
			}		
			
		}

	}
}

void transactions::rentGame(vector<customer> &customerInfo, vector<movie> &movieInfo, vector<transaction> &loanInfo, vector<game> &gameInfo)
{

	string  m_title;	// store movie name
	string 	date;		// store due date
	int     itemID;
	
	string 	titleSearch;	// used to match title 
	int 	idSearch;		// used to match customer id
	int 	movieSearch;	// used to match movie id
	
	char 	userChoice;		// for menu choice
	
	// randomize loan id
	srand(time(NULL));
	long randomizedID = (rand() % 900001) + 100000;
	
	cout << endl;
	cout << "Enter your customer ID: "; cin >> idSearch; cin.ignore();
	
	// this loop will check user information and let them rent movies 
	for (unsigned int i = 0; i < loanInfo.size(); i++)
	{
		if (customerInfo.at(i).getCustomerID() == idSearch)
		{
			
			cout << "Enter the title of the game you would like to rent: "; getline(cin, titleSearch);
			
			if (gameInfo.at(i).getGameTitle() == titleSearch)
			{
				itemID 	= randomizedID;
				
				loanInfo.at(i).setLoanID(itemID);
				
				cout << "Would you like to rent an additional movie?(y/n): "; cin >> userChoice;
				if (userChoice == 'y')			{loanInfo.resize(i+2);}
				else if (userChoice == 'n')		{break;}
				else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
				
			}		
			
		}

	}
}

// print loan data
void transactions::printLoans(vector<customer> &customerInfo, vector<movie> &movieInfo, vector<transaction> &loanInfo)
{
	cout << endl;
	for (unsigned int i = 0; i < loanInfo.size(); i++)
	{
		cout << "Customer ID: " << loanInfo.at(i).getCustID() << endl;
		cout << "Movie Title: " << loanInfo.at(i).getMovieTitle() << endl;
		cout << "Movie ID: " 	<< loanInfo.at(i).getMovieID() << endl;
		cout << "Loan ID: " 	<< loanInfo.at(i).getLoanID() << endl;
		cout << endl;
	}
}

// store loan data
void transactions::storeLoans(vector<customer> &customerInfo, vector<movie> &movieInfo, vector<transaction> &loanInfo)
{
	ofstream fout;
	fout.open("loans.dat");
	
	for (unsigned int i = 0; i < loanInfo.size(); i++)
	{
		fout << loanInfo.at(i).getLoanID() << " " << loanInfo.at(i).getMovieTitle() << endl;
	}
	
	fout.close();
}

// load loan data
void transactions::loadLoans(vector<customer> &customerInfo, vector<movie> &movieInfo, vector<transaction> &loanInfo)
{
	ifstream fin;
	int id;
	string name;
	
	fin.open("loans.dat");
	
	for (unsigned int i = 0; i < loanInfo.size(); i++)
	{
		fin >> id >> name;
		loanInfo.at(i).setLoanID(id);
		loanInfo.at(i).setMovieTitle(name);
	}
	
	fin.close();
}

