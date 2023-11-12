#include <iostream>
#include <Windows.h>
#include <map>
#include <fstream>
using namespace std;

typedef pair<string, string> word;

void Input(multimap<string, string>& dict) {
	string str1, str2;
	cout << "Enter a word in English: ";
	cin >> str1;
	cout << "Enter a word in Russian: ";
	cin >> str2;
	dict.insert(word(str1, str2));
}
void Print(multimap<string, string>& dict) {
	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		cout << it->first << " - " << it->second << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");

	multimap<string, string> dict;
	fstream file("Dictionary.txt", ios::in | ios::out | ios::trunc);

	int v;
	do
	{
		cout << "1.Input\n2.Print\n3.Find\nEnter: ";
		cin >> v;
		switch (v)
		{
		case 1:
			Input(dict);
			for (auto it = dict.begin(); it != dict.end(); it++)
			{
				file << it->first << " - " << it->second << endl;
			}
			break;
		case 2:
			Print(dict);
			break;
		case 3:
			string str;
			cout << "Enter the word you want find: ";
			cin >> str;
			int countOfWords = 0;
			auto result = dict.find(str);
			if (result == dict.end())
			{
				cout << "This word is not found\n";
				break;
			}
			for (; result != dict.end(); result++)
			{
				if (result->first == str) {
					cout << result->second << ' ';
					countOfWords++;
				}
			}
			cout << "This word has been found in the dictionary " << countOfWords << " times" << endl;
			break;
		}

	} while (v != 4);
	
	return 0;
}