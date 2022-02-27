#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string removeNonAlphanumeric(string inputString) {
	replace_if(inputString.begin(), inputString.end(), [](const auto& c) {
		return !isalnum(c) && c != ' ';
		},' ');
	return inputString;
}

string convertStringToLowercase(string inputString) {
	transform(inputString.begin(), inputString.end(), inputString.begin(), [](const auto& c) {
		return tolower(c);
		});
	return inputString;
}

vector<string> splitString(string inputString, string delimiter) {
	vector<string> results;

	size_t wordPosition = 0;
	while ((wordPosition = inputString.find(delimiter)) != string::npos) {
		string word = inputString.substr(0, wordPosition);
		if(!word.empty()) results.push_back(word);
		
		inputString = inputString.substr(wordPosition + delimiter.size());
	}
	if(!inputString.empty()) results.push_back(inputString);
	
	return results;
}
string getMostCommonWord(string wordsString, vector<string>& bannedWords) {
	wordsString = removeNonAlphanumeric(wordsString);
	replace(wordsString.begin(), wordsString.end(), ',', ' ');
	wordsString = convertStringToLowercase(wordsString);

	vector<string> words = splitString(wordsString, " ");
	int maxFrequency = INT_MIN;
	string maxFreqWord = "";
	map<string, int> wordsFrequencyMap,bannedWordsMap;

	for (string& word : bannedWords) {
		bannedWordsMap[word] = 1;
	}
	for (string& word : words) {
		if (bannedWordsMap.count(word) == 0) {
			wordsFrequencyMap[word]++;
		}
	}
	for (map<string, int>::iterator it = wordsFrequencyMap.begin(); it != wordsFrequencyMap.end(); it++) {
		if (it->second > maxFrequency) {
			maxFrequency = it->second;
			maxFreqWord = it->first;
		}
	}

	return maxFreqWord;
}

int main() {
	string words = "Bob. hIt, baLl";
	vector<string> bannedWords = { "bob", "hit"};

	string mostFrequentWord = getMostCommonWord(words, bannedWords);
	cout << "Most frequent word is : " << mostFrequentWord << endl;
	return 0;
}