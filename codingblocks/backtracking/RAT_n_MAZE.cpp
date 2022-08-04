#include<iostream>
using namespace std;

void rat_maze(char arr[5][5], int curr_i, int curr_j, int dest_i, int dest_j) {
	//curr block in out of maze
	if (curr_i > dest_i || curr_j > dest_j)
		return;
	//curr block might be blocked
	if (arr[curr_i][curr_j] == 'X')
		return;
	//make curr block as 1
	arr[curr_i][curr_j] = '.';
	//curr block is destination then print and return
	if (curr_i == dest_i && curr_j == dest_j) {
		for (int i = 0; i <= dest_i; i++) {
			for (int j = 0; j <= dest_j; j++)
				cout << arr[i][j];
			cout << endl;
		}
		cout << endl << "____________________________________" << endl;
		return;
	}

	//call for curr path first go right and then down
	rat_maze(arr, curr_i, curr_j + 1, dest_i, dest_j);
	rat_maze(arr, curr_i + 1, curr_j, dest_i, dest_j);

	//while backtracking make the visited block as 0
	arr[curr_i][curr_j] = '0';
	return;
}


int main(int argc, char const *argv[])
{
	char arr[5][5] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};

	rat_maze(arr, 0, 0, 3, 3);
	return 0;
}

