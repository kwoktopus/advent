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
			string value = pair.substr(pair.find(":") + 1);

			bool valid = true;
			if (key == "byr") {
				for (char c : value) {
					if (c < '0' || c > '9') { 
						valid = false;
						break;
					}
				}

				if (valid) {
					int n = stoi(value);
					valid = n >= 1920 && n <= 2002;
				}
			} else if (key == "iyr") {
				for (char c : value) {
					if (c < '0' || c > '9') { 
						valid = false;
						break;
					}
				}

				if (valid) {
					int n = stoi(value);
					valid = n >= 2010 && n <= 2020;
				}
			} else if (key == "eyr") {
				for (char c : value) {
					if (c < '0' || c > '9') { 
						valid = false;
						break;
					}
				}

				if (valid) {
					int n = stoi(value);
					valid = n >= 2020 && n <= 2030;
				}
			} else if (key == "hgt") {
				if (value.length() < 3) {
					valid = false;

				} else {
					string suffix = value.substr(value.length() - 2);
					value.erase(value.length() - 2, value.length());

					valid = suffix == "in" || suffix == "cm";

					for (char c : value) {
						if (c < '0' || c > '9') { 
							valid = false;
							break;
						}
					}

					if (valid) {
						int n = stoi(value);
						if (suffix == "cm") valid = n >= 150 && n <= 193;
						if (suffix == "in") valid = n >= 59 && n <= 76; 
					}
				}
			} else if (key == "hcl") {
				valid = value[0] == '#';
				valid = value.length() == 7;

				for (int i = 1; i < 7; i++) {
					char c = value[i];
					if ((c < '0' || c > '9') && (c < 'a' || c > 'f')) {
						valid = false;
						break;
					}
				}

			} else if (key == "ecl") {
				valid = (value == "amb" || value == "blu" || value == "brn" || value == "grn" || value == "gry" || value == "hzl" || value == "oth");
			} else if (key == "pid") {
				for (char c : value) {
					if (c < '0' || c > '9') { 
						valid = false;
						break;
					}
				}

				if (valid) {
					valid = value.length() == 9;
				}
			} else if (key == "cid") {
				// nothing
			} else {
				cout << "wrong key?\n";
			}

			if (valid) m[key] = value;	
			// else cout << key << " -> " << value << " is invalid\n";
		}
	}

	cout << ans << "\n";

	return 0;
}


