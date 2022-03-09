#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<string> splitString(string inputString, string delimiter) {
    size_t pos = 0;
    vector<string> results;
    while ((pos = inputString.find(delimiter)) != string::npos) {
        string word = inputString.substr(0, pos);
        inputString = inputString.substr(pos + 1);
        results.push_back(word);
    }
    results.push_back(inputString);
    return results;
}

bool wordPattern(string pattern, string s) {
    map<char, string> patternMap;
    vector<string> words = splitString(s, " ");

    if (words.size() != pattern.length()) return false;

    set<string> visitedWords;
    for (int i = 0; i < words.size(); i++) {
        if (patternMap.count(pattern[i])) {
            if (patternMap[pattern[i]] != words[i])
                return false;
            else
                continue;
        }

        if (visitedWords.find(words[i]) != visitedWords.end()) return false;

        patternMap[pattern[i]] = words[i];
        visitedWords.insert(words[i]);
    }

    return true;
}

int main() {
    string testPattern = "abba";
    string testWords = "dog cat cat dog";

    bool testResult = wordPattern(testPattern, testWords);
    
    if(testResult == true)
        cout << "Pattern : " << testPattern << " matches with: " << testWords;
    else
        cout << "Pattern : " << testPattern << " doesn't match with: " << testWords;

    return 0;
}