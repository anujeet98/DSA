#include<iostream>
#include<vector>
using namespace std;

class Stack {
private:
	vector<int> st;
public:
	void push(int data) {
		st.push_back(data);
	}
	int top() {
		return st[st.size() - 1];
	}
	void pop() {
		if (!is_empty())
			st.pop_back();
	}
	bool is_empty() {
		if (st.size() == 0)
			return true;
		else
			return false;
	}
};

int main(int argc, char const *argv[])
{
	Stack s;
	for (int i = 1; i < 6; i++) {
		s.push(i * i);
	}

	//printing
	while (!s.is_empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.top() << endl;  //this condition not checked; corrected in template program; by returning -1 if stack empty
	return 0;
}
