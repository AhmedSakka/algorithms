#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int sumSubarrayMins(vector<int>& arr) {

    int N = arr.size(), modulo = 1e9 + 7;

    stack<pair<int, int>> mStackLeft, mStackRight;
    vector<int> lesserLeft(N);
    vector<int> lesserRight(N);

    for (int i = 0; i < N; i++) {
        int count = 1;
        while (!mStackLeft.empty() && mStackLeft.top().first > arr[i]) {
            count += mStackLeft.top().second;
            mStackLeft.pop();
        }
        mStackLeft.push({ arr[i],count });
        lesserLeft[i] = count;
    }

    for (int i = N - 1; i >= 0; i--) {
        int count = 1;

        while (!mStackRight.empty() && mStackRight.top().first >= arr[i]) {
            count += mStackRight.top().second;
            mStackRight.pop();
        }
        mStackRight.push({ arr[i],count });
        lesserRight[i] = count;
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        result = (result + (long)arr[i] * lesserLeft[i] * lesserRight[i]) % modulo;
    }

    return result;

}

int main() {

    vector<int> testInput = { 3,1,2,4 };
    int testResult = sumSubarrayMins(testInput);

    cout << "Sum of subarrays is : " << testResult << endl;
    return 0;
}