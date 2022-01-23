/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 4 - GreenBox Program

CSCE 1040.022
transaction.cpp
*/

// transaction.cpp

#include <string>
#include "transaction.h"

// set initial values of private class variables
transaction::transaction()
{
	loanID 		= 0;
	movieID 	= 0;
	custID 		= 0;
	dueDate 	= "";
	movieTitle  = "";
}

// set values depending on user input
transaction::transaction(int l_id, int m_id, int c_id, string date, string title)
{
	loanID 		= l_id;
	movieID 	= m_id;
	custID 		= c_id;
	dueDate 	= date;
	movieTitle  = title;
}

// set values in individual functions
void transaction::setLoanID(int l_id)			{loanID = l_id;}
void transaction::setMovieID(int m_id)			{movieID = m_id;}
void transaction::setCustID(int c_id)			{custID = c_id;}
void transaction::setDueDate(string date)		{dueDate = date;}
void transaction::setMovieTitle(string title)   {movieTitle = title;}

// return values when functions are called
int		transaction::getLoanID()				{return loanID;}
int  	transaction::getMovieID()				{return movieID;}
int  	transaction::getCustID()				{return custID;}
string 	transaction::getDueDate()				{return dueDate;}
string  transaction::getMovieTitle()			{return movieTitle;}

