//https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/duplicate_brackets/topic

//given balanced expression i.e for every '(' there is an ')'
//find if there is any duplicate bracket ie. each openeing and closing bracket should have some characters; if not then that is dublicate
//eg:  (a+b) + ((c+d-f))    c+d-f already hac one bracket; so the outer bracket becomes dupilcate; so funtn should return True

#include<iostream>
#include<stack>
using namespace std;

void duplicate_bracket(char *arr, int n) {
	stack<char> st;
	for (int i = 0; i < n; i++) {
		char ch = arr[i];

		if (ch == ')') {
			if (st.top() == '(') {
				cout << "TRUE" << endl;
				return;
			}
			while (st.top() != '(') {
				st.pop();
			}
			st.pop();
		}
		else {
			st.push(ch);
		}
	}
	cout << "FALSE" << endl;
}

int main(int argc, char const *argv[])
{
	//FALSE input test case
	char *arr = "((a + b) + (c + d))";

	//TRUE input test case
	//char *arr = "(a+b)+((c+d))";
	int n = strlen(arr);
	//cout << n << endl;
	duplicate_bracket(arr, n);

	return 0;
}








//SUBMITTED CODE in PEPCODE


// #include<iostream>
// #include<stack>
// #include<cstring>
// using namespace std;

// void duplicate_bracket(string arr, int n) {
//   stack<char> st;
//   for (int i = 0; i < n; i++) {
//     char ch = arr[i];

//     if (ch == ')') {
//       if (st.top() == '(') {
//         cout << "true" << endl;
//         return;
//       }
//       while (st.top() != '(') {
//         st.pop();
//       }
//       st.pop();
//     }
//     else {
//       st.push(ch);
//     }
//   }
//   cout << "false" << endl;
// }

// int main(int argc, char const* argv[])
// {
//   //FALSE input test case
//   string arr;
//   getline(cin,arr);

//   //TRUE input test case
//   //char *arr = "(a+b)+((c+d))";
//   int n = arr.size();

//   //cout << n << endl;
//   duplicate_bracket(arr, n);

//   return 0;
// }
