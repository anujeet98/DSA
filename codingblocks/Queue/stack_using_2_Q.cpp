//implementation of STACK using 2 QUEUES

#include<iostream>
#include<queue>
using namespace std;


template<typename T>
class Stack {
private:
	queue<T> Q1, Q2;
public:
	void push(T d) {
		//push this element into non empty queue. let Q2 be empty always and push into q1
		Q1.push(d);
	}

	void pop() {
		//remove last
		//move n-1 elements to q2
		//rename q2 to q1 and vice versa

		//empty condn
		if (Q1.empty())
			return;
		while (Q1.size() > 1) {
			Q2.push(Q1.front());
			Q1.pop();
		}
		Q1.pop(); // removes last element from STACK

		//swap names of Q1 and Q1
		swap(Q1, Q2);

	}

	T top() {
		while (Q1.size() > 1) {
			Q2.push(Q1.front());
			Q1.pop();
		}
		T elem = Q1.front(); //storing in elem to return it from function
		Q2.push(Q1.front());
		Q1.pop();

		swap(Q1, Q2);

		return elem;
	}

	bool size() {
		return Q1.size() + Q2.size();
	}

	bool empty() {
		return size() == 0;
	}
};

int main(int argc, char const *argv[])
{
	Stack<int> s;
	for (int i = 1; i <= 5; i++) {
		s.push(i * i);
	}

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}

