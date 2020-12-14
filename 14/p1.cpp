#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;
const int N = 36;
typedef long long ll;

int main(void) {
	string mask;
	cin >> mask >> mask >> mask;


	ll n = mask.length();
	unordered_map<int,ll> mem;

	string a,b,c;
	while (cin >> a >> b >> c) {

		if (a == "mask") {
			mask = c;
			continue;
		}
		int idx = stoi(a.substr(4, a.length() - 1));
		ll num = stoi(c);

		// cout << idx << " - " << num << "\n";

		bitset<N> bs(num);

		for (int i = n - 1; i >= 0; i--) {
			if (mask[i] == 'X') continue;

			bs[n - 1 - i] = mask[i] - '0';
		}

		mem[idx] = bs.to_ulong();
	}

	ll ans = 0;
	for (auto it : mem) {
		// cout << it.first << " -> " << it.second << '\n';
		ans += it.second;
	}

	cout << ans << "\n";

	return 0;
}
