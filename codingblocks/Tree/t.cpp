#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	while (true) {
		cin >> s;
		if (s == "no")
			break;
		cout << stoi(s) << endl;
	}
	return 0;
}
