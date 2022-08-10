#include<iostream>
#include<stack>
using namespace std;

void solve(string input) {
	stack<int> st;
	int i;
	for (i = 0; i < input.length(); i++) {
		char ch = input[i];
		if (ch == 'd') {
			st.push(i + 1);
		}
		else if (ch == 'i') {
			st.push(i + 1);
			while (!st.empty()) {
				cout << st.top();
				st.pop();

			}
		}
	}

	//push the last element
	st.push(i + 1);
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
int main(int argc, char const *argv[])
{
	string input;
	cin >> input;
	solve(input);
	return 0;
}
