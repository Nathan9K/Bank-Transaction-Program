/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 4 - GreenBox Program

CSCE 1040.022
transaction.h
*/

#include <iostream>
#include <string>

using namespace std;

class transaction
{
	private:
		int loanID;			// stores loan id
		int movieID;		// stores movie id
		int custID;			// stores customer id
		string movieTitle;	// stores movie name
		string dueDate;		// stores due date of movie
		
	public:
		// constructors
		transaction();
		transaction(int l_id, int m_id, int c_id, string date, string title);
		
		// set functions
		void setLoanID(int l_id);
		void setMovieID(int m_id);
		void setCustID(int c_id);
		void setDueDate(string date);
		void setMovieTitle(string title);
		
		// get functions
		int 	getLoanID();
		int 	getMovieID();
		int 	getCustID();
		string 	getDueDate();
		string  getMovieTitle();
};