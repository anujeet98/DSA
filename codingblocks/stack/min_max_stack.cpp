#include<iostream>
#include<vector>

using namespace std;


class Stack {
private:
	vector<int> st;
	vector<int> min_stack;
	vector<int> max_stack;

public:
	void push(int data) {
		int curr_min = data;
		int curr_max = data;
		if (min_stack.size()) {
			curr_min = min(curr_min, min_stack[min_stack.size() - 1]);
			curr_max = max(curr_max, max_stack[max_stack.size() - 1]);
		}
		min_stack.push_back(curr_min);
		max_stack.push_back(curr_max);
		st.push_back(data);
	}

	bool empty() {
		if (st.size() == 0)
			return false;
		return true;
	}

	void pop() {
		//remove from all 3 stacks
		if (!st.empty()) {
			st.pop_back();
			min_stack.pop_back();
			max_stack.pop_back();
		}
	}
	int top() {
		return st[st.size() - 1];
	}

	int GetMin() {
		return min_stack[min_stack.size() - 1];
	}
	int GetMax() {
		return max_stack[max_stack.size() - 1];
	}
};

int main() {
	Stack st;
	st.push(1);
	st.push(4);
	st.push(2);
	st.push(6);

	cout << st.GetMax() << endl;
	cout << st.GetMin() << endl;

	st.pop();
	cout << st.top() << endl;
	cout << st.GetMin() << endl;
	cout << st.GetMax() << endl;

	return 0;
}

