#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int left,right;
	int count = 0;

	while (cin >> left) {
		char c,dummy;
		string pw;
		cin >> dummy >> right >> c >> dummy >> pw;

		int n = 0;
		for (char ch : pw) {
			if (ch == c) {
				n++;
			}
		}

		if (n >= left && n <= right)count++;
	}

	cout << count;

	return 0;
}
