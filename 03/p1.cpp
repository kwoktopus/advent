#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int count = 0;
	int x = 0;

	string s;
	while (cin >> s) {
		if (s[x] == '#') count++;

		x += 3;
		x %= s.length();
	}

	cout << count << '\n';

	return 0;
}
