#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void print(const vector<string> &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].length(); j++) {
			cout << v[i][j];
		}

		cout << "\n";
	}
}

int main(void) {
	vector<string> grid;
	string s;
	int n = 0;

	while (cin >> s) {
		grid.push_back(s);
		for (char c : s) {
			if (c == '#') n++;
		}
	}

	while (true) {
		int prev = n;

		n = 0;
		vector<string> grid2;
		for (int i = 0; i < grid.size(); i++) {
			string s2 = "";
			for (int j = 0; j < grid[i].length(); j++) {

				// cout << i << ", " << j << '\n';
				s2 += grid[i][j];

				if (grid[i][j] == '.') continue;

				int filled = 0;
				int empty = 0;
				for (int r = -1; r <= 1; r++) {
					for (int c = -1; c <= 1; c++) {
						if (r == 0 && c == 0) continue;
						int row = i;
						int col = j;

						while (true) {
							row += r;
							col += c;

							if (row < 0 || row >= grid.size() || col < 0 || col >= grid[i].size()) break;

							if (grid[row][col] == 'L') {
								empty++;
								break;
							}

							if (grid[row][col] == '#') {
								filled++;
								break;
							}
						}
					}
				}

				if (grid[i][j] == 'L' && filled == 0) s2[j] = '#';
				if (grid[i][j] == '#' && filled >= 5) s2[j] = 'L';

				if (s2[j] == '#') n++;
			}
			grid2.push_back(s2);
		}


		grid = grid2;
		// cout << prev << ", " << n << "\n";
		if (prev == n) break;
	}

	cout << n << '\n';


	return 0;
}
