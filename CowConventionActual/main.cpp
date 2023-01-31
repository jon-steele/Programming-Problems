#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using std::endl;
using std::vector;

int n, m, c;
vector<int> arrivals;

bool validate(int k) {
	int bus = 0;   // number of buses needed
	int cow = 0;   // current cow
	int lcow = 0;  // earliest cow on this bus

	while (cow < n) {
		if (cow == lcow) {
			bus++;
		}

		// can't satisfy time constraint by adding this cow
		if (arrivals[cow] - arrivals[lcow] > k) {
			lcow = cow;
		// can't fit this cow in the bus
		} else if (cow - lcow + 1 == c) {
			lcow = ++cow;
		// add this cow to the current bus
		} else {
			cow++;
		}
	}
	return bus <= m;
}

int main() {
	
	std::cin >> n >> m >> c;
	arrivals.resize(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> arrivals[i];
	}

	// sort by arrival time to process cows in order
	sort(arrivals.begin(), arrivals.end());

	int lo = 0;
	int hi = arrivals[n - 1] - arrivals[0];

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
	
		if (validate(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	std::cout << lo << endl;
}