//https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/infix-conversions-official/ojquestion

#include<iostream>
#include<string>
#include<ctype.h>
#include<stack>

using namespace std;


int precedence(char optr) {
	if (optr == '+')
		return 1;
	else if (optr == '-')
		return 1;
	else if (optr == '*')
		return 2;
	else if (optr == '/')
		return 2;
}

// int solve_operation(int var1, int var2, char optr) {
// 	if (optr == '+')
// 		return var1 + var2;
// 	else if (optr == '-')
// 		return var1 - var2;
// 	else if (optr == '*')
// 		return var1 * var2;
// 	else if (optr == '/')
// 		return var1 / var2;
// }

void evaluate_infix(string expression, int n) {
	stack<string> operand_prefix;
	stack<string> operand_postfix;
	stack<char> operators;

	for (int i = 0; i < n; i++) {
		char ch = expression[i];

		if (ch == '(') {
			//push to operator stack
			operators.push(ch);
		}
		else if (ch == ')') {
			//expersion assumed to be balanced i.e for every ) bracket we have a ( bracket
			//pop 2 elements from operands and 1 from, operator evaluate it and push the result to operrands
			//do the above untill ( bracket occurs. pop that ( bracket at the end
			while (operators.top() != '(') {
				char optr = operators.top();
				operators.pop();

				string var2 = operand_postfix.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
				operand_postfix.pop();

				string var1 = operand_postfix.top();
				operand_postfix.pop();


				string var4 = operand_prefix.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
				operand_prefix.pop();

				string var3 = operand_prefix.top();
				operand_prefix.pop();


				//int ans = solve_operation(var1, var2,  optr);

				operand_prefix.push(optr + var3 + var4); //push the evaluated result into operand stack
				operand_postfix.push(var1 + var2 + optr);
			}

			//pop the opening bracket as well
			operators.pop();

		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

			//need to pop and evaluate if conditions : 1)stack is not empty 2) ( bracket did NOT occurs 3)precedence of current optr is less than or equal to optr on top of stack(so pop elements and evaluate it first)
			//once all done push current optr into stack
			while ((!operators.empty()) and (operators.top() != '(') and (precedence(ch) <= precedence(operators.top())) ) {
				char optr = operators.top();
				operators.pop();

				string var2 = operand_postfix.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
				operand_postfix.pop();

				string var1 = operand_postfix.top();
				operand_postfix.pop();


				string var4 = operand_prefix.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
				operand_prefix.pop();

				string var3 = operand_prefix.top();
				operand_prefix.pop();


				//int ans = solve_operation(var1, var2,  optr);

				operand_prefix.push(optr + var3 + var4); //push the evaluated result into operand stack
				operand_postfix.push(var1 + var2 + optr);
			}

			//after all is done push the current operator on to the stack
			operators.push(ch);
		}
		else {
			//push to operand stack
			//cout << "" + ch << endl;
			string s(1, ch);
			operand_prefix.push(s);
			operand_postfix.push(s);
		}
	}


	//if still some operators are left then evaluate the remaining untill operator stack becomes empty
	while (!operators.empty()) {
		char optr = operators.top();
		operators.pop();

		string var2 = operand_postfix.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
		operand_postfix.pop();

		string var1 = operand_postfix.top();
		operand_postfix.pop();


		string var4 = operand_prefix.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
		operand_prefix.pop();

		string var3 = operand_prefix.top();
		operand_prefix.pop();


		//int ans = solve_operation(var1, var2,  optr);
		//cout << var1 << " " << var2 << " " << optr << " " << ("" + optr + var1 + var2) << endl;

		operand_prefix.push(optr + var3 + var4); //push the evaluated result into operand stack
		operand_postfix.push(var1 + var2 + optr);
	}

	//return the last element on operand stack which is the final evaluated answer
	// return operand.top();
	cout << operand_postfix.top() << endl;
	cout << operand_prefix.top() << endl;

}




int main(int argc, char const * argv[])
{
	string expression;
	getline(cin, expression);
	int n = expression.length();

	evaluate_infix(expression, n);

	return 0;
}
