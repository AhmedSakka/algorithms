#include <iostream>
#include <vector>


using namespace std;

int minFlipsMonoIncr(string s) {
	int stringSize = s.length();
	vector<int> prefixSums(stringSize + 1);
	int minFlips = INT_MAX;

	prefixSums[0] = 0;
	for (int i = 0; i < stringSize; i++) {
		prefixSums[i + 1] = prefixSums[i] + (s[i] == '1' ? 1 : 0);
	}

	for (int i = 0; i <= stringSize; i++) {
		minFlips = min(minFlips, prefixSums[i] + ((stringSize - i) - (prefixSums[stringSize] - prefixSums[i])));
	}

	return minFlips;
}

int main() {

	string testString = "010110";
	int minFlips = minFlipsMonoIncr(testString);

	cout << "Number of flips : " << minFlips << endl;
	return 0;
}