#include<iostream>
using namespace std;

//O(N+Range) if range is small approx O(n)


void counting_sort(int *arr, int n) {
	//find largest element to create bucket of that sized array
	int largest = -1;
	for (int i = 0; i < n; i++)
		largest = max(largest, arr[i]);
	//create frequency array of that size

	//int *freq = new int[largest+1] {0};
	//or using memset for dynamic size
	int freq[largest + 1];
	memset( freq, 0, (largest + 1)*sizeof(int) );
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	//put elements back into arr by reading freq arr
	int j = 0;
	for (int i = 0; i <= largest; i++) {
		while (freq[i]--) {
			arr[j++] = i;
		}
	}
}

int main() {
	int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	counting_sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

