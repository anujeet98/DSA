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

int evaluate_infix(string expression, int n) {
	stack<int> operand;
	stack<char> operators;

	for (int i = 0; i < n; i++) {
		char ch = expression[i];

		if (ch == '(') {
			//push to operator stack
			operators.push(ch);
		}
		else if (isdigit(ch)) {
			//push to operand stack
			operand.push(ch - '0');
		}
		else if (ch == ')') {
			//expersion assumed to be balanced i.e for every ) bracket we have a ( bracket
			//pop 2 elements from operands and 1 from, operator evaluate it and push the result to operrands
			//do the above untill ( bracket occurs. pop that ( bracket at the end
			while (operators.top() != '(') {
				char optr = operators.top();
				operators.pop();

				int var2 = operand.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
				operand.pop();

				int var1 = operand.top();
				operand.pop();

				int ans = solve_operation(var1, var2,  optr);

				operand.push(ans);  //push the evaluated result into operand stack
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

				int var2 = operand.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
				operand.pop();

				int var1 = operand.top();
				operand.pop();

				int ans = solve_operation( var1,  var2,  optr);

				operand.push(ans);  //push the evaluated result into operand stack
			}

			//after all is done push the current operator on to the stack
			operators.push(ch);
		}
	}


	//if still some operators are left then evaluate the remaining untill operator stack becomes empty
	while (!operators.empty()) {
		char optr = operators.top();
		operators.pop();

		int var2 = operand.top(); //var2 is always on top and var 1 is below;  eg :operations: var1 + var2
		operand.pop();

		int var1 = operand.top();
		operand.pop();

		int ans = solve_operation( var1,  var2,  optr);

		operand.push(ans);  //push the evaluated result into operand stack
	}

	//return the last element on operand stack which is the final evaluated answer
	return operand.top();
}




int main(int argc, char const * argv[])
{
	string expression;
	getline(cin, expression);
	int n = expression.length();

	cout << evaluate_infix(expression, n);

	return 0;
}
