/*
	programm soll eine Datei einlesen und die Worte inklusive ihrer Häufigkeit in einer Datei abspeichern.
*/


#include <iostream>
#include <string>
#include <map>
using std::map;
using std::string;
#include <cctype> //für tolower
#include <utility> //pair
#include <fstream>
using std::ifstream;
using std::ofstream;
#include "Testfunctions.h"



int main() try
{
	//open infile
	string nameIn{ "wiki100k.txt" };
	ifstream infile{ nameIn.c_str() };
	if (!infile) throw std::runtime_error("Kein Lesezugriff auf Datei");

	//open outfile
	string nameOut{ "p4a2.txt" };
	ofstream outfile{ nameOut.c_str() };
	if (!outfile) throw std::runtime_error("Kein Schreibzugriff auf Datei");

	//container
	map<string, int> words{};

	//copy words from infile to words map
	std::istream_iterator<string> in{ infile };
	std::istream_iterator<string> eof{};

	string i{};
	string word{};
	while (in != eof){
		word = *in;
		++in;
		if (words.find(word) == words.end()) { words.insert(make_pair(word, 1)); } //do if not in map
		else { words[word] += 1; }													//do if in map
	}

	checkEquals("#!comment:", words.cbegin()->first, "Test input beginning string");
	checkEquals(1015, words.cbegin()->second, "Test input beginning count");

	//sort words
	std::multimap<int, string> histo{};

	for (map<string, int>::const_iterator it{ words.cbegin() }; it != words.cend(); ++it)
	{
		//std::cout << (*it).first << it->second << std::endl;
		histo.insert(std::pair<int, string> {it->second, it->first});
	}

	for (map<int, string>::const_iterator it{ histo.cbegin() }; it != histo.cend(); ++it)
	{
		outfile << it->second;
		outfile.put(' ');
		outfile << it->first;
		outfile << std::endl;
		//std::cout << (*it).second << ' ' << it->first << std::endl;
	}

	checkEquals("''Tis", histo.cbegin()->second, "Test output");

	return 0;
}
catch (...)
{
	std::cerr << "unknown error";
	return -1;
}