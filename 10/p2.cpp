#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;


int main(void) {

	int n;
	vector<int> v;

	while (cin >> n) {
		v.push_back(n);
	}

	v.push_back(0);
	sort(v.begin(), v.end());
	v.push_back(v[v.size() - 1] + 3);

	n = v.size();

	// dp[i][j] = number of ways to reach power[j] using the first j adapters	
	ll dp[n];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		ll val = v[i];

		for (int j = i - 1; j >= 0; j--) {
			if (val - v[j] > 3) break;
		 	dp[i] += dp[j];
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << dp[i] << "\n";
	// }


	cout << dp[n - 1] << "\n";

	return 0;	
}
