#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

#define mod 1000000007


int easyLego(int n, int m) {
	vector<long long> F(m + 1, 1);
	long long a, b, c, d;
	for (int i = 1; i <= m; i ++) {
		a = F[i - 1];
		b = (i - 2 < 0) ? 0 : F[i - 2];
		c = (i - 3 < 0) ? 0 : F[i - 3];
		d = (i - 4 < 0) ? 0 : F[i - 4];
		F[i] = (a + b + c + d) % mod;
	}
	long long result = 1;
	for (int i = 0; i < n; i ++) {
		result *= F[m];
		result %= mod;
	
	}
	return result;
}


int main() {
	cout << easyLego(2, 4);
}