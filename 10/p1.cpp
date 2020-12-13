#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	vector<int> v;

	while (cin >> n) {
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	int prev = 0;
	int one = 0;
	int three = 1;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] - prev == 1) one ++;
		else if (v[i] - prev == 3) three ++;

		prev = v[i];		
	}

	cout << one << " * " << three << " = " << one*three << "\n";

	return 0;	
}
