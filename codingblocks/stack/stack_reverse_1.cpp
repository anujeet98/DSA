#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &S1, stack<int> &S2) {
	while (!S1.empty()) {
		S2.push(S1.top());
		S1.pop();
	}
}

void stackReverse(stack<int> &s) {
	int var_top;   //store top for the algo
	stack<int> helper;  //helper stack

	int n = s.size();

	for (int i = 0; i < n; i++) {
		//pop and store top in var
		var_top = s.top();
		s.pop();

		//move remaining elements from s to helper
		transfer(s, helper);

		//move top stored in var_top back to s
		s.push(var_top);

		//move all elem back from helper to s
		transfer(helper, s);

	}
}

int main(int argc, char const *argv[])
{
	stack<int> S;

	cout << "before reverse :" << endl;

	for (int i = 1; i < 5; i++) {
		S.push(i);
		cout << i << endl;
	}

	//Stack reverse
	stackReverse(S);

	cout << "after stack reverse: " << endl;
	while (!S.empty()) {
		cout << S.top() << endl;
		S.pop();
	}



	return 0;
}
