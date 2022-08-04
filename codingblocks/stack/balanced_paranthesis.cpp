#include<iostream>
#include<stack>
using namespace std;

bool valid_blanaced(char *s) {
	stack<char> stk;

	for (int i = 0; s[i] != '\0'; i++) {
		char ch = s[i];
		if (ch == '(')
			stk.push(ch);
		else if (ch == ')') {
			if (stk.empty() or stk.top() != '(')
				return false;
			stk.pop();

		}
	}
	if (stk.empty())
		return true;
	else
		return false;

}


int main() {
	char s[100] = "((a+b)+(c+d-f))";
	if (valid_blanaced(s))
		cout << "Yes, it is balanced" << endl;
	else
		cout << "No, it is not balanced" << endl;
	return 0;
}
