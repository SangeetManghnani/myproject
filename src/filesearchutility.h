/**
 * FileSearchUtility.h
 *
 * @Description: File search utility provides functions to index files
 * in a directory and search the contents of those files for a term.
 *
 */

#ifndef __FILE_SEARCH_UTILITY_H__
#define __FILE_SEARCH_UTILITY_H__

#include <string>
#include <vector>
#include "index.h"

using namespace std;


class FileSearchUtility
{

public:

	/**
 	 * Constructor
 	 */
	FileSearchUtility();

	/**
	 * Destructor
	 */
	~FileSearchUtility();

	/**
	 * Sets the directory from which files are to indexed.
	 */
	void SetDirToIndex(string directoryPath);

	/**
	 * Creates an index of files in the specified directory.
	 */
	bool CreateIndex();

	/**
	 * Searches the files in the index for a word.
	 */
	vector<string> Search(string word);

private:

	/**
	 * Adds the file to index
	 */ 
	bool AddFileToIndex(string filename);

	Index             fileIndex;
	string            indexedDir;
};

#endif

