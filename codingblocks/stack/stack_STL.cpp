#include<iostream>
#include<stack>//<------------------------------------STACK STL
using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> S;

	for (int i = 0; i < 5; i++) {
		S.push(i * i);
	}

	while (!S.empty()) {
		cout << S.top() << endl;
		S.pop();
	}

	// Stack<char> S1;  //stack is genrelized as it can now take in any datatype

	// for (int i = 65; i < 70; i++) {
	// 	S1.push(i);
	// }

	// while (!S1.empty()) {
	// 	cout << S1.top() << endl;
	// 	S1.pop();
	// }


	return 0;
}
