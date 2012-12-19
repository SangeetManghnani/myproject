#include "index.h"

Index::Index()
{
}

Index::~Index()
{
}

bool Index::AddEntry(string filename, string word)
{  
	if(wordFileMap.find(word) == wordFileMap.end())
	{
    	vector<string>*newEntry = new vector<string>(); //creates a new string vector
		wordFileMap[word] = newEntry;
		newEntry->push_back(filename);
	}         
    else
	{
		vector<string>* entry = wordFileMap[word];
		entry->push_back(filename);
	} 
	return true;
}

bool Index::SearchFiles(string word, vector<string>& files)
{
	/* Search the wordFileMap for the word and return the vector
 	 * of filenames found as a the result. */
	if(wordFileMap.find(word) == wordFileMap.end())
	{
		// No file found
		return false;
	}
	else
	{
		vector<string>* fileList = wordFileMap[word];
		// Go through the list and add each item to files
		for(int i = 0; i < fileList->size(); i++)
			files.push_back(fileList->at(i));
	}
	return true;
}

int Index::Size()
{
	return wordFileMap.size();
}
