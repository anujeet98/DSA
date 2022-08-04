#include<iostream>
#include<stack>

using namespace std;

int find_largest_area_histogram(int *arr, int n) {
	stack<int>st;

	//find NSEL next smaller element left //CAN SOLVE USING NSEL and NSER and then find area
	int area[n];

	for (int i = 0; i < n; i++) {
		while (!st.empty() and arr[st.top()] >= arr[i])
			st.pop();

		if (st.empty())
			area[i] = i + 1; //STORING THE SPAN OF RECTANGLE ON LEFT instead of next smaller element. ********CAN DO BOTH THE WAYS

		else
			area[i] = i - st.top(); //NO NEED FOR -1 since we are calculating span from smaller bar index and not from last bar of the recatangle
		st.push(i);
	}

	//make stack empty
	while (!st.empty())
		st.pop();

	//find NSER next smaller element right, ALSO COMPUTE AREA ans store it here
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and arr[st.top()] >= arr[i])
			st.pop();

		int leftspan;
		if (st.empty()) {
			leftspan = n - i; //STORING THE SPAN OF RECTANGLE ON LEFT instead of next smaller element. ********CAN DO BOTH THE WAYS
		}

		else
			leftspan = st.top() - i; //NO NEED FOR -1 since we are calculating span from smaller bar index and not from last bar of the recatangle

		st.push(i);


		//total width = right span + leftspan - 1(-1 because current bar is add in both the span)
		//right span is already at area[i] add leftspan to it
		area[i] += leftspan - 1;
		//compute area also and store it at same place
		area[i] = area[i] * arr[i];
	}


	//find max area
	int max_area = area[0];
	for (int i = 1; i < n; i++) {
		max_area = max(max_area, area[i]);
	}
	return max_area;

}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << find_largest_area_histogram(arr, n) << endl;
	return 0;
}

