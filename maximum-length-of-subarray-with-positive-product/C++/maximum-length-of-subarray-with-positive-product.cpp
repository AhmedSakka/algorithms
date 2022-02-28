#include <iostream>
#include <vector>

using namespace std;

int getMaxLen(vector<int>& nums) {
	int positiveLen = 0, negativeLen = 0, result = 0;

	for (int& num : nums) {
		if (num > 0) {
			positiveLen++;
			negativeLen = negativeLen == 0 ? 0 : negativeLen + 1;
		}
		else if (num < 0) {
			int temp = positiveLen;
			positiveLen = negativeLen == 0 ? 0 : negativeLen + 1;
			negativeLen = temp + 1;
		}
		else if (num == 0) {
			negativeLen = 0;
			positiveLen = 0;
		}
		result = max(result, positiveLen);
	}

	return result;
}


int main() {
  	
	vector<int> testInput = { 1, -2, -3, 4 };
	int result = getMaxLen(testInput);

	cout << "Max Length of positive subarray is : " << result << endl;
	return 0;
}