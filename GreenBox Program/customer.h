/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 4 - GreenBox Program

customer.h
*/

#include <iostream>
#include <string>
using namespace std;

class customer
{
	private:
		// private data members
		int 	customerID;
		string  customerName;
		double 	customerCard;
		int 	customerKey;
		string 	customerExpiration;
		
	public:
		// constructors
		customer();
		customer(int id, string name, double card, int key, string expiration);
		
		// set functions
		void 	setCustomerID(int id);
		void 	setCustomerName(string name);
		void 	setCustomerCard(double card);
		void 	setCustomerKey(int key);
		void 	setCustomerExpiration(string expiration);
		
		// get functions
		int    	getCustomerID();
		string 	getCustomerName();
		double 	getCustomerCard();
		int    	getCustomerKey();
		string 	getCustomerExpiration();
};