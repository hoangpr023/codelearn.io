#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

long MaximumNonAdj(std::vector<int> arr) {
	arr.insert(arr.begin(), 0);
	vector<int>F(arr.size(), 0);

	F[1] = arr[1];

	for (int i = 2; i < arr.size(); i ++) 
		F[i] = max(F[i - 2] + arr[i], F[i - 1]);
	return F[arr.size() - 1];

	
}



int main() {
	int n;
	int temp;
	fstream file("text.txt");
	vector<int> arr(0);
	int i = 0;
	while (file >> temp) arr.push_back(temp);

	file.close();
	
	cout << MaximumNonAdj(arr) << "\n";
	system("pause");
}