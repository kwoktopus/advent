#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

	int n;
	string s;
	cin >> n >> s;

	vector<int> times;
	s += ',';

	int idx = -1;
	while ((idx = s.find(",")) != -1) {
		string sub = s.substr(0, idx);
		s.erase(0, idx + 1);

		if (sub != "x") times.push_back(stoi(sub));
	}
	int best = 123456789;
	int id = -1;

	for (int t : times) {
		int departTime = ceil(1.0*n/t) * t;

		if (departTime - n < best) {
			best = departTime - n;
			id = t;
		}
	}

	cout << best * id << "\n";

	return 0;
}
