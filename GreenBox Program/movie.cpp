/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 4 - GreenBox Program

CSCE 1040.022
movie.cpp
*/

#include <string>
#include "movie.h"

// set initial values of private class variables
movie::movie()
{
	movieID 				= 0;
	movieTitle 				= "";
	movieRating 			= "";
	movieLength 			= "";
	movieRelease			= "";
	movieCost 				= 0.0;
	movieReplacementCost 	= 0.0;
}

// store values of variables based on user input
movie::movie(int id, string title, string rating, string length, string release, float cost, float replace)
{
	movieID 				= id;
	movieTitle 				= title;
	movieRating 			= rating;
	movieLength 			= length;
	movieRelease			= release;
	movieCost 				= cost;
	movieReplacementCost 	= replace;
}

// set values individually
void movie::setMovieID(int id)						{movieID = id;}
void movie::setMovieTitle(string title)				{movieTitle = title;}
void movie::setMovieRating(string rating)			{movieRating = rating;}
void movie::setMovieLength(string length)			{movieLength = length;}
void movie::setMovieRelease(string release)			{movieRelease = release;}
void movie::setMovieCost(float cost)				{movieCost = cost;}
void movie::setMovieReplacement(float replace)		{movieReplacementCost = replace;}

// get functions return values when called
int 	movie::getMovieID()							{return movieID;}
string 	movie::getMovieTitle()						{return movieTitle;}
string 	movie::getMovieRating()						{return movieRating;}
string 	movie::getMovieLength()						{return movieLength;}
string 	movie::getMovieRelease()					{return movieRelease;}
float 	movie::getMovieCost()						{return movieCost;}
float 	movie::getMovieReplacement()				{return movieReplacementCost;}

