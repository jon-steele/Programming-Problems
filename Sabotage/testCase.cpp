#include <iostream>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int n = stoi(argv[1]);
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        cout << dist(gen) << endl;
    }
    // sort(nums, nums + n);
    return 0;
}
