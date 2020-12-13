#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	char c;
	int n;
	
	int x = 0, y = 0;
	int dir = 1;

	while (cin >> c >> n) {
		if (c == 'N') {
			y += n;
		} else if (c == 'E') {
			x += n;
		} else if (c == 'S') {
			y -= n;
		} else if (c == 'W') {
			x -= n;
		} else if (c == 'L') {
			dir -= n/90;
			dir %= 4;
			if (dir < 0) dir += 4;
		} else if (c == 'R') {
			dir += n/90;
			dir %= 4;
		} else if (c == 'F') {
			if (dir == 0) {
				y += n;
			} else if (dir == 1) {
				x += n;
			} else if (dir == 2) {
				y -= n;
			} else if (dir == 3) {
				x -= n;
			}
		}
	}
	
	cout << abs(x) + abs(y) << "\n";

	return 0;
}