#include<iostream>
#include<list>  //inked list: forward ll STL
using namespace std;
//CIRCULAR QUEUE implementation



class Queue {
private:
	int current_size;
	list<int> l;
public:
	Queue() {
		current_size = 0;
	}
	void push(int d) {
		l.push_back(d);
		current_size++;
	}
	void pop() {
		if (!empty()) {
			l.pop_front();
			current_size--;
		}
	}
	int front_elem() {
		return l.front();
	}
	bool empty() {
		return current_size == 0;
	}
	//no full in dynamic ds linked list
	// bool full() {
	// 	return current_size == max_size; //if equal then both are same returns true else false
	// }
};


int main(int argc, char const *argv[])
{
	Queue Q;

	for (int i = 1; i <= 6; i++) {
		Q.push(i);
	}

	Q.pop();
	Q.pop();

	Q.push(7);
	while (!Q.empty()) {
		cout << Q.front_elem() << endl;
		Q.pop();
	}

	return 0;
}
