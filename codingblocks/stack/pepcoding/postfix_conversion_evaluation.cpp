//https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/infix-conversions-official/ojquestion

#include<iostream>
#include<string>
#include<ctype.h>
#include<stack>

using namespace std;

//NO NEED FOR PRECEDENCE CHECK IN POSTFIX
// int precedence(char optr) {
// 	if (optr == '+')
// 		return 1;
// 	else if (optr == '-')
// 		return 1;
// 	else if (optr == '*')
// 		return 2;
// 	else if (optr == '/')
// 		return 2;
// }

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

void evaluate_postfix(string expression, int n) {
	//FOR POSTFIX need 1 stack for each opereation : evaluation, conversion infix, conversion prefix
	stack<string> prefix;
	stack<string> infix;
	stack<int> evaluation;

	for (int i = 0; i < n; i++) {
		char ch = expression[i];

		//FOR POSTFIX NO OPENING BRACKET NEEDED
		// if (ch == '(') {
		// 	//push to operator stack
		// 	operators.push(ch);
		// }


		//FOR POSTFIX NO NEED TO CHECK FOR CLOSING BRACKET
		// else if (ch == ')') {
		// 	while (operators.top() != '(') {
		// 		char optr = operators.top();
		// 		operators.pop();

		// 		string var2 = operand_postfix.top();
		// 		operand_postfix.pop();

		// 		string var1 = operand_postfix.top();
		// 		operand_postfix.pop();


		// 		string var4 = operand_prefix.top();
		// 		operand_prefix.pop();

		// 		string var3 = operand_prefix.top();
		// 		operand_prefix.pop();


		// 		//int ans = solve_operation(var1, var2,  optr);

		// 		operand_prefix.push(optr + var3 + var4);
		// 		operand_postfix.push(var1 + var2 + optr);
		// 	}

		// 	operators.pop();

		// }
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

			//NO NEED TO CHECK PRECEDENCE FOR POSTFIX
			int var2 = evaluation.top();
			evaluation.pop();
			int var1 = evaluation.top();
			evaluation.pop();

			int ans = solve_operation(var1, var2, ch);

			evaluation.push(ans);


			//for PREFIX expression pop 2 from stack and use operator and make prefix expression
			string exp2 = prefix.top();
			prefix.pop();
			string exp1 = prefix.top();
			prefix.pop();

			prefix.push(ch + exp1 + exp2);

			//for INFIX SAME AS PREFIX BUT ENCLOSE WITHING BRACKETS
			exp2 = infix.top();
			infix.pop();
			exp1 = infix.top();
			infix.pop();

			infix.push("(" + exp1 + ch + exp2 + ")");
		}

		else {
			//if its operands; push it into stack
			evaluation.push(ch - '0');
			//convert to string for push into infix and prefix stack
			string s(1, ch);
			prefix.push(s);
			infix.push(s);
		}
	}


	cout << evaluation.top() << endl;
	cout << infix.top() << endl;
	cout << prefix.top() << endl;

}




int main(int argc, char const * argv[])
{
	string expression;
	getline(cin, expression);
	int n = expression.length();

	evaluate_postfix(expression, n);

	return 0;
}
