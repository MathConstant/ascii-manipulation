// asciiFlip.cpp
// MathConstant 2016
// This program flips an ascii picture verticaly

// I made this file because i wanted to flip an ascci 
// picture but couldent find a convient way to do it elseware 

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

// function declaration 
string CharFlip (string subject, char char1, char char2);

int main ()
{
	
ifstream readFile;
ofstream writeFile;

readFile.open ("enterprise.txt");

int lineCount = 0;
string lineCounter, line;

// finds the # of lines in the file & allows contents to be an undefined size untill the # of lines in the file are found
while (getline(readFile, lineCounter))
{	
	lineCount++;
}

readFile.close();
readFile.open ("enterprise.txt");

string contents [lineCount];

// saves each line of the file to part of contents[] 
for (int i = 0 ;getline(readFile, line); i ++)
{
	contents [i] = line;	
}

readFile.close();
writeFile.open ("flipPicture.txt");

int longestline = contents[0].length();


for (int i=1; i < lineCount ; i++) // finds the longest line in the file 
{
	//cout << contents[i-1]  << "    " << longestline << endl;	// prints your origanl file plus what longest line is at the time
	if (contents[i].length() > longestline) 
	{
		longestline = contents[i].length(); 
	} 	
}
//cout << contents[lineCount]  << "    " << longestline << endl;


// declares strings to be used for saving the fliped lines of text
string flipContent [lineCount];
string spaces [lineCount];

// reverses each line of text and saves it to a new array
for (int i=0; i <lineCount; i++) 
{

	// finds how many spaces are needed to make the current contents[] line the same length as the longest line 
	// then saves that number of spaces to the relivent spaces[] 
	int diff= abs(longestline - contents[i].length()); 
	spaces[i].append (diff,' ');
	
	//cout << spaces[i] << "1\n"; // for debuging shows how long each spaces[] is
	
	flipContent [i] = string ( contents [i].rbegin(), contents [i].rend()); // flips the line 
	
	// finds and replaces all right directional charictors with their left directional counterparts and vice versa 
	flipContent [i] = CharFlip (flipContent [i], '/', '\\');
	flipContent [i] = CharFlip (flipContent [i], '(', ')');
	flipContent [i] = CharFlip (flipContent [i], '<', '>');
	flipContent [i] = CharFlip (flipContent [i], '[', ']');
	flipContent [i] = CharFlip (flipContent [i], '{', '}');

	writeFile << spaces[i] << flipContent [i] << endl; // writes the fliped line to the new file 
}

}

// replaces char1 with char2 and vice versa based on the origanly entered subject
string CharFlip (string subject, char char1, char char2)
{
 	size_t pos = 0;
    string referanceLine = subject;
    
    while (subject.find(char1, pos) != string::npos) 
	{
		pos = subject.find(char1, pos);
         subject = subject.replace(pos, 1, 1 , char2);
        pos++;
    }
    
	pos = 0;
	 
	while (referanceLine.find(char2, pos) != string::npos) 
	{
		pos = referanceLine.find(char2, pos);
         subject = subject.replace(pos, 1, 1 , char1);
         pos++;
    }
    return subject;	
}

