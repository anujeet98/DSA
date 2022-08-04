#include<iostream>
#include<cmath>

using namespace std;

bool canPlace(int sudoku[][9], int x, int y, int N, int number) {
	//check horiz and verti; whether no not present
	for (int i = 0; i < N; i++) {
		if (sudoku[i][y] == number || sudoku[x][i] == number)
			return false;
	}
	//check if number can be placed in subgrid
	int rn = sqrt(N); //subgrid length
	int Sx = (x / rn) * rn; //start x index of subgrid
	int Sy = (y / rn) * rn; //start y index of subgrid
	for (int i = Sx; i < Sx + rn; i++) {
		for (int j = Sy; j < Sy + rn; j++) {
			if (sudoku[i][j] == number)
				return false;

		}
	}
	return true;
}

bool solveSudoku(int sudoku[][9], int x, int y, int N) {
	//base
	if (x == N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}

	//if bloack contains any number ; call for j+1th block in same row
	if (sudoku[x][y] != 0)
		return solveSudoku(sudoku, x, y + 1, N);
	//reached end of row ; move to next
	if (y == N)
		return solveSudoku(sudoku, x + 1, 0, N);

	//now if block is blank ie 0
	//fill with 1-9; check if no could be placed; call recursive to find further; if futher returns false; increase value; else return true
	for (int number = 1; number <= N; number++) {
		if (canPlace(sudoku, x, y, N, number)) {
			sudoku[x][y] = number;
			if (solveSudoku(sudoku, x, y + 1, N))
				return true;
		}
	}
	//backtrack if all numbers return false i.e need to change previous soln
	//make current as 0 and backtrack
	sudoku[x][y] = 0;
	return false;
}

int main(int argc, char const *argv[])
{
	int sudoku[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	if (!solveSudoku(sudoku, 0, 0, 9))
		cout << "no solution";
	return 0;
}



