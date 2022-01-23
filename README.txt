Author: Nathan Kevil

Transaction Management (fleshed out CS1 project w/ added class functions)

Overview
--can add user account data (name, type of account (business or personal), transaction processing)
--can remove user account data 
--can process transactions from already existing data taken from files in the program folder 
--can display transaction information for an account
--works for users who create their own data file with a list of transactions

Files
--this program requires the accounts.cpp file with the associated header file, accounts.h as well as the main.cpp file
--145268b.dat (business account) and 145268p.dat (personal account) are sample files used to test the program. they contain lists of transactions 
--account_data.data is another sample file for testing, containing a list of users

How to Run
--make sure accounts.cpp, accounts.h, and main.cpp are in the same directory along with any data files you may want to use (the personal/business account data files must have transactions listed similar to the sample ones provided. Same goes for the account_data.dat file with the account name and number)
--make sure you have an IDE installed for C++ in order to compile the program
--use your compile command in the command prompt (use g++ *.cpp to compile all files at once when you're in the correct directory)
--run the exe file (the program's menu will be displayed)

How to use
--from here, you decide which options to choose from
--you can add an account to the accounts_data.dat, remove an account from the account_data.dat file, add transactions to a personal/business account, or display transaction information from an account