#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int ans;

	string s;
	while (cin >> s) {
		int left = 0;
		int right = 127;
		for (int i = 0; i < 7; i++) {
			if (s[i] == 'F') {
				right = (left + right)/2;
			} else if (s[i] == 'B') { 
				left = ceil(1.0*(left + right)/2);
			} else {
				cout << "fuck\n";
			}
			// cout << left << " -> " << right << "\n";
		}

		// left is the row
		int row = left;

		left = 0;
		right = 8;

		for (int i = 7; i < s.length(); i++) {
			if (s[i] == 'L') {
				right = (left + right)/2;
			} else if (s[i] == 'R') { 
				left = ceil(1.0*(left + right)/2);
			} else {
				cout << "fuck\n";
			}
			// cout << left << " -> " << right << "\n";
		}

		int col = left;
		cout << row << ", " << col << '\n';
		ans = max(ans, row*8 + col);
	}	
	cout << ans << '\n';
	return 0;
}
