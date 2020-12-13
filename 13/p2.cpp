#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(void) {

	int n;
	string s;
	cin >> n >> s;

	vector<pair<ll, int>> times;

	s += ',';
	int id = 0;
	int idx = -1;
	while ((idx = s.find(",")) != -1) {
		string sub = s.substr(0, idx);
		s.erase(0, idx + 1);

		if (sub != "x") times.push_back({stoi(sub), id});
		id++;
	}
	n = times.size();




	ll multiple = times[0].first;
	ll constant = 0;
	ll ans;
	
	for (int a = 2; a <= n; a++) {
		ll k = 0;
		while (true) {
			ll time = multiple*k + constant;
			ll prev = time;
			ll valid = true;
			// cout << "testing: " << time << "const = " << constant << " mult = " << multiple << '\n';

			for (int i = 1; i < a; i++) {
				// get the departure time
				ll targetTime = time + times[i].second;

				if (targetTime%times[i].first) {
					valid = false; 
					break;
				}
			}

			if (valid) {
				multiple *= times[a - 1].first;
				constant = time;
				ans = time;
				cout << time << " " << multiple << '\n';
				break;
			}

			k++;
		}
	}

	cout << "\nFINAL ANSWER:\n" << ans << '\n';


	return 0;
}
