/**
 * Index.h
 *
 * @Description: Index represents and in memory data structure which holds a
 * list of words against the files that contain that word.
 *
 * Example:
 *
 * 		Paris  -->  city_file.txt, address_file.txt
 * 		John   -->  address_file.txt, person_file.txt
 * 		Delhi  -->  city_file.txt
 *
 */

#ifndef __INDEX_H__
#define __INDEX_H__

#include <string>
#include <vector>
#include <map>

using namespace std;


class Index
{

public:

	/**
 	 * Contructor
 	 */
	Index();

	/**
 	 * Destructor
 	 */ 
	~Index();

	/**
	 * Adds an entry to the index.
	 * @param [input] filename Name of the file to be added to index against the given word.
	 * @param [input] word The word against which the filename is to be added.
	 * @return bool true if the operation succeeds, false otherwise.
	 */
	bool AddEntry(string filename, string word);

	/** Searches the index for files with the given word.
 	 *  @param [input] word The word for which the index is to be searched.
 	 *  @param [output] files that contain the given word found as a result of the search operation.
 	 *  @return bool true if the operation succeeds, false otherwise.
 	 */
	bool SearchFiles(string word, vector<string>& files);

protected:

	map<string, vector<string>* > wordFileMap;               // Map to hold the index.
	
};

#endif
