#include <iostream>
#include "index.h"

using namespace std;

int main()
{
	/* Create Index */
	Index inMemoryIndex;

	cout << "Creating index..." << endl;
	inMemoryIndex.AddEntry("city_file.txt", "Paris");
	inMemoryIndex.AddEntry("city_file.txt", "Delhi");
	inMemoryIndex.AddEntry("city_file.txt", "Mumbai");

	inMemoryIndex.AddEntry("address_file.txt", "Paris");
	inMemoryIndex.AddEntry("address_file.txt", "Eiffel");
	inMemoryIndex.AddEntry("address_file.txt", "John");

	inMemoryIndex.AddEntry("person_file.txt", "Mike");
	inMemoryIndex.AddEntry("person_file.txt", "John");
	inMemoryIndex.AddEntry("person_file.txt", "Ballu");

	/* Search the index for files using a word */

	vector<string> searchResults;
	string searchString("Paris");
	cout << "Searching index for the word 'Paris'..." << endl;

	if(false ==	inMemoryIndex.SearchFiles(searchString, searchResults))
	{
		cout << "No files found." << endl;
	}
	else
	{
		for(int i=0; i < searchResults.size(); i++)
			cout << searchResults[i] << endl;
	}

	return 0;	
}
