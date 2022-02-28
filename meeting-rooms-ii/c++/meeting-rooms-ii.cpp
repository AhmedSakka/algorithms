#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {

	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
		}); // O(NlogN)

	priority_queue<int, vector<int>, greater<int>> meetingRooms;

	for (vector<int>& interval : intervals) {
		if (!meetingRooms.empty() && interval[0] >= meetingRooms.top()) {
			meetingRooms.pop();
		}
		meetingRooms.push(interval[1]); // O(logN)
	} // O(N)
	return meetingRooms.size();
}


int main() {

	vector<vector<int>> testInput = { {0,30},{5,10},{15,20} };
	int testResult = minMeetingRooms(testInput);

	cout << "Number of meetings rooms needed : " << testResult << endl;

	return 0;
}