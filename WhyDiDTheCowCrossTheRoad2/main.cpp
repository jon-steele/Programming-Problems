#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("circlecross.in","r",stdin);
	string crossingPoints;
	cin >> crossingPoints;

	int crossing_pairs = 0;
	// Iterate through all characters of the string
	for (int a = 0; a < crossingPoints.size(); a++) {
		for (int b = a + 1; b < crossingPoints.size(); b++) {
			for (int c = b + 1; c < crossings.size(); c++) {
				for (int d = c + 1; d < crossings.size(); d++) {
					/* 
					 * If we find two entry/exit paths such that a < b < c < d, 
					 * the path of cows crossing (a, c) and (b, d) must intersect,
					 * so we have a crossing pair
					 */
					crossing_pairs += (
						crossings[a] == crossings[c] &&
						crossings[b] == crossings[d]
					);
				}
			}
		}
	}
	
	freopen("circlecross.out", "w", stdout);
	cout << crossing_pairs << endl;
}