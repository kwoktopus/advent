#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {
	vector<pair<string, int >> instructions;

	string s;
	int n;
	while (cin >> s >> n) {
		instructions.push_back({s, n});
	}

	bool visited[instructions.size()];
	memset(visited, false, sizeof(visited));

	int idx = 0;
	int acc = 0;
	while (idx < instructions.size()) {
		if (visited[idx]) {
			cout << acc << '\n';
			break;
		}

		visited[idx] = true;

		string cmd = instructions[idx].first;
		int val = instructions[idx].second;

		if (cmd == "acc") {
			acc += val;
			idx++;
		} else if (cmd == "jmp") {
			idx += val;
		} else if (cmd == "nop") {
			idx++;
		} else {
			cout << "fuck\n";
		}
	}


	return 0;
}
