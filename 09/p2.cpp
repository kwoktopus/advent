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
	int idx;
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
			idx = i;
			break;
		}
	}

	idx--;
	for (int i = 0; i < idx; i++) {
		ll sum = 0;

		ll smallest = v[i];
		ll largest = v[i];

		for (int j = i; j < idx; j++) {
			sum += v[j];

			smallest = min(smallest, v[j]);
			largest = max(largest, v[j]);

			if (sum == v[idx + 1]) {
				cout << smallest + largest << "\n";
				return 0;
			}
		}
	}

	return 0;
}
