#include <iostream>
using namespace std;


const int MAX_N = 1e5;

pair<long long, long long> intervals[MAX_N];

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}
	sort(intervals, intervals + m);

	long long lo = 0;
	long long hi = intervals[m - 1].second - intervals[0].first + 1;
	while (lo < hi) {
		long long mid = lo + (hi - lo + 1) / 2;
		int count = 1;
		int intervalCount = 0;
		long long current = intervals[0].first;

		// try to fit the next cow into the earliest patch of grass that's available
		while ((current + mid) < intervals[m - 1].second) {
			while (current + mid > intervals[intervalCount].second) {
				intervalCount++;
			}
			current = max(intervals[intervalCount].first, current + mid);
			count++;
			if (count == n) break;
		}

		if (count >= n) lo = mid;
		else hi = mid - 1;
	}
	cout << lo << '\n';
}