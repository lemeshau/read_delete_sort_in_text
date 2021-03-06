#include "stdafx.h"
#include "editor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;




int main(int argc, char* argv[]) {

	vector<string> arr;
	vector<string> buf;
	
	edit* obj = new edit;
	arr = obj->readFile(argv[1]);
	buf = obj->toLow(arr);
	
	while (true)
	{
		obj->justPrint();
		int a;
		cin >> a;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (a)
		{
		case 1:
		{
			obj->arrPrint(arr);
			break;
		}

		case 2:
		{
			cout << "Enter the word to delete: ";
			string word;
			getline(cin >> ws, word);
			word = obj->toLow(word);
			obj->arrErase(buf, arr, word);
			cout << "Completed" << endl;
			break;
		}

		case 3:
		{
			sort(buf.begin(), buf.end(), edit());
			sort(arr.begin(), arr.end(), edit());
			cout << "Completed" << endl;
			break;
		}

		case 4:
		{
			cout << "Enter the name of file: ";
			string fileName;
			getline(cin >> ws, fileName);
			obj->writeFile(arr, fileName);
			cout << "Completed" << endl;
			break;
		}

		case 5: return 0;

		default: {cout << "Incorrect number" << endl; break; }

		}
	}
	return 0;

}

