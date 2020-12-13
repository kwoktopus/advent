#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> hasGold;
unordered_map<string, vector<string>> contains;

bool dfs(string bag) {
	// cout << bag << "\n";
	if (bag == "shiny gold bag" || hasGold[bag]) return true;

	for (string next : contains[bag]) {
		if (dfs(next)) {
			hasGold[bag] = true;
			return true;
		}
	}

	hasGold[bag] = false;
	return false;
}


int main(void) {
	string s;

	while (cin) {
		getline(cin, s);
		if (s.empty()) break;
		s[s.length() - 1] = ',';
		
		string outer = s.substr(0, s.find(" contain") - 1);

		s.erase(0, s.find(" contain") + 8);

		vector<string> v;
		
		int idx = -1;
		while ((idx = s.find(",")) != -1) {
			string bag = s.substr(1, idx - 1);
			bag.erase(0, bag.find(" ") + 1);
			if (bag[bag.length() - 1] == 's') bag = bag.substr(0, bag.size() - 1);

			v.push_back(bag);
			s.erase(0, idx + 1);
		}

		contains[outer] = v;


		// cout << outer << ": " << s << "\n";
	}

	int ans = 0;
	for (auto it : contains) {
		// break;
		// cout << it.first << ": ";
		// for (string b : it.second) {
		// 	cout << b << ", ";
		// }
		// cout << "\n";
		if (it.first != "shiny gold bag" && dfs(it.first)) ans++;

	}
	cout << ans << "\n";
	return 0;
}
