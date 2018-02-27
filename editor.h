#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


	class edit {
	public:

		vector<string> readFile(const string text);

		void writeFile(const vector<string> arr, string text);

		vector<string> toLow(vector<string> arr);

		string toLow(string str);

		void justPrint();

		void arrPrint(const vector<string> arr);

		void arrErase(vector<string>& buf, vector<string>& arr, const string word);

		bool operator()(const string& lhs, const string& rhs) const;
	};
