#include<iostream>
#include<queue>
using namespace std;



int main(int argc, char const *argv[])
{
	queue<int> Q;

	for (int i = 1; i <= 6; i++) {
		Q.push(i);
	}

	while (!Q.empty()) {
		cout << Q.front() << endl;
		Q.pop();
	}

	return 0;
}
