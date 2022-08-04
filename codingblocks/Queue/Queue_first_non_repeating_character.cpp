#include<iostream>
#include<queue>
#include<map>
using namespace std;


// int main(int argc, char const *argv[])
// {

// 	queue<char> Q;
// 	map<char, int> m;

// 	char *arr = "aabcbccd";

// 	for (int i = 0; arr[i] != '\0'; i++) {
// 		//add char to queue and frequency table
// 		Q.push(arr[i]);
// 		if (m.count(arr[i]))
// 			m[arr[i]]++;
// 		else
// 			m.insert(make_pair(arr[i], 1));

// 		//check query to find first not repeating char
// 		if (!Q.empty()) {
// 			while (m[Q.front()] > 1)
// 				Q.pop();
// 			if (Q.empty())
// 				cout << -1 << endl;
// 			else
// 				cout << Q.front() << endl;
// 		}
// 	}

// 	return 0;
// }


int main(int argc, char const *argv[])
{

	queue<char> Q;
	int freq[27] = {0};

	//create running stream take input until '.' occurs

	char ch;
	cin >> ch;
	while (ch != '.') {
		//add char to queue and frequency table
		Q.push(ch);
		freq[ch - 'a']++;


		//check query to find first not repeating char
		while (!Q.empty() and freq[Q.front() - 'a'] > 1) {
			Q.pop();
		}

		if (Q.empty())
			cout << -1 << "----" << endl;
		else
			cout << Q.front() << "----" << endl;


		cin >> ch;
	}

	return 0;
}

