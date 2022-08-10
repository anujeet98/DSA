//https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/prefix-official/ojquestion

//PREFIX SAME AS POSTFIX JUST ITERATE FROM END TO START

#include<iostream>
#include<string>
#include<ctype.h>
#include<stack>
using namespace std;

int solve_operation(int var1, int var2, char optr) {
	if (optr == '+')
		return var1 + var2;
	else if (optr == '-')
		return var1 - var2;
	else if (optr == '*')
		return var1 * var2;
	else if (optr == '/')
		return var1 / var2;
}

void evaluate_pretfix(string expression, int n) {
	//FOR postfix need 1 stack for each opereation : evaluation, conversion infix, conversion postfix
	stack<string> postfix;
	stack<string> infix;
	stack<int> evaluation;

	for (int i = n - 1; i >= 0; i--) {  //-<<<<<<<<<<<<<<<<<<<<<<<<<<<<--------------------FROM END TO START
		char ch = expression[i];

		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

			//NO NEED TO CHECK PRECEDENCE FOR postfix -----------------REVERSE VAR1 and VAR2 for all conditions
			int var1 = evaluation.top();
			evaluation.pop();
			int var2 = evaluation.top();
			evaluation.pop();

			int ans = solve_operation(var1, var2, ch);

			evaluation.push(ans);


			//for PREFIX expression pop 2 from stack and use operator and make postfix expression
			string exp1 = postfix.top();
			postfix.pop();
			string exp2 = postfix.top();
			postfix.pop();

			postfix.push(exp1 + exp2 + ch);

			//for INFIX SAME AS PREFIX BUT ENCLOSE WITHING BRACKETS
			exp1 = infix.top();
			infix.pop();
			exp2 = infix.top();
			infix.pop();

			infix.push("(" + exp1 + ch + exp2 + ")");
		}

		else {
			//if its operands; push it into stack
			evaluation.push(ch - '0');
			//convert to string for push into infix and postfix stack
			string s(1, ch);
			postfix.push(s);
			infix.push(s);
		}
	}


	cout << evaluation.top() << endl;
	cout << infix.top() << endl;
	cout << postfix.top() << endl;

}




int main(int argc, char const * argv[])
{
	string expression;
	getline(cin, expression);
	int n = expression.length();

	evaluate_pretfix(expression, n);

	return 0;
}
