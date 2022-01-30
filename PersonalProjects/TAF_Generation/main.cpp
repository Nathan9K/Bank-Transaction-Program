#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void displayREADME()
{

}

int main()
{
	bool		option = 0;		// conditions for while loop
	int 		menuInput;		// user input for menu options

	// overview
	cout << endl << "Welcome to TAF Generation"								<< endl;
	cout << "README contains info on this student project"			<< endl << endl;
	cout << "Not meant for professional use. Purely experimental"	<< endl << endl;

	// loop menu for user to choose from options
	while (option == 0)
	{
		// menu options
		cout << "1. Enter Observational Data"				<< endl;
		cout << "2. Enter Forecast Data for TAF Generation" << endl;
		cout << "3. Display Observational Data"				<< endl;
		cout << "4. Display Forecast Data"					<< endl;
		cout << "5. Display README"							<< endl;
		cout << "6. Exit Program"					<< endl << endl;
		cout << "Enter your choice from above: ";  cin >> menuInput;

		// checks conditions of the input. If its anything other than an int, exit program
		if (cin >> menuInput)
		{
			switch (menuInput)
			{
			case 1:
				// call observationalInput
				option = 0;
				break;
			case 2:
				// call forecastInput
				option = 0;
				break;
			case 3:
				// call displayObervation
				option = 0;
				break;
			case 4:
				// call displayForecast
				option = 0;
				break;
			case 5:
				// call displayREADME
				option = 0;
				break;
			case 6:
				cout << "Exiting ..." << endl;
				option = 1;
				break;
			default:
				cout << "Not a valid number. Enter again" << endl << endl;
				option = 0;
				break;
			}
		}
		else
		{
			cout << "Bad input, exiting ..." << endl << endl;
			exit(1);
		}
	}


	return 0;
}