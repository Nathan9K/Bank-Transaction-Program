/*
movie.h
*/

#include <iostream>
#include <string>
#include <cfloat>

using namespace std;

class movie
{
	private:
		int 		movieID;					// stores movie id			
		string 		movieTitle;					// stores movie title
		string	 	movieRating;				// stores rating
		string 		movieLength;				// stores movie length
		string 		movieRelease;				// stores release date
		float 		movieCost;					// stores rental cost
		float 		movieReplacementCost;		// stores replacement cost				
	
	public:
		movie();	// movie constructor
		movie(int id, string title, string rating, string length, string release, float cost, float replace); // movie construnctor that will assign user  values
	
		// set functions that store movie data
		void setMovieID(int id);			
		void setMovieTitle(string title);
		void setMovieRating(string rating);
		void setMovieLength(string length);
		void setMovieRelease(string release);
		void setMovieCost(float cost);
		void setMovieReplacement(float replace);
		
		// get functions that return movie data
		int 	getMovieID();
		string 	getMovieTitle();
		string 	getMovieRating();
		string 	getMovieLength();
		string  getMovieRelease();
		float 	getMovieCost();
		float 	getMovieReplacement();
};
