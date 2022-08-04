#include<iostream>
using namespace std;
//CIRCULAR QUEUE implementation


class Queue {
private:
	int front;
	int rear;
	int current_size;
	int max_size;
	int *arr;

public:
	Queue(int ds = 5) {
		//accepted default size; created queue of that size; arr is pointing to that array
		//cs is 0 since empty; ms=accepted default size; front inital =0 and rear is end index
		arr = new int[ds];
		current_size = 0;
		max_size = ds;
		front = 0;
		rear = ds - 1;
	}
	void push(int d) {
		//check is queue is full(since array is used)
		//else add queue to rear and increament rear
		if (!full()) {
			rear = (rear + 1) % max_size;
			arr[rear] = d;
			current_size++;
		}
	}
	void pop() {
		if (!empty()) {
			front = ((front + 1) % max_size);
			current_size--;
		}
	}
	int front_elem() {
		return arr[front];
	}
	bool empty() {
		if (current_size == 0)
			return true;
		return false;
	}
	bool full() {
		return current_size == max_size; //if equal then both are same returns true else false
	}
	~Queue() {
		if (arr != NULL) {
			delete [] arr;
			arr = NULL;

		}
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
