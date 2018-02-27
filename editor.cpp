#include "stdafx.h"
#include "editor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


	vector<string> edit::readFile(const string text) {
		vector<string> arr;
		ifstream stream;
		stream.open(text);
		if (!stream) { cout << "Can't load the file" << endl; }
		else { cout << "File is loaded" << endl; }
		string str;
		while (getline(stream, str)) { arr.push_back(str); }
		stream.close();
		return arr;
	}

	void edit::writeFile(const vector<string> arr, string text) {
		text = text + ".txt";
		ofstream stream;
		stream.open(text, ios::trunc);
		for (auto i : arr) { stream << i << endl; }
		stream.close();
	}

	vector<string> edit::toLow(vector<string> arr) {
		for (int i = 0; i < arr.size(); i++) {
			transform(arr[i].begin(), arr[i].end(), arr[i].begin(), tolower);
		}
		return arr;
	}

	string edit::toLow(string str) {
		transform(str.begin(), str.end(), str.begin(), tolower);
		return str;
	}

	void edit::justPrint() {
		cout << endl;
		cout << "1 - show" << endl;
		cout << "2 - delete" << endl;
		cout << "3 - sort" << endl;
		cout << "4 - save" << endl;
		cout << "5 - exit" << endl;
		cout << endl << "Enter the number: ";
	}

	void edit::arrPrint(const vector<string> arr) {
		if (arr.empty()) { cout << "File wasn't uploaded" << endl; }
		for (auto i : arr) { cout << i << endl; }
	}

	void edit::arrErase(vector<string>& buf, vector<string>& arr, const string word) {
		int i = 0;
		for (int j = 0; j < buf.size(); j++) {
			for (int k = 0; k < buf[j].length(); k++) {
				if (word[i] == buf[j][k]) {
					if (i == word.length() - 1) {
						buf[j].erase(k - i, word.length());
						arr[j].erase(k - i, word.length());
						k = 0;
						i = 0;
					}
					else {
						i++;
					}
				}
				else {
					i = 0;
				}
			}
		}
	}

	bool edit::operator()(const string& lhs, const string& rhs) const {
		string lhcLower(lhs);
		string rhcLower(rhs);
		transform(lhs.begin(), lhs.end(), lhcLower.begin(), tolower);
		transform(rhs.begin(), rhs.end(), rhcLower.begin(), tolower);
		return lhcLower < rhcLower;
	}
