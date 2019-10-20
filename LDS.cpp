#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;


int max(int a, int b) {
	if (a > b) return a;
	return b;
}

// int findMax(vector<int> arr) {
// 	vector<int> B(arr.size(), 1);
// 	int m = 0;
// 	bool check = false;
// 	int C = 1;

// 	for (int i = 1; i < arr.size(); i ++) {
// 		m = 0;
// 		for (int j = 0; j < i; j ++) {
// 			if (arr[j] < arr[i]) 
// 				m = max(m, B[j]);
			
// 		}
// 		B[i] = m + 1;
// 		C = max(C, B[i]);

// 	}

// 	return C;
// }

int findMax(vector<int> arr) {
	vector<int> B(arr.size(), 1);
	int m = 0;
	int C = 1;

	for (int i = 1; i < arr.size(); i ++) {
		m = 0;
		for (int j = 0; j < i; j ++) {
			if (arr[j] > arr[i]) 
				m = max(m, B[j]);
			
		}
		B[i] = m + 1;
		C = max(C, B[i]);
	}
	return C;
}
  
// Driver program to test above 
int main() 
{ 
    int x[] = {4, 3, -2, 6, 1, 7};
    vector<int> arr(x, x + 6);
    cout << findMax(arr);     
} 