//USING STACK
//ALSO SOLVED USING DEQUE
//can also use binary heap, self balancing binary search tree


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	stack<int> st;
	int nums_size = nums.size();
	vector<int> nger_vec (nums_size, 0);


	for (int i = nums_size - 1; i >= 0; i--) {
		while (!st.empty() and nums[i] > nums[st.top()]) {
			st.pop();
		}

		if (st.empty()) {
			nger_vec[i] = nums_size;  //making  it outside array length as it won't get count in window
		}
		else {
			nger_vec[i] = st.top(); //index of next greater ellement right
		}

		st.push(i);
	}



	int req_length = nums_size - k;
	vector<int> ans;

	int j = 0;
	for (int i = 0; i <= req_length; i++) {
		if (j < i)
			j = i;
		while (nger_vec[j] - i < k) {
			j = nger_vec[j];
		}
		ans.push_back(nums[j]);
	}

	return ans;
}


int main(int argc, char const *argv[])
{
	vector<int>nums;
	int K;
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}

	cin >> K;

	vector<int> ans = maxSlidingWindow(nums, K);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

