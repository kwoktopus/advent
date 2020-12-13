#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int left,right;
	int count = 0;

	while (cin >> left) {
		char c,dummy;
		string pw;
		cin >> dummy >> right >> c >> dummy >> pw;

		left--;
		right--;
		
		if (left < 0 || left > pw.size() || right < 0 || right >= pw.size()) continue;		

		if (pw[left] == c && pw[right] != c) count++;
		else if (pw[right] == c && pw[left] != c) count ++;
	}

	cout << count;

	return 0;
}
