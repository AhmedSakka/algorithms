#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> suggestSearch(vector<string>& searchContent, string prefix) {
	sort(searchContent.begin(), searchContent.end());
	string currentPrefix = "";
	vector<vector<string>> results;
	int contentSize = searchContent.size(), searchStartIndex = 0;

	for (char& c : prefix) {
		currentPrefix += c;
		results.push_back({});

		int searchIndex = lower_bound(searchContent.begin() + searchStartIndex, searchContent.end(), currentPrefix) - searchContent.begin();

		for (int i = searchIndex; i < (min(searchIndex + 3, contentSize)) && searchContent[i].compare(0, currentPrefix.size(), currentPrefix) == 0; i++) {
			results.back().push_back(searchContent[i]);
		}

		searchStartIndex = searchIndex;
	}
	return results;
}

void printSearchResults(vector<vector<string>>& searchResults) {
	for (vector<string>& words : searchResults) {
		for (string& word : words) {
			cout << word << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<string> testContent = { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
	string searchWord = "mouse";

	vector<vector<string>> searchResults = suggestSearch(testContent, searchWord);
	printSearchResults(searchResults);
	return 0;
}
