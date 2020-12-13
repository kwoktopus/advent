#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	int n = 0;

	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;


	string s;
	while (cin >> s) {
		if (n == 0 || n%2 == 0) {
			cout << n << ", " << x5 << '\n';
			if (s[x5] == '#') count5++;

			x5 += 1;
			x5 %= s.length();
		}

		if (s[x1] == '#') count1++;
		if (s[x2] == '#') count2++;
		if (s[x3] == '#') count3++;
		if (s[x4] == '#') count4++;

		x1 += 1;
		x2 += 3;
		x3 += 5;
		x4 += 7;

		x1 %= s.length();
		x2 %= s.length();
		x3 %= s.length();
		x4 %= s.length();
		n++;
	}
	
	cout << count1*count2*count3*count4*count5 << '\n';
	return 0;
}
