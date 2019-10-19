#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;


bool checkCondiction(int arr[][8], int row, int col) {
	for (int i = 0; i < 8; i ++) {
		if (i == col) continue;
		if (arr[row][i] == 1) return false;
	}
	for (int i = 0; i < 8; i ++) {
		if (i == row) continue;
		if (arr[i][col] == 1) return false;
	}
	int c = col, r = row;
	while (c != 0 && r != 0) {
		c --;
		r --;
	}
	while (c < 8 && r < 8) {
		if (c == col) {
			r ++; c ++;
			continue;
		}
		if (arr[r][c] == 1) return false;
		r ++;
		c ++;
	}

	c = col, r = row;
	while (c != 7 && r != 0) {
		c ++;
		r --;
	}
	while (c > 0 && r < 8) {
		if (c == col) {
			r ++;
			c --;
			continue;
		}
		if (arr[r][c] == 1) {
			return false;
		}
		r ++;
		c --;
	}
	return true;


}

bool findQueenPos(int arr[][8], int col) {
	static bool check = false;
	for (int i = 0; i < 8; i ++) {
		if (check == true) return true;
		arr[i][col] = 1;
		if (checkCondiction(arr, i, col)) {
			if (col == 7) {
				check = true;
				return true;
			}
			findQueenPos(arr, col + 1);
		}

		if (check == false) {
			arr[i][col] = 0;
		}
	}
	if (check == true) return true;
	return false;
}


int main() {
	int arr[][8] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
	cout << findQueenPos(arr, 0) << "\n\n";

	for (int i = 0; i < 8; i ++) {
		for (int j = 0; j < 8; j ++)
			cout << arr[i][j] << "\t";
		cout << "\n";
	}

}