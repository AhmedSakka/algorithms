#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TrieNode {
public:
	map<char, TrieNode*> children;
	string word;
	TrieNode() {
		word = "";
	};
};


void backtrack(vector<vector<char>>& board, int row, int col, TrieNode* node, vector<string>& results) {
	int rowOffset[4] = { -1,0,1,0 };
	int colOffset[4] = { 0,1,0,-1 };

	char currentChar = board[row][col];
	TrieNode* childNode = node->children[currentChar];

	if (!childNode->word.empty()) {
		results.push_back(childNode->word);
		childNode->word = "";
	}

	board[row][col] = '#'; // Mark as visited

	for (int i = 0; i < 4; i++) {

		int newRowVal = row + rowOffset[i];
		int newColVal = col + colOffset[i];

		if (newRowVal < 0 || newRowVal >= board.size() || newColVal < 0 || newColVal >= board[newRowVal].size()) continue;
		int newChar = board[newRowVal][newColVal];
		if (childNode->children.count(newChar)) {
			backtrack(board, newRowVal, newColVal, childNode, results);
		}
	}

	board[row][col] = currentChar; // Backtrack
	if (childNode->children.empty()) {
		node->children.erase(currentChar);
	}
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	TrieNode* parentTrieNode = new TrieNode();
	vector<string> results;
	// Building the Trie
	for (string& word : words) {
		TrieNode* newNode = parentTrieNode;

		for (char& c : word) {
			if (!newNode->children.count(c)) {
				newNode->children[c] = new TrieNode();
			}	
			newNode = newNode->children[c];
		}
		newNode->word = word;
	}

	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board[0].size(); col++) {
			char currentChar = board[row][col];
			if (parentTrieNode->children.count(currentChar)) {
				backtrack(board, row, col, parentTrieNode, results);
			}
		}
	}

	return results;
}

void printWords(vector<string>& words) {
	for (string& word : words) {
		cout << word << " ";
	}
}


int main() {

	vector<vector<char>> testBoard = { {'o','a','a','n' }, { 'e','t','a','e' }, { 'i','h','k','r' }, { 'i','f','l','v' } };
	vector<string> testWords = { "oath","pea","eat","rain" };
	vector<string> testResults = findWords(testBoard, testWords);

	printWords(testResults);
	return 0;
}