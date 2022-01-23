/*
movies.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "movie.h"
#include "movies.h"

using namespace std;

// this function is set up and works the same way as addCustomers in customers.cpp
void movies::addMovie(vector<movie> &movieInfo)
{
	int 	id;
	string 	title;
	string 	rating;
	string 	length;
	string 	release;
	float 	cost		= 3.00;
	float 	replace		= 20.00;
	
	char movieChoice;
	
	int size = 10;
	
	cout << endl;
	
	if (movieInfo.size() != 10)
	{
		for (unsigned int i = movieInfo.size()+1; i < size; i++)
		{
			cout << "Enter info to add movies to possible rental list" << endl;		cin.ignore();
			cout << "Movie Title: "; 					getline(cin, title);	  //cin.ignore();
			cout << "Movie ID: "; 						cin >> id;					cin.ignore();
			cout << "Movie Rating(x/10): "; 			cin >> rating;				cin.ignore();
			cout << "Movie Length: "; 					cin >> length;				cin.ignore();
			cout << "Movie Release Date: "; 			getline(cin, release);    //cin.ignore();
		
			movieInfo.resize(i+1);
			
			movieInfo.at(i).setMovieID(id);
			movieInfo.at(i).setMovieTitle(title);
			movieInfo.at(i).setMovieRating(rating);
			movieInfo.at(i).setMovieLength(length);
			movieInfo.at(i).setMovieRelease(release);
			movieInfo.at(i).setMovieCost(cost);
			movieInfo.at(i).setMovieReplacement(replace);
		
			cout << endl;
			cout << "Add another movie? (y/n): "; cin >> movieChoice;
		
			if (movieChoice == 'y')			{continue;}
			else if (movieChoice == 'n')	{size = movieInfo.size(); break;}
			else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
		}
	}
	else
	{
		for (unsigned int i = 0; i < movieInfo.size(); i++)
		{
			cout << "Enter info to add movies to possible rental list" << endl;		cin.ignore();
			cout << "Movie Title: "; 					getline(cin, title);	  //cin.ignore();
			cout << "Movie ID: "; 						cin >> id;					cin.ignore();
			cout << "Movie Rating(x/10): "; 			cin >> rating;				cin.ignore();
			cout << "Movie Length: "; 					cin >> length;				cin.ignore();
			cout << "Movie Release Date: "; 			getline(cin, release);    //cin.ignore();
		
			movieInfo.at(i).setMovieID(id);
			movieInfo.at(i).setMovieTitle(title);
			movieInfo.at(i).setMovieRating(rating);
			movieInfo.at(i).setMovieLength(length);
			movieInfo.at(i).setMovieRelease(release);
			movieInfo.at(i).setMovieCost(cost);
			movieInfo.at(i).setMovieReplacement(replace);
		
			cout << endl;
			cout << "Add another movie? (y/n): "; cin >> movieChoice;
		
			if (movieChoice == 'y')			{continue;}
			else if (movieChoice == 'n')	{movieInfo.resize(i+1); break;}
			else							{cout << "Please enter 'y' or 'n' - exiting to menu" << endl; break;}
		}		
	}
}

// this function is set up and works the same as editCustomers 
void movies::editMovie(vector<movie> &movieInfo)
{
	int idSearch;
	int editChoice;
	
	string newTitle;
	string newRating;
	string newLength;
	string newRelease;
	
	cout << endl;
	cout << "Enter Movie ID: "; cin >> idSearch;
	
	for (unsigned int i = 0; i < movieInfo.size(); i++)
	{
		if (movieInfo.at(i).getMovieID() == idSearch)
		{
			cout << "What would you like to edit?" 		<< endl;
			cout << "1 - Title"							<< endl;
			cout << "2 - Rating"						<< endl;
			cout << "3 - Length"						<< endl;
			cout << "4 - Release"						<< endl;
			cout << "Choos an option: "; cin >> editChoice; cin.ignore();
		
			switch (editChoice)
			{
				case 1:
					cout << "Enter movie title: "; getline(cin, newTitle);
					break;
				case 2:
					cout << "Enter updated rating: "; cin >> newRating;
					break;
				case 3:
					cout << "Enter movie length: "; cin >> newLength;
					break;
				case 4:
					cout << "Enter release date: "; getline(cin, newRelease);
					break;
			}
		
			movieInfo.at(i).setMovieTitle(newTitle);
			movieInfo.at(i).setMovieRating(newRating);
			movieInfo.at(i).setMovieLength(newLength);
			movieInfo.at(i).setMovieRelease(newRelease);
		}
		cout << endl;
	}
}

// works the same way as removeCustomers
void movies::removeMovie(vector<movie> &movieInfo)
{
	int idSearch;
	
	cout << "Enter movie ID: "; cin >> idSearch;
	
	for (unsigned int i = 0; i < movieInfo.size(); i++)
	{
		if (movieInfo.at(i).getMovieID() == idSearch)
		{
			movieInfo.erase(movieInfo.begin() + i);
			cout << "Movie removed" << endl;
		}
	}
}

// print movie data
void movies::printMovies(vector<movie> &movieInfo)
{
	cout << endl;
	//cout << "Movie Data" << endl;
	for (unsigned int i = 0; i < movieInfo.size(); i++)
	{
		cout << "Movie " << i+1 << endl;
		cout << "Movie Title: " << movieInfo.at(i).getMovieTitle() << endl;
		cout << "Movie ID: " << movieInfo.at(i).getMovieID() << endl;
		cout << "Movie Rating: " << movieInfo.at(i).getMovieRating() << endl;
		cout << "Movie Length: " << movieInfo.at(i).getMovieLength() << endl;
		cout << "Movie Release Date: " << movieInfo.at(i).getMovieRelease() << endl;
		cout << "Movie Rental Cost: " << movieInfo.at(i).getMovieCost() << endl;
		cout << "Any overdue fees will charge accounts $1.00 per day that it is overdue" << endl;
		cout << endl;
	}
}

// store movies
void movies::storeMovies(vector<movie> &movieInfo)
{
	ofstream fout;
	fout.open("movies.dat");
	
	for (unsigned int i = 0; i < movieInfo.size(); i++)
	{
		fout << movieInfo.at(i).getMovieID() << " " << movieInfo.at(i).getMovieTitle() << endl;
	}
	
	fout.close();
}

// load movies
void movies::loadMovies(vector<movie> &movieInfo)
{
	ifstream fin;
	int id;
	string name;
	
	fin.open("movies.dat");
	
	for (unsigned int i = 0; i < movieInfo.size(); i++)
	{
		fin >> id >> name;
		movieInfo.at(i).setMovieID(id);
		movieInfo.at(i).setMovieTitle(name);
	}
	
	fin.close();	
}

