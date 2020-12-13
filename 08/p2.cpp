#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int acc;
vector<pair<string, int >> instructions;

bool inf() {	
	bool visited[instructions.size()];
	memset(visited, false, sizeof(visited));
	int idx = 0;
	acc = 0;

	while (idx < instructions.size()) {
		if (visited[idx]) return true;
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

	return false;
}


int main(void) {

	string s;
	int n;
	while (cin >> s >> n) {
		instructions.push_back({s, n});
	}

	for (int i = 0; i < instructions.size(); i++) {
		string cmd = instructions[i].first;
		if (cmd == "acc") continue;
		if (cmd == "jmp") instructions[i].first = "nop";
		else if (cmd == "nop") instructions[i].first = "jmp";

		if (!inf()) {
			cout << "changing instruction " << i << "\n";
			cout << acc << "\n";
			break;
		}

		instructions[i].first = cmd;
	}


	return 0;
}
