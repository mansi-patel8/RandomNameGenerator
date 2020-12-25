/*
* Name: Mansi Patel
* Problem:
			- Write a program to generate n random names for a character of some game or a novel. To do this, you need to access three files: firstnames.txt, lastnames.txt, prefixes.txt, postfixes.txt.
			- These files are provided with the project and have 20 lines each, for simplicity. 
			  Make sure to ask the user for a number of names to generate. Since gender is a concept highly argued today, your random names may be controversial and ridiculous, which just adds some fun to it. Your typical random name should look like this:
			     Prefix (space) Firstname (space) Lastname , Postfix
			- So, each time you want to generate a name, you get a random number line from 1 to 20 and get a name part from that line. Do this for all name parts, then concatenate them to get a full name and display it to the user. There should be a 50% chance to NOT generate a prefix, postfix or both. Make sure to display all generated names to the user in an orderly fashion.

* Peudo Code:
			- Create arrays for each file and then store the data from the file to the arrays
				- prefixArray, firstnameArray, lastnameArray, postfixArray - the array size will be 20 because each file has 20 lines in it
			- Ask use for the number of names to generate and store the user input in varible (n)
			- Create a for loop that will n times
				- Create a bool variable and store the coin_flip() result value in it for 50% chance for prefix
					- If the result true
						- Generate random number through rand(0,20) for prefix and get that lineno from the prefixArray then append to the randomName string with the prefix value
				- Generate the random number through rand(0,20) for the firstname and get that lineno form the firstnameArray then append to the randomName string with the firstname value
				- Generate the random number through rand(0,20) for the lastname and get that lineno form the lastnameArray then append to the randomName string with the lastname value
				- Create a bool variable and store the coin_flip() result value in it for 50% chance for postfix
					- If the result true
						- Generate random number through rand(0,20) for postfix and get that lineno from the postfixArray then append to the randomName string with the postfix value
				- Show the randomName value as output to the console and store it in the output.txt file
*/

#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>
#include "RandomNameGenerator.h"

using namespace std;

const int FILESIZE = 20;            //FileSize
string prefixArray[FILESIZE];		//prefixArray to store the data from prefixes.txt file  
string firstnameArray[FILESIZE];    //firstnameArray to store the data from firstnames.txt file  
string lastnameArray[FILESIZE];     //lastnameArray to store the data from lastnames.txt file  
string postfixArray[FILESIZE];      //postfixArray to store the data from postfixes.txt file  

int main() {

	cout << "This program generates random names." << endl;
	//user input for # of random names
	int n;
	cout << "Please enter number of names to generate (n): " << endl;
	cin >> n;

	cout << "Reading name files..." << endl;

	//storing data from prefixes.txt file to prefixArray
	ifstream prefixesFile("prefixes.txt");						//connect to "prefixes.txt"
	if (prefixesFile.is_open())									//opening the input file 
	{
		for (int i = 0; i < FILESIZE; i++)
		{
			getline(prefixesFile, prefixArray[i]);
		}
		prefixesFile.close();									//close and release file
	}
	else cout << "Unable to open the prefixes.txt file" << endl;

	//storing data from firstnames.txt file to firstnameArray
	ifstream firstnamesFile("firstnames.txt");					//connect to "firstnames.txt"
	if (firstnamesFile.is_open())								//opening the input file 
	{
		for (int i = 0; i < FILESIZE; i++)
		{
			getline(firstnamesFile, firstnameArray[i]);
		}
		firstnamesFile.close();									 // close and release file
	}
	else cout << "Unable to open the firstnames.txt file" << endl;

	//storing data from lastnames.txt file to lastnameArray
	ifstream lastnamesFile("lastnames.txt");					//connect to "lastnames.txt"
	if (lastnamesFile.is_open())								//opening the input file 
	{
		for (int i = 0; i < FILESIZE; i++)
		{
			getline(lastnamesFile, lastnameArray[i]);
		}
		lastnamesFile.close();									//close and release file
	}
	else cout << "Unable to open the lastnames.txt file" << endl;

	//storing data from postfixes.txt file to postfixArray
	ifstream postfixesFile("postfixes.txt");					 //connect to "postfixes.txt"
	if (postfixesFile.is_open())								//opening the input file 
	{
		for (int i = 0; i < FILESIZE; i++)
		{
			getline(postfixesFile, postfixArray[i]);
		}
		postfixesFile.close();									//close and release file
	}
	else cout << "Unable to open the postfixs.txt file" << endl;

	//create/open the output.txt file 
	ofstream outputFile("output.txt");							//connect to "output.txt"
	if (!outputFile.fail())
	{
		cout << "The generated names are:" << endl;

		for (int count = 0; count < n; count++) {

			int randomNumberForPrefix = 0;				//variable to store the randomnumber for prefix
			int randomNumberForFirstName = 0;			//variable to store the randomnumber for firstname
			int randomNumberForLastName = 0;			//variable to store the randomnumber for lastname
			int randomNumberForPostfix = 0;				//variable to store the randomnumber for postfix
			string randomNameString = "";				//randomName string
			bool showPrefix = false;					//flag for populating prefix
			bool showPostfix = false;					//flag for populating postfix			

			//calling coin_flip() to check if generate the prefix
			showPrefix = coin_flip();

			if (showPrefix == true) {							//if yes 
				randomNumberForPrefix = rnd_num(0, FILESIZE);	//get the randomnumber for prefix
				randomNameString += prefixArray[randomNumberForPrefix] + " ";    //get the prefix from prefixArray with element = randomnumber 
			}

			//get the randomnumber for firstname
			randomNumberForFirstName = rnd_num(0, FILESIZE);

			//get the firstname from firstnameArray with element = randomnumber 
			randomNameString += firstnameArray[randomNumberForFirstName] + " ";

			//get the randomnumber for lastname
			randomNumberForLastName = rnd_num(0, FILESIZE);

			//get the lastname from lastnameArray respectively with element = randomnumber 
			randomNameString += lastnameArray[randomNumberForLastName];

			//calling coin_flip() to check if generate the postfix
			showPostfix = coin_flip();

			if (showPostfix == true) {							  //if yes
				randomNumberForPostfix = rnd_num(0, FILESIZE);   //get the randomnumber for postfix
				randomNameString += ", " + postfixArray[randomNumberForPostfix];   //get the postfix from postfixArray with element = randomnumber 
			}

			//console output of randomName
			cout << randomNameString << endl;

			//store the randomName in the file 
			outputFile << randomNameString << endl;
		}
		outputFile.close();												//close and release file
	}
	else cout << "ERROR: Could not open output file." << endl;

	return 0;
}
