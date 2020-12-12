#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	set<int> s;

	int n;
	while (cin >> n) {
		if (s.find(2020 - n) != s.end()) {
			cout << n*(2020 - n) << "\n";
			return 0;
		}

		s.insert(n);
	}

	return 0;
}