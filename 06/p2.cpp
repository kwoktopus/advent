#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	string s;
	int ans = 0, n = 0;
	int answers[26];
	memset(answers, 0, sizeof(answers));

	while (cin) {
		getline(cin, s);

		if (s.empty()) {
			for (int i = 0; i < 26; i++) {
				if (answers[i] == n) ans ++;
			}
			n = 0;
			memset(answers, 0, sizeof(answers));
		} else {
			n++;
			for (char c : s) {
				answers[c - 'a'] ++;
			}
		}
	} 

	for (int i = 0; i < 26; i++) {
		if (answers[i] == n) ans ++;
	}

	cout << ans << '\n';

	return 0;
}
