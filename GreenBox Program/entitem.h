/*
entitem.h
*/

#include <string>
#include <cfloat>
using namespace std;

class entitem
{
	private:
		int    itemID;
		float  itemCost;
		string itemStatus;
		string itemPeriod;
	
	public:
		entitem();
		entitem(int id, float cost, string status, string period);
		
		void setItemID(int id);
		void setItemCost(float cost);
		void setItemStatus(string status);
		void setItemPeriod(string period);
		
		int    getItemID();
		float  getItemCost();
		string getItemStatus();
		string getItemPeriod();
};

class game: public entitem 
{
	private:
		string gameRating;
		string gameGenre;
		string gameTitle;
		string gameRelease;
		string gameStudio;
		float  gameCost;
		float  gameReplacement;
	
	public:
		game();
		game(string rating, string genre, string title, string release, string studio, float cost, float replacement);
		
		void setGameRating(string rating);
		void setGameGenre(string genre);
		void setGameTitle(string title);
		void setGameRelease(string release);
		void setGameStudio(string studio);
		void setGameCost(float cost);
		void setGameReplacement(float replacement);
		
		string getGameRating();
		string getGameGenre();
		string getGameTitle();
		string getGameRelease();
		string getGameStudio();
		float  getGameCost();
		float  getGameReplacement();
		

};
	
