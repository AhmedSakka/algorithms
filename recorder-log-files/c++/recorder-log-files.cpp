#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> reorderLogFiles(vector<string>& logs) {
	stable_sort(begin(logs), end(logs), [](const auto& a, const auto& b) {
		// Check if the log is a string log or digits log
		bool isStringA = isalpha(a.back());
		bool isStringB = isalpha(b.back());
		// Find the index of beginning of the log content
		int contentIndexA = a.find(' ');
		int contentIndexB = b.find(' ');
		// Extract the log ID
		string idA = a.substr(0, contentIndexA);
		string idB = b.substr(0, contentIndexB);
		// Extract the log Content
		string contentA = a.substr(contentIndexA + 1);
		string contentB = b.substr(contentIndexB + 1);
		// Compare the conents, if the content is the same then compare identifiers
		if (isStringA && isStringB) {
			return contentA == contentB ? idA < idB : contentA < contentB;
		}
		// Sort string logs before digits logs
		if (isStringA && !isStringB) {
			return true;
		}

		return false;
		});
	return logs;
}

void printVector(vector<string>& stringVector) {
	cout << "[";
	for (string& stringItem : stringVector) {
		cout << stringItem;
		if (stringItem != stringVector.back()) {
			cout << " , ";
		}
	}
	cout << "]";
}

int main() {

	vector<string> testLogs = { "dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero" };
	vector<string> sortedLogs = reorderLogFiles(testLogs);

	printVector(sortedLogs);

	return 0;
}