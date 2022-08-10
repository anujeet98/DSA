#include<iostream>
#include<vector>
#include<stack>
#include <utility>

using namespace std;

bool compare(pair<int, int> interval1, pair<int, int>interval2) {
	return interval1.first <= interval2.first;
}

void merge(vector<pair<int, int> > intervals) {
	stack< pair<int, int> > stk;
	for (int i = 0; i < intervals.size(); i++) {
		if (i == 0) {
			stk.push(intervals[i]);
		}
		else {
			if (intervals[i].first <= stk.top().second) {
				stk.top().second = max(stk.top().second, intervals[i].second);
			}
			else
				stk.push(intervals[i]);
		}
	}

	stack < pair<int, int> > helper_stk;
	while (!stk.empty()) {
		helper_stk.push(stk.top());
		stk.pop();
	}
	while (!helper_stk.empty()) {
		cout << helper_stk.top().first << " " << helper_stk.top().second << endl;
		helper_stk.pop();
	}

}

int main() {
	vector < pair<int, int> > intervals;
	int n;
	cin >> n;

	int st;
	int et;
	for (int i = 0; i < n; i++) {
		cin >> st >> et;
		intervals.push_back(make_pair(st, et));
	}

	//sort the intervals according to st
	sort(intervals.begin(), intervals.end(), compare);

	merge(intervals);



}
