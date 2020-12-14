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

vector<string> bitsets;

void recurse(string s, int idx) {
	if (idx == s.length()) {
		bitsets.push_back(s);
		return;
	}

	if (s[idx] == 'X') {
		s[idx] = '1';
		recurse(s, idx + 1);

		s[idx] = '0';
		recurse(s, idx + 1);
		
		return;
	}

	recurse(s, idx + 1);
}

int main(void) {
	string mask;
	cin >> mask >> mask >> mask;


	ll n = mask.length();
	unordered_map<ll,ll> mem;

	string a,b,c;
	while (cin >> a >> b >> c) {

		if (a == "mask") {
			mask = c;
			continue;
		}

		ll idx = stoi(a.substr(4, a.length() - 1));
		ll num = stoi(c);

		// cout << idx << " - " << num << "\n";
		// idx gets modified instead
		bitset<N> bs(idx);
		string bstring = bs.to_string();
		for (int i = 0; i < n; i++) {
			if (mask[i] == '0') continue;
			else bstring[i] = mask[i];
		}


		bitsets.clear();
		recurse(bstring, 0);

		for (string out : bitsets) {
			bitset<N> idxbs;
			for (int i = 0; i < n; i++) {
				idxbs[n - 1 - i] = out[i] - '0';
			}

			mem[idxbs.to_ulong()] = num;
		}

	}

	ll ans = 0;
	for (auto it : mem) {
		// cout << it.first << " -> " << it.second << '\n';
		ans += it.second;
	}

	cout << ans << "\n";

	return 0;
}
