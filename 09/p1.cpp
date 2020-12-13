#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 25;

int main(void) {
	vector<ll> v;

	ll n;
	while (cin >> n) {
		v.push_back(n);
	}

	for (int i = N; i < v.size(); i++) {
		bool valid = false;
		for (int j = i - N; j < i; j++) {
			for (int k = j + 1; k < i; k++) {
				if (v[j] != v[k] && v[j] + v[k] == v[i]) {
					valid = true;
					break;
				}
			}
		}

		if (!valid) {
			cout << v[i] << "\n";
			break;
		}
	}

	return 0;
}
