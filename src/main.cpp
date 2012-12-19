#include <iostream>
#include <cstdlib>
#include "filesearchutility.h"
#include "timer.h"

using namespace std;

int main()
{
	FileSearchUtility fsUtil;
	string dir, searchTerm;
	vector<string> searchResults;
	Timer timer;
	int choice;

	while(1)
	{
		cout << endl;
		cout << "File Search Utility" << endl;
		cout << "===================" << endl;
		cout << "1. Index files in a directory" << endl;
		cout << "2. Search index" << endl;
		cout << "3. Search file on disk" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice)
		{
		case 1:
			{
				cout << "Enter directory to index: " << endl;
				cin >> dir;
				fsUtil.SetDirToIndex(dir);
				timer.start();
				fsUtil.CreateIndex();
				timer.stop();
				cout << endl << endl;
				cout << "================================" << endl;
				cout << fsUtil.IndexSize() << " terms indexed." << endl;
				cout << "Time taken to index files: " << timer.duration() << "ms" << endl;
				cout << "================================" << endl;
	
			}
			break;
		case 2:
			{
				cout << "Enter word to search(without spaces): " << endl;
				cin >> searchTerm;
				cout << "Searching index..." << endl;
				timer.start();
				searchResults = fsUtil.SearchIndex(searchTerm);
				timer.stop();
				if(searchResults.size() == 0)
					cout << "No files found." << endl;
				else
					cout << "Search Results: " << endl;
				for(int i=0; i < searchResults.size(); i++)
					cout << searchResults[i] << endl;
				cout << endl << endl;
				cout << "================================" << endl;
				cout << "Time taken to search: " << timer.duration() << "ms" << endl;
				cout << "================================" << endl;
				
			}
			break;
		case 3:
			{
				cout << "Enter word to search(without spaces): " << endl;
				cin >> searchTerm;
				timer.start();
				searchResults = fsUtil.SearchDisk(searchTerm);
				timer.stop();
				if(searchResults.size() == 0)
					cout << "No files found." << endl;
				else
					cout << "Search Results: " << endl;
				for(int i=0; i < searchResults.size(); i++)
					cout << searchResults[i] << endl;
				cout << endl << endl;
				cout << "================================" << endl;
				cout << "Time taken to search: " << timer.duration() << "ms" << endl;
				cout << "================================" << endl;

			}
			break;
		case 4:
			{
				exit(0);
			}
			break;
		default:
			break;
		}
	}

	return 0;	
}
