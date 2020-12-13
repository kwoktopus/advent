#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
	string s;
	unordered_set<char> set;
	int ans = 0;
	while (cin) {
		getline(cin, s);

		if (s.empty()) {
			ans += set.size();
			set.clear();
		} else {
			for (char c : s) {
				set.insert(c);
			}
		}
	} 

	cout << ans + set.size() << '\n';

	return 0;
}
