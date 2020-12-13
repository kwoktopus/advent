#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> nBags;
unordered_map<string, vector<pair<int, string>>> contains;

int dfs(string bag) {
	if (nBags.find(bag) != nBags.end()) return nBags[bag];
	// cout << bag << "\n";
	int res = 1;
	for (pair<int, string> next : contains[bag]) {
		res += dfs(next.second) * next.first;
	}

	nBags[bag] = res;
	return res;
}


int main(void) {
	string s;

	while (cin) {
		getline(cin, s);
		if (s.empty()) break;
		s[s.length() - 1] = ',';
		
		string outer = s.substr(0, s.find(" contain") - 1);

		s.erase(0, s.find(" contain") + 8);

		vector<pair<int, string>> v;
		
		int idx = -1;
		while ((idx = s.find(",")) != -1) {
			string bag = s.substr(1, idx - 1);

			if (bag == "no other bags") {
				s.erase(0, idx + 1);
				continue;
			}

			int num = stoi(bag.substr(0, bag.find(" ")));

			bag.erase(0, bag.find(" ") + 1);
			if (bag[bag.length() - 1] == 's') bag = bag.substr(0, bag.size() - 1);

			v.push_back({num,bag});
			s.erase(0, idx + 1);
		}

		contains[outer] = v;


		// cout << outer << ": " << s << "\n";
	}

	// int ans = 0;
	// for (auto it : contains) {
	// 	cout << it.first << ": ";
	// 	for (pair<int, string> b : it.second) {
	// 		cout << "(" << b.first << ", " << b.second << ") ";
	// 	}
	// 	cout << "\n";
	// }


	cout << dfs("shiny gold bag") - 1 << "\n";
	return 0;
}
