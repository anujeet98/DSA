#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class Queue {
private:
	stack<T> S1;
	stack<T> S2;
public:
	void push(T d) {
		//we only push on S1
		//when pop then move n-1 to s2 ; swap stacks and pop last element
		S1.push(d);
	}

	void pop() {
		if (S1.empty())
			return;
		while (S1.size() > 1) {
			S2.push(S1.top());
			S1.pop();
		}
		S1.pop();


//OPTIMIZE below steps no need to move to other stack: can do shifting when pop is requested and other stack is empty
		while (S2.size() > 0) {
			S1.push(S2.top());
			S2.pop();
		}
	}

	T front() {
		while (S1.size() > 0) {
			S2.push(S1.top());
			S1.pop();
		}
		T elem = S2.top();

		while (S2.size() > 0) {
			S1.push(S2.top());
			S2.pop();
		}
		return elem;
	}

	bool empty() {
		return S1.empty();  //stack STL empty method
	}
};

int main(int argc, char const *argv[])
{
	Queue<int> Q;

	for (int i = 1; i < 6; i++) {
		Q.push(i * i);
	}

	while (!Q.empty()) {
		cout << Q.front() << endl;
		Q.pop();
	}
	return 0;
}

