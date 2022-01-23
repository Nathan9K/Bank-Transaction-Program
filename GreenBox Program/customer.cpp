/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 4 - GreenBox Program

customer.cpp
*/

#include <string>
#include "customer.h"

// default constructor sets initial values
customer::customer()
{
	customerID 			= 0;
	customerName 		= "";
	customerCard 		= 0;
	customerKey 		= 0;
	customerExpiration 	= "";
}

// paramaterized constructor sets user defined values
customer::customer(int id, string name, double card, int key, string expiration)
{
	customerID 			= id;
	customerName 		= name;
	customerCard 		= card;
	customerKey 		= key;
	customerExpiration 	= expiration;
}

// set values individually for each data member
void customer::setCustomerID(int id)						{customerID 		= id;}
void customer::setCustomerName(string name)					{customerName 		= name;}
void customer::setCustomerCard(double card)					{customerCard 		= card;}
void customer::setCustomerKey(int key)						{customerKey 		= key;}
void customer::setCustomerExpiration(string expiration)		{customerExpiration = expiration;}
		
// obtain values when functions are called for each data member 
int    	customer::getCustomerID()							{return customerID;}
string 	customer::getCustomerName()							{return customerName;}
double 	customer::getCustomerCard()							{return customerCard;}
int    	customer::getCustomerKey()							{return customerKey;}
string 	customer::getCustomerExpiration()					{return customerExpiration;}