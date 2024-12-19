//Antonio Colantuono
//12142024

#include <iostream>
#include <fstream> //library used since we are reading a file
#include <string> 
//deleted a bunch of include statements that I used to help show me the file path because the original Shopping.txt file was having issues being imported due to my directory pathing being off in VisualStudios which I did not know was a thing until this project
using namespace std;

class grocceryItem {
public:
	//constructor to initialize variables
	grocceryItem() : grocceryCount(0) {}

	void bringItemsFromFile() {
		std::ifstream inputFile("Shopping.txt"); //this opens the input file for reading. Renamed file because I am again having issues opening a file correctly even though my code is right. Turns out i forget to add the file to my folder for the project and by just dragging and dropping the file into my project visual studio screen, it does not properly add the file to the repo
		string Groccery; //intializes Groccery as the first part of what is read

		if (!inputFile.is_open()) { //this is here to tell me if there is any error with opening the file
			std::cout << "Could not Open: Shopping.txt" << endl; //this tells me there is an error

			return ; //indicates an error
		}

		string line; //initates the lines of text
		std::ofstream MyFile("Frequency.txt"); // this opens the input file to prepare it to be used to write on
		if (!MyFile.is_open()) {//this checks to see if the file is open
			std::cout << "could not open the file for writing" << endl; //this tells me if the file was opened or not
			return ;//when it returns this code this tells me there is something wrong with opening the file
		}
		while (std::getline(inputFile, line)) { //this takes the lines of the original file

			bool found = false;

			for (int i = 0; i < grocceryCount; i++) { //adds the amount of time the item is mentioned on the file
				if (grocceryItems[i] == line) {//this takes the groccery item input and runs it through to find the item iterations
					counts[i]++; //increments the count of the line above based on how many times it is mentioned in the file
					found = true;
					break;
				}
			}

			if (!found) { //if the item is a new item this one adds it to the existing list on the file and outputs the amount of times that it shows up 
				grocceryItems[grocceryCount] = line;
				counts[grocceryCount] = 1;//this adds the number of times that an item appears
				grocceryCount++;//this increments the amount of times an item appears
				continue;
			}
		}
		inputFile.close(); //closes the first file

		for (int i = 0; i < grocceryCount; i++) { //this loop outputs the information from above onto the new file and stops outputting one it reaches the end of the file
			MyFile << grocceryItems[i] << " " << counts[i] << endl;
		}
		MyFile.close(); //closes the second file

		std::cout << "Finished writing to Frequency.txt" << endl; //added this in because I was having issues finding the written file and importing the Farhenheit file so this would tell me that everything went well
	}
	
	void printListWithFreq() {
		for (int i = 0; i < grocceryCount; i++) { //this loop outputs the information from above onto the new file and stops outputting one it reaches the end of the file
			std::cout << grocceryItems[i] << " " << counts[i] << endl;
		}
	}

	void printHistogramItems() {
		for (int i = 0; i < grocceryCount; i++) { //this loop counts the number of times an item is mentioned in the file
			std::cout << grocceryItems[i];
			for (int j = 0; j < counts[i]; j++) { //this loop outputs the information from above onto the new file and stops outputting one it reaches the end of the file and prints it in ****
				std::cout  << "*";//prints my Histogram

			}
			std::cout << std::endl; //this is needed so this way the end of the * on each line is then entered so not all my groccery items are on one line for my histogram

		}
	}

	void displayMenu() {
		int choice; //this initalizes giving our users a choice
		string searchItems; //this intializes my search item command which we use in case 1

		do {//this is my main menu for the application that is extremely user friendly
			std::cout << "Main Menu" << endl;//title
			std::cout << "Option 1: Look for an Item" << endl;
			std::cout << "Option 2: Print the full item list along with iterations " << endl;
			std::cout << "Option 3: Histogram Version " << endl;
			std::cout << "Option 4: Exit Program " << endl;
			std::cout << "Enter your choice: " << endl;
			cin >> choice;

			switch (choice) {//these are my menu options and what happens when you select each option 
				case 1:
					cout << "Enter an Item: " << endl;
					cin >> searchItems; //turns the user input into the searchItems command and then runs that through the voiditemSearch function as seen below
					itemSearch(searchItems);
					break;
				case 2:
					printListWithFreq();
					break;
				case 3:
					printHistogramItems();
					break;
				case 4:
					cout << "Exiting have a good day. . . " << endl;
					break;
				default:
					cout << "Invalid Response Please Try Again." << endl;//this is used as input validation so the user cannot break the application of the main menu
				}
			} while (choice != 4);
		}

	void itemSearch(const string& item) {//this is my item search command for option 2
		bool found = false;
		for (int i = 0; i < grocceryCount; i++) { //adds the amount of time the item is mentioned on the file
			if (grocceryItems[i] == item) {
				std::cout << grocceryItems[i] << " " << counts[i] << endl;
				found = true; //this says if the inputted item is found then the system outputs that item name and the amount of times we seen it in the text file
				break;
			}

		}
		if (!found) {
			std::cout << "item not found" << endl; //hopefully this works in making sure input is able to be verified
			}
		}
private:
	string grocceryItems[200];
	int counts[100] = { 0 };//these are my private class definitions
	int grocceryCount;
};

int main() {
	grocceryItem groccery;//this initiates the class grocceryItem

	groccery.bringItemsFromFile();//this is my first direction in the main menu that exports the frequency file

	groccery.displayMenu();//this begins my loop for the main menu

	return 0;
	}

