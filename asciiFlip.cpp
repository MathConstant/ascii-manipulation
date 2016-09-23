// asciiFlip.cpp
// MathConstant 2016
// This program flips an ascii picture verticaly
 
// only works for pictures 100 lines or less

// I made this file because i wanted to flip an ascci 
// picture but couldent find a convient way to do it elseware 

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main ()
{
	
ifstream readFile;
ofstream writeFile;

readFile.open ("bird.txt");

int lineCount = 0;
string line;
string contents [100];

// saves each line of the file to part of contents[] and finds the # of lines in the file
while (getline(readFile, line))
{
	contents [lineCount] = line;	
	lineCount++;
}

readFile.close();
writeFile.open ("flipbird.txt");

int longestline = contents[0].length();

//	
for (int i=1; i < lineCount ; i++) // finds the longest line in the file 
{
	//cout << contents[i-1] < << "    " << longestline< endl;	// prints your origanl file plus what longest line is at the time
	if (contents[i].length() > longestline) 
	{
		longestline = contents[i].length(); 
	} 	
}
//cout << contents[lineCount] < << "    " << longestline< endl;

// defines functions
string ReplaceString1 (string subject, const string& search, const string& change);
string ReplaceString2 (string subject, string referanceLine, const string& search, const string& change);

// declares strings to be used for saving the fliped lines of text
string flipContent [lineCount];
string flipContentFinal [lineCount];
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
	
	// finds and replaces all slashes with backslashes and vice versa (or at least it should)
	flipContentFinal [i] = ReplaceString1 (flipContent [i], "/", "\\");
	flipContentFinal [i] = ReplaceString2 (flipContentFinal [i], flipContent [i], "\\", "/");
	
	writeFile << spaces[i] << flipContent [i] << endl; // writes the fliped line to the new file 
}

}
// these functions currently seem to do nothing (will fix later)
string ReplaceString1 (string subject, const string& search, const string& change) 
{
    int pos = 0;
    
    while (subject.find(search, pos) != string::npos) 
	{
		pos = subject.find(search, pos);
         subject = subject.replace(pos, search.length(), change);
        // pos += replace.length();
        pos++;
    }
    return subject;
}
string ReplaceString2 (string subject, string referanceLine, const string& search, const string& change) 
{
    int pos = 0;
    
    while (referanceLine.find(search, pos) != string::npos) 
	{
		pos = referanceLine.find(search, pos);
         subject = subject.replace(pos, search.length(), change);
         //pos += replace.length();
         pos++;
    }
    return subject;
}

