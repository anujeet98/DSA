#include<iostream>
#include<deque>

using namespace std;


int main(int argc, char const *argv[])
{
	deque<int> dq;
	int *arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int K;
	cin >> K;

	//for first k elements add into deque
	int i;
	for (i = 0; i < K; i++) {
		//take curr element compare with all from front
		//if less than current pop it
		//while queue is not empty or not encountered any back element >current element (since q is in decending order)
		//always q front has largest element
		//store index in queue
		while (!dq.empty() and arr[dq.back()] < arr[i]) {
			//pop it
			dq.pop_back();
		}
		//push_back the current element now into dq. //now largest element will be at front
		dq.push_back(i);
	}

	//now for remaining elements
	//first print the front as it contains max element in previous sub array
	//pop the elements from dq front (excess elements out of window size) ie dq front value + i should be < K
	//pop the front elements less than current // so that max is at front
	//push the element into dq
	// i starts from index where it left
	for (; i < n; i++) {
		cout << arr[dq.front()] << endl; //prints max element of prev subarray

		//pop from front excess elem in sliding window
		while (!dq.empty() and dq.front() <= i - K) {
			dq.pop_front();
		}

		//r3emove from back elem < current element
		while (!dq.empty() and arr[dq.back()] < arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

	//print the last element
	cout << arr[dq.front()] << endl;


	return 0;
}

