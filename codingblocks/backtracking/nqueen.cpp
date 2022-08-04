#include<iostream>
using namespace std;

bool isSafePlace_Queen(int board[][10], int i, int j, int N) {
	//check if previously placed queens attack cuurent position
	//check back diagonal, front diagonal and straight back
	//1st straight back
	int x = i - 1;
	int y = j;
	while (x >= 0) {
		if (board[x][y] == 1)
			return false;
		x--;
	}

	//check back diagonal
	x = i - 1;
	y = j - 1;
	while (x >= 0 && y >= 0) {
		if (board[x][y] == 1)
			return false;
		x--;
		y--;
	}

	//check front diagonal
	x = i - 1;
	y = j + 1;
	while (x >= 0 && y < N) {
		if (board[x][y] == 1)
			return false;
		x--;
		y++;
	}
	//if no queen appeared
	return true;
}

void NQueen(int board[][10], int N, int row_index) {
	//base condn
	//placed all queens and completed all rows;  so print it
	if (row_index == N)
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0)
					cout << "_ ";
				else
					cout << "Q ";
			}
			cout << endl;
		}
		cout << endl << "______________________________________" << endl;
		return;
	}

	//try to place queen for all positions in this row_index and call recursive function to place Q in lower rows
	for (int i = 0; i < N; i++) {
		if (isSafePlace_Queen(board, row_index, i, N)) {
			board[row_index][i] = 1;
			NQueen(board, N, row_index + 1);
			board[row_index][i] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int board[10][10] = {0};
	NQueen(board, N, 0);
	return 0;
}


