#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;




int main(int argc, char const *argv[])
{
	char a[] = "abcabcbb";//"abcdefghijklmnopqrstuvwxymz";

	int n = strlen(a);
	if (n == 0)
		return 0;


	int curr_len = 1 ;
	int max_len = 1;

	int visited[256];
	for (int i = 0; i < 256; i++) {
		visited[i] = -1;
	}

	visited[a[0]] = 0;

	for (int i = 1; i < n; i++) {
		int last_occr = visited[a[i]];

		//Expansion
		if ((last_occr == -1) || (last_occr < (i - curr_len))) //if(element has not ocured OR if element prev occr postion is before index of start of curr substring)
		{
			curr_len += 1;
		}

		//Expansion + contraction
		else {
			if (max_len < curr_len)
				max_len = curr_len;
			curr_len = i - last_occr;
		}
		visited[a[i]] = i;
	}


//update length at last position as well
	if (max_len < curr_len)
		max_len = curr_len;
	cout << max_len << endl;

	return 0;
}
