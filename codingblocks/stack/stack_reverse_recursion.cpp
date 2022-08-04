#include<iostream>
#include<stack>
using namespace std;

void pushatend(stack<int> &s1, int target) {
	//base
	if (s1.empty()) {
		s1.push(target);
		return;
	}

	int top_val = s1.top();
	s1.pop();
	pushatend(s1, target);
	s1.push(top_val);
}

void stack_Reverse_Recusrion(stack<int> &s) {
	//base condn
	if (s.size() <= 1)
		return;


	//if not base

	int var_top = s.top(); //store top for the algo
	s.pop();

	//recrsive call to reverse remaining elements
	stack_Reverse_Recusrion(s);

	//push var_top to the end of the stack recursively
	pushatend(s, var_top);
}

int main(int argc, char const *argv[])
{
	stack<int> S;

	for (int i = 1; i < 5; i++) {
		S.push(i);
	}


	//Stack reverse
	stack_Reverse_Recusrion(S);

	cout << "after stack reverse: " << endl;
	while (!S.empty()) {
		cout << S.top() << endl;
		S.pop();
	}



	return 0;
}
