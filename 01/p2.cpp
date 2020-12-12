#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	vector<int> v;

	int n;
	while (cin >> n) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				if (i == j) continue;

				if (v[i]+v[j]+n == 2020) {
					cout << v[j]*v[i]*n << '\n';

					return 0;
				}
			}
		}

		v.push_back(n);

	}

	return 0;
}
