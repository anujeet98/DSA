#include<iostream>
#include<vector>
using namespace std;

class Student {
public:
	int marks;
	string name;
};

void bucket_sort(Student s[], int N) {
	//total marks 100 so create an vector-array containing 100 buckets
	vector<Student> v[101];//each block in this array is a vector. So for each marks[0-100] i.e 101 buckets; we add student with that mark into that vector
	for (int i = 0; i < N; i++) {
		int m = s[i].marks;
		v[m].push_back(s[i]);
	}

	cout << endl << "sorted acc to rank" << endl;
	for (int i = 100; i >= 0; i--) {
		for (vector<Student>::iterator it = v[i].begin(); it != v[i].end(); it++) {
			cout << (*it).marks << " " << (*it).name << endl;
		}
	}

}

int main(int argc, char const *argv[])
{
	Student s[100];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i].marks >> s[i].name;
	}
	bucket_sort(s, N);

	return 0;
}
