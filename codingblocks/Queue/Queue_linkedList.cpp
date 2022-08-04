#include<iostream>
using namespace std;
//CIRCULAR QUEUE implementation

class Node {
public:
	int data;
	Node *next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};

class Queue {
private:
	Node *front;
	Node *rear;

public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	void push(int d) {
		//empty queue
		Node *n = new Node(d);
		if (empty()) {
			front = n;
			rear = n;
		}
		else {
			rear->next = n;
			rear = n;
		}

	}
	void pop() {
		//no element present
		if (!empty()) {
			Node *temp = front->next;
			front->next = NULL;
			delete front;
			front = temp;

			//if front becomes null then no element present therefore rear also is null
			if (front == NULL)
				rear = NULL;
		}
	}
	int front_elem() {
		return front->data;
	}
	bool empty() {
		if (front == NULL and rear == NULL)
			return true;
		return false;
	}
	//no full in dynamic ds linked list
	// bool full() {
	// 	return current_size == max_size; //if equal then both are same returns true else false
	// }
	~Queue() {
		delete front;
	}
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
