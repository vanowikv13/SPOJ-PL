// LENLCS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using vec = vector<pair<char, int>>;

using namespace std;

//return common data in both map
map<char,int> commonData(map<char, int> shorter, map<char, int> longer);

//our data returnet in map with <letterInString, occurrenceOfALetter>
map<char, int> returnStringInMap(string str);

//delete data in basicData what aren't in common data
void changeValueInMap(map<char, int> &basicData, const map<char, int> common);

int main()
{
	int x, y, k;
	string data;

	//ile razy
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> x;	cin >> data;
		auto object1 = returnStringInMap(data);
		cin >> y;	cin >> data;
		auto object2 = returnStringInMap(data);

		map<char, int> common;
		if (x > y)
			common = commonData(object2, object1);
		else
			common = commonData(object1, object2);

		changeValueInMap(object1, common);
		changeValueInMap(object2, common);
	}
    return 0;
}

map<char, int> commonData(map<char, int> shorter, map<char, int> longer)
{
	map<char, int> letters;
	for (auto &x : shorter) {
		if (longer.find(x.first) != longer.end())
			letters[x.first] += 1;
	}

	return letters;
}

vec returnStringInMap(string str)
{
	vec object;

	for (int j = 0; j < str.size(); j++) {
		object[str[j]] += 1;
	}

	return object;
}

void changeValueInMap(map<char, int> &basicData, const map<char, int> common)
{
	for (auto &x : basicData) {
		if (common.find(x.first) == common.end())
			basicData.erase(x.first);
	}
}
