/*
sort string challenge
ip:
-no of strings :N
-N lines, different strings with chracter and spaces. No space at begin and end of string
No consecutive spaces. digits beside spaces are columns. 1st column is numbered as 1
-cloumn no.,Reverse, ordering(numeric/lexico)   (3 ip: col no to use for sorting strings, Reverse is boolean: to reverse output results order or not, ordering(numeric or lexicographic))
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string extractStringKey(string input, int col) {
	//use strtok to divide string into character array; ip: character array and delimiter " "
	//c_str()
	char *key = strtok( (char *)input.c_str(), " ");
	//string key_string;
	while (col > 1) {
		key = strtok(NULL, " ");
		col--;
	}

	return (string)key;
}

bool numericCMP(pair<string, string> p1, pair<string, string> p2) {
	string s1 = p1.second;
	string s2 = p2.second;
	return atoi(s1.c_str()) < atoi(s2.c_str());
}

bool lexicoCMP(pair<string, string> p1, pair<string, string> p2) {
	string s1 = p1.second;
	string s2 = p2.second;
	return s1 < s2;
}
int main() {

	int N;
	cin >> N;
	cin.get(); //to eleminate whitepace(enter) after number input into strings
	string arr[N];
	for (int i = 0; i < N; i++) {
		getline(cin, arr[i]);
	}
	int col;
	string reversal, ordering;

	cin >> col >> reversal >> ordering;

	//pair array containing string and column digit string
	pair<string, string> p[N];
	//use strtok inbuilt function to extract key string
	for (int i = 0; i < N; i++) {
		string key = extractStringKey(arr[i], col);
		p[i] = make_pair(arr[i], key);
	}

	//check ordering
	//1st numeric
	if (ordering == "numeric") {
		sort(p, p + N, numericCMP);
	}
	else {
		sort(p, p + N, lexicoCMP);
	}

	//check if need result to be reversed
	if (reversal == "true") {
		for (int i = 0; i < N / 2; i++) {
			swap(p[i], p[N - i - 1]);
		}
	}

	//print string pairs after sorted

	for (int i = 0; i < N; i++) {
		cout << p[i].first << endl;
	}


	return 0;
}
