#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
	
int main(void) {
	string s;
	unordered_map<string, string> m;
	unordered_set<string> st;

	st.insert("byr");
	st.insert("iyr");
	st.insert("eyr");
	st.insert("hgt");
	st.insert("hcl");
	st.insert("ecl");
	st.insert("pid");
	// st.insert("cid");

	int ans = 0;
	while (cin) {
		getline(cin, s);
		if (s.empty()) {
			bool valid = true;
			for (string s1 : st) {
				if (m.find(s1) == m.end()) {
					valid = false;
					break;
				}
			}

			if (valid) ans ++;


			m.clear();
			continue;
		}
		s += " ";
		int idx;
		while ((idx = s.find(" ")) != -1) {
			string pair = s.substr(0, idx);
			s.erase(0, idx + 1);

			string key = pair.substr(0, pair.find(":"));
			string value = pair.substr(pair.find(":" + 1));

			m[key] = value;	
		}
	}

	cout << ans << "\n";

	return 0;
}