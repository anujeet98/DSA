#include<iostream>
#include<set>
#include<string>
using namespace std;

void permutation(char input[], int i, set<string> &s) {
	//base condition
	if (input[i] == '\0') {
		s.insert(input);
		return;
	}

	//consider picking each character by swapping
	for (int j = i; input[j] != '\0'; j++) {
		//bring each character to front
		swap(input[i], input[j]);
		permutation(input, i + 1, s);
		swap(input[i], input[j]);
	}
	return;
}

int main(int argc, char const *argv[])
{
	char input[100];
	cin >> input;
	//to find unique permutation and in lexicographic order : use set to store
	set<string> s;
	permutation(input, 0, s);
	for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ", ";
	}
	return 0;
}


