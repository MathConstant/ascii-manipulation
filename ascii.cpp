#include "ascii.h"


ascii::ascii()
{
	input_fileName();
	check_fileName();
	fileSize ();
	fill();
	LongestLine ();
}

ascii::ascii(string fileName) : fileName(fileName)
{
	check_fileName();
	fileSize();
	fill();
	LongestLine ();
}

ascii::ascii(string strarr[], string fileName) : contents(strarr), fileName(fileName)
{
	check_fileName();
	write();
	fileSize ();
	LongestLine ();
}

ascii::~ascii()
{
	clear();
}

void ascii::CharSwitch (const char &char1, const char &char2)
{	
	for (int i = 0 ; i < size; i++) 
	{
		size_t pos = 0;
    	string referanceLine = contents[i];
    
    	while (contents[i].find(char1, pos) != string::npos) 
		{
			pos = contents[i].find(char1, pos);
    	    contents[i] = contents[i].replace(pos, 1, 1 , char2);
    	    pos++;
    	}
    
		pos = 0;
	 
		while (referanceLine.find(char2, pos) != string::npos) 
		{
			pos = referanceLine.find(char2, pos);
        	contents[i] = contents[i].replace(pos, 1, 1 , char1);
    	    pos++;
 	   }
	}
	write();
    return;	
}

ascii ascii::Flip()
{
	ascii flipPic (fileName);
	flipPic.fileName = "flip" + fileName;
	
	string spaces;
	int diff;
	
	for (int i = 0 ; i <size; i++) 
	{
		// finds how many spaces are needed to make the current contents[] line the same length as the longest line 
		diff = abs(longestline - contents[i].length()); 
		spaces = "";
		
		spaces.append (diff,' ');
		
		flipPic.contents [i] = spaces + string ( contents [i].rbegin(), contents [i].rend()); // flips the line 
	}
	
	flipPic.CharSwitch ('/', '\\');
	flipPic.CharSwitch ('(', ')');
	flipPic.CharSwitch ('<', '>');
	flipPic.CharSwitch ('[', ']');
	flipPic.CharSwitch ('{', '}');
	
	return flipPic;
}

ascii ascii::Flip(string file_Name)
{
	ascii flipPic (fileName);
	flipPic.fileName = file_Name;
	flipPic.check_fileName();
	
	string spaces;
	int diff;
	
	for (int i = 0 ; i <size; i++) 
	{
		diff = abs(longestline - contents[i].length()); 
		spaces = "";
		
		spaces.append (diff,' ');
		
		flipPic.contents [i] = spaces + string ( contents [i].rbegin(), contents [i].rend()); // flips the line 
	}
	
	flipPic.CharSwitch ('/', '\\');
	flipPic.CharSwitch ('(', ')');
	flipPic.CharSwitch ('<', '>');
	flipPic.CharSwitch ('[', ']');
	flipPic.CharSwitch ('{', '}');
	
	return flipPic;
}

void ascii::print() const
{
	for (int i = 0 ; i <size; i++) 
	{
		cout << contents [i] << endl;
	}
	return;
}

void ascii::input_fileName()
{
	cout << "What is the name of the file? ";
	cin >> fileName;
	cout << endl;
	return;
}

int ascii::get_size() const
{
	return size;
}

void ascii::LongestLine ()
{
	longestline = contents[0].length();
	
	for (int i = 0; i < size ; i++) 
	{
		if (contents[i].length() > longestline) 
		{
			longestline = contents[i].length(); 
		} 	
	}	
	return;
}

void ascii::fileSize ()
{
	ifstream readFile;
	readFile.open (&fileName[0]);

	size = 0;
	string line;

	while (getline(readFile, line))
	{	
		size++;
	}
	readFile.close();
	return;
}

void ascii::fill()
{
	ifstream readFile;
	readFile.open (&fileName[0]);
	
	string line;
	contents = new string [size];
	
	for (int i = 0 ;getline(readFile, line); i ++)
	{
		contents [i] = line;
	}
	readFile.close();
	return;
}

void ascii::clear()
{
	delete [] contents; 
	return;
}

void ascii::write()
{
	ofstream writeFile;
	writeFile.open(&fileName[0]);
	
	for (int i = 0 ; i <size; i++) 
	{
		writeFile << contents [i] << endl;
	}
	writeFile.close();
	return;
}

void ascii::check_fileName()
{
	
	size_t pos = 0;
	if (fileName.find('.', pos) == string::npos)
	{
		fileName += ".txt";
	}
	return;
}
