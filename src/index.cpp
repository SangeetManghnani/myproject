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
          	vector<string>*newEntry = new vector<string>(); //creates a new string vectory
                wordFileMap[word] = newEntry;
                newEntry->push_back(filename);
          }         
    else
       {
       	vector<string>* entry = wordFileMap[word];
       	entry->push_back(filename);
       }

/* TODO: Check if wordFileMap already contains the word. If it does
 	 * then add the file name to the string vectory against the word. If it
 	 * does not contain the word, then create a new string vectory and add
 	 * it to the map with the word as the key. */
	return false;
}

bool Index::SearchFiles(string word, vector<string>& files)
{
	/* TODO: Search the wordFileMap for the word and return the vector
 	 * of filenames found as a the result. */
	return true;
}
