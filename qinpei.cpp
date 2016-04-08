#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <fstream>
#include <iterator>
#include<regex>

using namespace std;
typedef pair<string, int> PAIR;

void contain(const string & sent, map<string, int> & myMap)
{
	const regex pattern("[a-zA-Z]+-?[a-zA-Z]*", regex::icase);
	sregex_iterator it(sent.begin(), sent.end(), pattern), end_it;
	for (; it != end_it; ++it)
		myMap[it->str()]++;
}

int main()
{
	ifstream inFile("article.txt");
	ofstream outFile_1("3_1_1out.txt");
	ofstream outFile_2("3_1_2out.txt");
	map<string, int> myMap;
	vector<string> nNeed;
	string s_voc;
	while (getline(inFile, s_voc))
	{
		transform(s_voc.begin(), s_voc.end(), s_voc.begin(), ::tolower);
		contain(s_voc, myMap);
	}
	for (auto each : myMap)
		outFile_1 << each.first << ':' << each.second << endl;
	vector<PAIR> v_sortMap(myMap.begin(), myMap.end());
	sort(v_sortMap.begin(), v_sortMap.end(),
		[](const PAIR & lhs, const PAIR & rhs) { return lhs.second > rhs.second; });
	for (auto each : v_sortMap)
		outFile_2 << each.first << ':' << each.second << endl;
}