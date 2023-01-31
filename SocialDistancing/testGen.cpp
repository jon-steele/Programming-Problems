#include <iostream>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
    random_device rd;
    mt19937 gen(rd());

    int n = stoi(argv[1]);
    int m = 0;

    vector<pair<int, int> > grass;
    uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < m; i++) {
        int roll = dist(gen);
        if (roll < 8){
            pair<int, int> x = make_pair(i, i + roll);
            grass.push_back(x);
            i = i + roll;
            m++;
        }
    }

    cout << n << " " << m << endl;

    for (int i = 0; i < grass.size(); i++){
        cout << grass[i].first << " " << grass[i].second << endl;
    }
}
