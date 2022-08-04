#include<iostream>
#include<vector>
using namespace std;

//TEMPLATE WITH 2 DATATYPE init
template<typename T, typename U>
class Stack {
private:
	vector<T> v1;
	vector<U> v2;
public:
	void push(T data) {
		v1.push_back(data);
	}

	void pop() {
		if (!empty())
			v1.pop_back();
	}

	T top() {
		if (!empty())
			return v1[v1.size() - 1];
		return -1;
	}

	bool empty() {
		if (v1.size() == 0)
			return true;
		return false;
	}
};


int main(int argc, char const *argv[])
{
	Stack<int, char> S;

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
