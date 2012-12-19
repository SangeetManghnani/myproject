#include "filesearchutility.h"

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
	/* TODO: Go through each file in the directory and add it to index.
	 * Use the method AddIndexToFile(string filename) to add the file to
	 * index.
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
	/* TODO: Read each word form file and add it to index.
	 * Use  fileIndex.AddEntry(filename, word) to add an
	 * entry to the index.
	 */
	return false;
}

