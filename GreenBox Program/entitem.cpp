/*
Author: Nathan Kevil
Student ID: 11441056
Assignment: Homework 4 - GreenBox Program

CSCE 1040.022
entitem.cpp
*/

#include <string>
#include "entitem.h"
using namespace std;

// entitem
entitem::entitem()
{
	itemID = 0;
	itemCost = 0.0;
	itemStatus = "";
	itemPeriod = "";
}

entitem::entitem(int id, float cost, string status, string period)
{
	itemID = id;
	itemCost = cost;
	itemStatus = status;
	itemPeriod = period;
}

void entitem::setItemID(int id)					{itemID = id;}
void entitem::setItemCost(float cost)			{itemCost = cost;}
void entitem::setItemStatus(string status)		{itemStatus = status;}
void entitem::setItemPeriod(string period)		{itemPeriod = period;}

int    entitem::getItemID()						{return itemID;}
float  entitem::getItemCost()					{return itemCost;}
string entitem::getItemStatus()					{return itemStatus;} 
string entitem::getItemPeriod()					{return itemPeriod;}


// game
game::game()
{
	gameRating = "";
	gameGenre = "";
	gameTitle = "";
	gameRelease = "";
	gameStudio = "";
	gameCost = 0.0;
	gameReplacement = 0.0;
}

game::game(string rating, string genre, string title, string release, string studio, float cost, float replacement)
{
	gameRating = rating;
	gameGenre = genre;
	gameTitle = title;
	gameRelease = release;
	gameStudio = studio;
	gameCost = cost;
	gameReplacement = replacement;
}

void game::setGameRating(string rating)						{gameRating = rating;}
void game::setGameGenre(string genre)						{gameGenre = genre;}
void game::setGameTitle(string title)						{gameTitle = title;}
void game::setGameRelease(string release)					{gameRelease = release;}
void game::setGameStudio(string studio)						{gameStudio = studio;}
void game::setGameCost(float cost)							{gameCost = cost;}
void game::setGameReplacement(float replacement)			{gameReplacement = replacement;}

string game::getGameRating()								{return gameRating;}
string game::getGameGenre()									{return gameGenre;}
string game::getGameTitle()									{return gameTitle;}
string game::getGameRelease()								{return gameRelease;}
string game::getGameStudio()								{return gameStudio;}
float  game::getGameCost()									{return gameCost;}
float  game::getGameReplacement()							{return gameReplacement;}



