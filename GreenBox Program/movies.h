/*
movies.h
*/

// movies.h

#include <vector>

using namespace std;

class movies
{
	private:	
	public:
		// class gives user the option to add/edit/remove and display movie data 
		void addMovie(vector<movie> &movieInfo);
		void editMovie(vector<movie> &movieInfo);
		void removeMovie(vector<movie> &movieInfo);
		void printMovies(vector<movie> &movieInfo);
		
		// store and load into dat files
		void storeMovies(vector<movie> &movieInfo);
		void loadMovies(vector<movie> &movieInfo);
};
