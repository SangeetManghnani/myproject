#include "filesearchutility.h"
#include <dirent.h>
FileSearchUtility::FileSearchUtility()
{
}

FileSearchUtility::~FileSearchUtility()
{
}

void FileSearchUtility::SetDirToIndex(string directoryPath)
{
	indexedDir = directoryPath;
}

bool FileSearchUtility::CreateIndex()
{
	string filename;
	DIR    *d;
  struct dirent *dir;
  d = opendir(indexedDir);
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      AddFileToIndex(filename);
    }

    closedir(d);
  }

	/* TODO: Go through each file in the directory and add it to index.
	 * Use the method AddFileToIndex(string filename) to add the  file 
	 * to index.
	 */
	return false;
}

vector<string> FileSearchUtility::Search(string word)
{
	vector<string> searchResults;
	fileIndex.SearchFiles(word, searchResults);
	return searchResults;
}

bool FileSearchUtility::AddFileToIndex(string filename)
{
	ifstream file;
	file.open(filename);
	string word;
	if(!file)
	return; // empty file
	
	 	while(file>>word)
	 	fileIndex.Addentry(filename,word);
	 }
	/* TODO: Read each word form file and add it to index.
	 * Use  fileIndex.AddEntry(filename, word) to add an
	 * entry to the index.
	 */
	return false;
}

