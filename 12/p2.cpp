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

	int x2 = 10, y2 = 1;
	int dir = 1;

	int count = 0;


	while (cin >> c) {
		cin >> n;


		if (c == 'N') { // moving north
			if (dir == 0) {
				x2 += n;
			} else if (dir == 1) {
				y2 += n;
			} else if (dir == 2) {
				x2 -= n;
			} else {
				y2 -= n;
			}
		} else if (c == 'S') { // moving south
			if (dir == 0) {
				x2 -= n;
			} else if (dir == 1) {
				y2 -= n;
			} else if (dir == 2) {
				x2 += n;
			} else {
				y2 += n;
			}
		} else if (c == 'E') {
			if (dir == 0) {
				y2 -= n;
			} else if (dir == 1) {
				x2 += n;
			} else if (dir == 2) {
				y2 += n;
			} else {
				x2 -= n;
			}		
		} else if (c == 'W') {
			if (dir == 0) {
				y2 += n;
			} else if (dir == 1) {
				x2 -= n;
			} else if (dir == 2) {
				y2 -= n;
			} else {
				x2 += n;
			}
		} else if (c == 'L') {
			dir -= n/90;
			dir %= 4;
			if (dir < 0) dir += 4;
		} else if (c == 'R') {
			dir += n/90;
			dir %= 4;
		} else if (c == 'F') {

			for (int i = 0; i < n; i++) {
				if (dir == 0) { // north
					x -= y2;
					y += x2;
				} else if (dir == 1) { // east
					x += x2;
					y += y2;
				} else if (dir == 2) { // south
					x += y2;
					y -= x2;
				} else if (dir == 3) { // west
					x -= x2;
					y -= y2;
				} else {
					cout << "XD?\n";
				}
			}
		
			// cout << x << ", " << y << "\n";
		}  else {
			cout << "???\n";
		}

		// cout << count ++ << "x = " << x << " y = " << y << ": " << dir << ", x2 = " << x2 << " y2 = " << y2 << '\n';

	}

	cout << abs(x) + abs(y) << "\n";
	return 0;
}