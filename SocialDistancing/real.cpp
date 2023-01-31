#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
pair<long long, long long> patches[200000];

//x = distance;
bool check(long long x){
	long long ni = 1;	//ni keeps track of cows
	long long mi = 0; //mi keeps track of patches
	long long firstPosOfPatch;
	long long lastPos = 0 - x;
	long long counter = 0;

	//We iterate through the patches.
	while (mi < m && ni != n){

		//Either the first cow will fall into the next patch
		if (lastPos + x >= patches[mi].first && lastPos + x <= patches[mi].second){
			firstPosOfPatch = lastPos + x;
			lastPos = firstPosOfPatch;
			counter = 0;
		}

		//or it will fall short of the next patch, so we need to move him to the first posiition.
		else{
			firstPosOfPatch = patches[mi].first;
			lastPos = firstPosOfPatch;
			counter = 0;
		}

		//in each patch, we test if adding a cow will push us beyond the limits of the patch,
		//given our distancing restrictions.
		while (patches[mi].second >= firstPosOfPatch + (counter * x)){
			lastPos = firstPosOfPatch + (counter * x);
			counter++;
			ni++;
		}

		//once we can no longer add cows to the current patch, me must iterate on to the next.
		mi++;
		if (ni == n)
			break;
	}

	return (ni == n);

	// while ((current + mid) < intervals[m - 1].second) {
	// 	while (current + mid > intervals[intervalCount].second) {
	// 		intervalCount++;
	// 	}
	// 	current = max(intervals[intervalCount].first, current + mid);
	// 	count++;
	// 	if (count == n) break;
	// }
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> patches[i].first >> patches[i].second;
	}

	sort(patches, patches + m);

	long long low = 0;
	long long high = patches[m - 1].second - patches[0].first + 1;
	long long mid;

	while (low < high) {
		mid = low + high / 2;

		if (check(mid)) 
			low = mid;
		else 
			high = mid - 1;
	}
	cout << low << endl;
}