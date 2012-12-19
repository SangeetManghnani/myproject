#include "filesearchutility.h"
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

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
	DIR    *d;
	struct dirent *dir;
	d = opendir(indexedDir.c_str());
	cout << "Directory : " << indexedDir << endl;
	if (d)
	{	
		while ((dir = readdir(d)) != NULL)
		{
			string filename(dir->d_name);

			if(filename != "." && filename != "..")
			{
				cout << "Indexing file " << filename << endl;
				AddFileToIndex(filename);
			}
		}
		closedir(d);
	}

	return false;
}

vector<string> FileSearchUtility::SearchIndex(string word)
{
	vector<string> searchResults;
	fileIndex.SearchFiles(word, searchResults);
	return searchResults;
}

vector<string> FileSearchUtility::SearchDisk(string word)
{
	vector<string> searchResults;
	DIR    *d;
	struct dirent *dir;
	d = opendir(indexedDir.c_str());
	cout << "Searching files in directory : " << indexedDir << endl;
	if (d)
	{	
		while ((dir = readdir(d)) != NULL)
		{
			string filename(dir->d_name);

			if(filename != "." && filename != "..")
			{
				if(true == FileContainsWord(filename, word))
					searchResults.push_back(filename);
			}
		}
		closedir(d);
	}
	return searchResults;
}

int FileSearchUtility::IndexSize()
{
	return fileIndex.Size();
}

bool FileSearchUtility::AddFileToIndex(string filename)
{
	ifstream file;
	string filepath = indexedDir + "/" + filename;
	file.open(filepath.c_str());
	string word;
	if(!file)
		return false; // empty file
	
	while(!file.eof())
	{
		if(file>>word)
		{
			fileIndex.AddEntry(filename,word);
		}
	}
	return false;
}

bool FileSearchUtility::FileContainsWord(string filename, string searchWord)
{
	ifstream file;
	string filepath = indexedDir + "/" + filename;
	file.open(filepath.c_str());
	string word;
	if(!file)
		return false; // empty file
	
	while(!file.eof())
	{
		if(file>>word)
		{
			if(word == searchWord)
			{
				file.close();
				return true;
			}
			fileIndex.AddEntry(filename,word);
		}
	}
	file.close();
	return false;
}

