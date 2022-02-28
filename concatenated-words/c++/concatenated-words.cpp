#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

	unordered_set<string> wordsSet(words.begin(), words.end());
	vector<string> results;

	for (string& word : words) {
		int wordSize = word.size();
		vector<bool> dp(wordSize + 1);
		dp[0] = 1;
		for (int i = 0; i < wordSize; i++) {
			if (!dp[i]) continue;
			for (int j = i + 1; j <= wordSize; j++) {
				if (j - i < wordSize && wordsSet.find(word.substr(i, j - i)) != wordsSet.end()) {
					dp[j] = true;
				}
			}
			if (dp[wordSize]) {
				results.push_back(word);
				break;
			}
		}
	}

	return results;
}

void printWords(vector<string>& words) {
	for (string& w : words) {
		cout << w << " ";
	}
}


int main() {
	vector<string> testInput = { "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
	vector<string> testOutput = findAllConcatenatedWordsInADict(testInput);

	printWords(testOutput);
	
	return 0;
}