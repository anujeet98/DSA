//DNF sort hame same time complexity as of counting sort
//its just: instead of doing in 2 pass. array is sorted in single pass
#include<iostream>
#include<algorithm>
using namespace std;

void dnf_sort(int *arr, int n) {
//sort arr of 0's, 1s,2s
	int low = 0;
	int high = n - 1;
	int mid = 0;
	while (mid <= high) {
		if (arr[mid] == 0) {
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		}
		if (arr[mid] == 1) {
			mid++;
		}
		if (arr[mid] == 2) {
			swap(arr[mid], arr[high]);
			high--;
			//mid++;
		}

	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 2, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	dnf_sort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}


