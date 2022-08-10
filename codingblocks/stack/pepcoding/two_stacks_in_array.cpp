#include<iostream>
//#include<bits/stdc++.h>
#include<vector>

#include<string>

using namespace std;

class TwoStack {
public:
	vector<int> data;
	int tos1;
	int tos2;

	TwoStack(int capacity) {
		tos1 = -1;
		tos2 = capacity;
		vector<int> v (capacity);
		data = v;
	}

	void push1(int d) {
		if (tos2 == tos1 + 1) {
			cout << "Stack overflow" << endl;
		}
		else {
			tos1++;
			data[tos1] = d;
		}
	}

	void push2(int d) {
		if (tos2 == tos1 + 1) {
			cout << "Stack overflow" << endl;
		}
		else {
			tos2--;
			data[tos2] = d;
		}
	}

	int top1() {
		if (size1() > 0)
			return data[tos1];
		else {
			cout << "Stack underflow" << endl;
			return -1;
		}
	}
	int top2() {
		if (size2() > 0)
			return data[tos2];
		else {
			cout << "Stack underflow" << endl;
			return -1;
		}
	}

	int size1() {
		return tos1 + 1;
	}

	int size2() {
		return data.capacity() - tos2;
	}

	int pop1() {
		if (size1() > 0) {
			int x = data[tos1];
			tos1--;
			return x;
		}
		else {
			cout << "Stack underflow" << endl;
			return -1;
		}
	}
	int pop2() {
		if (size2() > 0) {
			int x = data[tos2];
			tos2++;
			return x;
		}
		else {
			cout << "Stack underflow" << endl;
			return -1;
		}
	}
};

int main() {
	string str;

	int cap;
	cin >> cap;
	TwoStack st(cap);

	while (true) {
		getline(cin, str);
		if (str[0] == 'q') {
			break;
		}
		else if (str[0] == 'p' && str[4] == '1') {
			string ss = str.substr(6, 2);
			int n = stoi(ss);
			st.push1(n);

		}
		else if (str[0] == 't' && str[3] == '1') {
			int tp = st.top1();
			if (tp != -1) cout << tp << endl;
		}
		else if (str[0] == 'p' && str[3] == '1') {
			int tp = st.pop1();
			if (tp != -1) cout << tp << endl;
		}
		else if (str[0] == 'p' && str[4] == '2') {
			string ss = str.substr(6, 2);
			int n = stoi(ss);
			st.push2(n);

		}
		else if (str[0] == 't' && str[3] == '2') {
			int tp = st.top2();
			if (tp != -1) cout << tp << endl;
		}
		else if (str[0] == 'p' && str[3] == '2') {
			int tp = st.pop2();
			if (tp != -1) cout << tp << endl;
		}

	}
	return 0;

}



5
push1 10 10
push1 20 10 20
push2 30 10 20 30
push2 40 10 20 40 30
push2 50 10 20 50 40 30
push1 60 overflow
top1  20
pop1  10 50 40 30
top1  10
pop1  50 40 30
top2  50
pop2  40 30
top2  40
pop2  30
top1 < -- -  underflow
pop1 < -- -  underflow
top2  30
pop2  30
quit

s1 10
s2 30