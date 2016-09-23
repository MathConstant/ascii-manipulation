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

while (getline(readFile, line))
{
	contents [lineCount] = line;	
	lineCount++;
}

readFile.close();
writeFile.open ("flipbird.txt");

int longestline = contents[0].length();

//cout << contents[0] <<" " << longestline << endl;	
for (int i=1; i < lineCount ; i++) // finds the longest line in the file 
{
	//cout << contents[i] < << "    " << longestline< endl;	// prints your origanl file plus what longest line is at the time
	if (contents[i].length() > longestline) 
	{
		longestline = contents[i].length(); 
	} 
			
}

string flipContent [(sizeof(contents)/sizeof(*contents))];
string flipContentFinal [(sizeof(contents)/sizeof(*contents))];

string spaces [lineCount];
	
string ReplaceString1 (string subject, const string& search, const string& change);
string ReplaceString2 (string subject, string referanceLine, const string& search, const string& change);

// reverses each line of text and saves it to a new array
for (int i=0; i <lineCount; i++) 
{

	int diff= abs(longestline - contents[i].length()); 
	
	spaces[i].append (diff,' ');
	
	//cout << spaces[i] << "1\n"; // for debuging shows how long each spaces[] is
	
	flipContent [i] = string ( contents [i].rbegin(), contents [i].rend()); 
	
	
	flipContentFinal [i] = ReplaceString1 (flipContent [i], "/", "\\");
	flipContentFinal [i] = ReplaceString2 (flipContentFinal [i], flipContent [i], "\\", "/");
	
	writeFile << spaces[i] << flipContent [i] << endl;
}

}
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

