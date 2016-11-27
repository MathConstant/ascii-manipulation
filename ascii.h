// ascii class 
// MathConstant 2016
// This class allows the creating of ascii objects that represent ascii pictures 
// and allows the manipulation of the picture eg. (flip an ascii picture horazontaly)

// I made this file because i wanted to flip an ascii 
// picture but couldn't find a convient way to do it elseware 

// you can use the clear and fill functions to save memory by claering the contents and only filling when needing to display 
#ifndef ASCII_H
#define ASCII_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <cstring>

using namespace std;

class ascii
{
public:
	ascii();
	ascii(string fileName);
	ascii(string strarr[], string fileName);
	
	~ascii(); 
	
	// finds and replaces all right directional charictors with their left directional counterparts and vice versa 
	void CharSwitch (const char &char1, const char &char2);
	
	// returns an ascii object with mirrored text
	ascii Flip();
	ascii Flip(string file_Name);
	
	// outputs the contents to the screen 
	void print() const;
	
	// allows the user to enter a file name
	void input_fileName();
	
	// returns the number of lines in the picture 
	int get_size() const;
	
	// saves each line of the file to part of contents[] 
	void fill(); 
	
	// clears the contents[] varables memory 
	void clear();
	
private:
	string * contents;
	int size;
	int longestline;
	string fileName;
	
	// finds the longest line 
	void LongestLine ();
	
	// finds file sise (# of lines)
	void fileSize ();
	
	// checks if the filename has an extension if not adds ".txt"
	void check_fileName();
	
	// writes contents to the file 
	void write();
};
#endif
