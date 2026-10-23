//Name: Kenny Garcia
// CS-210 Project Three Corner Grocer
// Date: October 16, 2026
//This program reads grocery items from an input file
// calculates theri frequencies, and displays the results

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// CornerGrocer class stores grocery items and their frequencies
class CornerGrocer
{
private:
	// Map stores each grocery item and the number of times it appears.
	map<string, int> groceryFrequency;

public:
	// Loads grocery items from the input file.
	void loadData(const string& fileName);

	// Displays the frequency of  one specific grocery item.
	void individualFrequency();

	// Displays the frequency of every grocery item.
	void overallFrequency();

	// Displays a text-based histogram of all grocery items.
	void displayHistogram();

	// Creates the required frequency.dat backup file.
	void createBackupFile(const string& fileName);
};

// Loads grocery items from the input file and counts their frequencies.
void CornerGrocer::loadData(const string& fileName)
{
	//Open the input file.
	ifstream inputFile(fileName);

	//Check that the file opened successfully.
	if (!inputFile)
	{
		cout << "Error: Could not open the input file." << endl;
		return;
	}

	string groceryItem;

	//Read each grocery item from the file.
	while (getline(inputFile, groceryItem))
	{
		// Add the item to the map or inrease its frequency.
		groceryFrequency[groceryItem]++;
	}

	//Close the input file.
	inputFile.close();
}

// Displays the frequency of one specific grocery item.
void CornerGrocer::individualFrequency()
{
	string groceryItem;

	cout << "Enter the grocery item: ";
	cin >> groceryItem;

	if (groceryFrequency.find(groceryItem) != groceryFrequency.end())
	{
		cout << groceryItem << ": "
			<< groceryFrequency[groceryItem] << endl;
	}
	else
	{
		cout << groceryItem << ": 0" << endl;
	}
} // end of individual frequency

// Displays the frequency of every grocery item.
void CornerGrocer::overallFrequency()
{
	for (const auto& item : groceryFrequency)
	{
		cout << item.first << ": " << item.second << endl;
	}
}

int main()
{
	// Create an instance of the CornerGrocer class.
	CornerGrocer grocery;

	// Load the grocery data when the program starts.
	grocery.loadData("CS210_Project_Three_Input_File.txt");

	int choice;

	// Continue displaying the menu until the user chooses Exit.
	do
	{
		cout << "\nCorner Grocer Menu" << endl;
		cout << "1. Individual Item Frequency" << endl;
		cout << "2. Overall Item Frequency" << endl;
		cout << "3. Histogram" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		// Process the menu selection.
		switch (choice)
		{
			case 1:
				//Find and display the frequency of one item.
				grocery.individualFrequency();
				break;

			case 2:
				// Display all grocery items and their frequencies.
				grocery.overallFrequency();
				break;

			case 3:
				// Display the grocery frequencies as a histogram.
				grocery.displayHistogram();
				break;

			case 4:
				// Exit the program.
				cout << "Exiting the program." << endl;
		}
	} while (choice != 4);

	return 0;
}

void CornerGrocer::displayHistogram()
{
	for (const auto& item : groceryFrequency)
	{
		cout << item.first << " ";
		for (int i = 0; i < item.second; ++i)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void CornerGrocer::createBackupFile(const string& filename)
{
	ofstream outputFile(filename);

	for (const auto& item : groceryFrequency)
	{
		outputFile << item.first << " " << item.second << endl;
	}

	outputFile.close();
}