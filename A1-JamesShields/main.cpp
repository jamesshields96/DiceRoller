/*
James Shields
30755964
Assingment 1 Tally Ho Dice Generator
*/

// Libraries 
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

//Declaring Functions
void runMenu(int& choice);
void displayText();
void createLists();
void generateTable();
void saveTable();
void loadTable();

//Global variables
bool tableCreated;
int count1{};
int count2{};
int count3{};
int count4{};
int count5{};
int count6{};
int count7{};
int count8{};
int count9{};
int count10{};
int count11{};
int count12{};
char star = '*';
char savedTable;
int numberOfDice{};
int numberOfRolls{};
std::string tableResults;

int tallyData[13];

//Main Function
int main()
{
	int choice = 0;

	runMenu(choice);


	system("pause");

}

//Running and displaying the Menu screen
void runMenu(int& choice)
{
	do
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "            Tally Ho Dice Generator          " << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "[0] End testing the program                  " << std::endl;
		std::cout << "[1] Display 'About' Information              " << std::endl;
		std::cout << "[2] Read and store the data from files       " << std::endl;
		std::cout << "[3] Generate a Dice Tally Table              " << std::endl;
		std::cout << "[4] Save tally statistics to table           " << std::endl;
		std::cout << "[5] Load tally statistics from table         " << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "Which option would you like to choose (0-5): ";
		std::cin >> choice;



		switch (choice)
		{
		case 0:
			std::cout << "Thank you for rolling the dice!" << std::endl;
			break;

		case 1: // Display about
			displayText();
			break;

		case 2: // Read/Store Data
			createLists();
			break;

		case 3: // Generate Dice Table
			generateTable();
			break;

		case 4: // Save table
			saveTable();
			break;

		case 5: // Load table
			loadTable();
			break;

		default:
			std::cout << "                                                  " << std::endl;
			std::cout << "Invalid input, only accepts 0-5, please try again!" << std::endl;
			std::cout << "                                                  " << std::endl;
			break;
		}

	} while (choice != 0);
}

//Displaying the information about the program
void displayText() //Function required to display the about data
{

	std::string line;
	std::ifstream outFile;
	outFile.open("TallyAbout.txt"); //which file to open

	while (std::getline(outFile, line)) //outputting every line in the file
	{
		std::cout << line << std::endl;
	}
	outFile.close();

	system("pause");
}

//Storing the last table created
void createLists()
{
	
	//storing the dice rolls into a array called tallyData
	int i = 0;
	std::ifstream fileOpen("saveTallyData.txt");
	if (fileOpen.is_open())
	{
		int tallyData[13];
		for (int i = 0; i < 13; i++)
		{
			fileOpen >> tallyData[i];
		}
	}

	//printing the last table if one has been made, if not will state that no table has been created yet
	if (tableCreated == true)
	{
		std::cout << "You rolled " << numberOfDice << " dice " << numberOfRolls * 10 << " times!" << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "1. " << std::string(count1, star) << std::endl;
		std::cout << "2. " << std::string(count2, star) << std::endl;
		std::cout << "3. " << std::string(count3, star) << std::endl;
		std::cout << "4. " << std::string(count4, star) << std::endl;
		std::cout << "5. " << std::string(count5, star) << std::endl;
		std::cout << "6. " << std::string(count6, star) << std::endl;
		std::cout << "7. " << std::string(count7, star) << std::endl;
		std::cout << "8. " << std::string(count8, star) << std::endl;
		std::cout << "9. " << std::string(count9, star) << std::endl;
		std::cout << "10. " << std::string(count10, star) << std::endl;
		std::cout << "11. " << std::string(count11, star) << std::endl;
		std::cout << "12. " << std::string(count12, star) << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "                          " << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "Table stored into array!" << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	}
	

	if (tableCreated == false)
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "No table has been created yet" << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	}

}

//Generating the random dice table
void generateTable()
{
	//All variables needed 
	
	int tallyResults{};
	char clearTable{};



	if (tableCreated == true) //Clearing the previous data table if another one is already stored
	{
		
	
			count1 = 0;
			count2 = 0;
			count3 = 0;
			count4 = 0;
			count5 = 0;
			count6 = 0;
			count7 = 0;
			count8 = 0;
			count9 = 0;
			count10 = 0;
			count11 = 0;
			count12 = 0;

		
	}
	

	//Inputs for the number of dice rolled and the number of rolls
	std::cout << "Select the number of Dice (1-2) ";
	std::cin >> numberOfDice;
	std::cout << "Select the number of Rolls (1-10) ";
	std::cin >> numberOfRolls;

	//Seed to generate random rolls
	unsigned int seed = unsigned(std::time(NULL));
	srand(seed);

	//Generating the random rolls
	int i = 0;
	for (int i = 0; i < numberOfRolls * 10; i++)
	{
		if (numberOfDice == 1)
		{
			tallyResults = rand() % 6 + 1;

		}
		if (numberOfDice == 2)
		{
			tallyResults = rand() % 12 + 1;

		}
		if (numberOfDice >= 3)
		{
			std::cout << "                                         " << std::endl;
			std::cout << "Invalid amount of Dice, please try again " << std::endl;
			std::cout << "                                         " << std::endl;
			generateTable();
			break;

		}
		if (numberOfRolls > 10)
		{
			std::cout << "                                         " << std::endl;
			std::cout << "Invalid number of Rolls, Please try again" << std::endl;
			std::cout << "                                         " << std::endl;
			generateTable();
			break;
		}

		//Counting how many of each roll appears and storing them into the tallyData array
		switch (tallyResults)
		{
		case 1:
			tallyData[1] = count1++;
			break;
		case 2:
			tallyData[2] = count2++;
			break;
		case 3:
			tallyData[3] = count3++;
			break;
		case 4:
			tallyData[4] = count4++;
			break;
		case 5:
			tallyData[5] = count5++;
			break;
		case 6:
			tallyData[6] = count6++;
			break;
		case 7:
			tallyData[7] = count7++;
			break;
		case 8:
			tallyData[8] = count8++;
			break;
		case 9:
			tallyData[9] = count9++;
			break;
		case 10:
			tallyData[10] = count10++;
			break;
		case 11:
			tallyData[11] = count11++;
			break;
		case 12:
			tallyData[12] = count12++;
			break;

		}

	}
	

	//Output of how many rolls show up
	std::cout << "You rolled " << numberOfDice << " dice " << numberOfRolls*10 << " times!" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "1. " << std::string(count1, star) << std::endl;
	std::cout << "2. " << std::string(count2, star) << std::endl;
	std::cout << "3. " << std::string(count3, star) << std::endl;
	std::cout << "4. " << std::string(count4, star) << std::endl;
	std::cout << "5. " << std::string(count5, star) << std::endl;
	std::cout << "6. " << std::string(count6, star) << std::endl;
	std::cout << "7. " << std::string(count7, star) << std::endl;
	std::cout << "8. " << std::string(count8, star) << std::endl;
	std::cout << "9. " << std::string(count9, star) << std::endl;
	std::cout << "10. " << std::string(count10, star) << std::endl;
	std::cout << "11. " << std::string(count11, star) << std::endl;
	std::cout << "12. " << std::string(count12, star) << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "                          " << std::endl;


	
	tableCreated = true; //changing the tableCreated variable to true for task 3
	system("pause");
}

//Saving the random dice table onto a text file
void saveTable()
{
	//displaying the last table created
	std::cout << "You rolled " << numberOfDice << " dice " << numberOfRolls * 10 << " times!" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "1. " << std::string(count1, star) << std::endl;
	std::cout << "2. " << std::string(count2, star) << std::endl;
	std::cout << "3. " << std::string(count3, star) << std::endl;
	std::cout << "4. " << std::string(count4, star) << std::endl;
	std::cout << "5. " << std::string(count5, star) << std::endl;
	std::cout << "6. " << std::string(count6, star) << std::endl;
	std::cout << "7. " << std::string(count7, star) << std::endl;
	std::cout << "8. " << std::string(count8, star) << std::endl;
	std::cout << "9. " << std::string(count9, star) << std::endl;
	std::cout << "10. " << std::string(count10, star) << std::endl;
	std::cout << "11. " << std::string(count11, star) << std::endl;
	std::cout << "12. " << std::string(count12, star) << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "                          " << std::endl;
	std::cout << "Would you like to save the file? (y/n) ";
	std::cin >> savedTable;

	if (savedTable == 'y')
	{
		

		std::ofstream outFile;
		outFile.open("saveTallyData.txt");
		


		outFile << "Super secret safety code cause the first line vanishes when i try read the damn file gavin dont you dare read this" << std::endl;
		outFile << "1. " << std::string(count1, star) << std::endl;
		outFile << "2. " << std::string(count2, star) << std::endl;
		outFile << "3. " << std::string(count3, star) << std::endl;
		outFile << "4. " << std::string(count4, star) << std::endl;
		outFile << "5. " << std::string(count5, star) << std::endl;
		outFile << "6. " << std::string(count6, star) << std::endl;
		outFile << "7. " << std::string(count7, star) << std::endl;
		outFile << "8. " << std::string(count8, star) << std::endl;
		outFile << "9. " << std::string(count9, star) << std::endl;
		outFile << "10. " << std::string(count10, star) << std::endl;
		outFile << "11. " << std::string(count11, star) << std::endl;
		outFile << "12. " << std::string(count12, star) << std::endl;

		outFile.close();
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Table has been saved into text file" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	

}

//Loading the random dice table from a text file
void loadTable()
{
	std::ifstream inFile;
	std::string line;
	inFile.open("saveTallyData.txt");

	std::getline(inFile, line);
	
	while (std::getline(inFile, line))
	{

		std::cout << line << std::endl;
	}

	inFile.close();
}


