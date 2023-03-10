//http://www.usaco.org/index.php?page=viewproblem2&cpid=965
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
vector<pair<string, string> > pairs;
vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int cowIndex(string name){
    for (int i = 0; i < 8; i++){
        if (cows[i] == name)
            return i;
    }

    return 999;
}

//Checks if this current permutation matches the given pairings
bool matchesPairs(){
    //For each pairing, we check if it is satisfied in the permutation
    for (int i = 0; i < pairs.size(); i++){

        //For each condition, we hav a flag. It is assumed false, until proven true.
        bool conditionFlag = false;
        string a = pairs[i].first;
        string b = pairs[i].second;

        //For each pair in cows
        for (int i = 0; i < 7; i++){
            //Check if a and b are next to eachother for each i
            if ((cows[i] == a && cows[i + 1] == b) || (cows[i] == b && cows[i + 1] == a)){
                conditionFlag = true;
                break;
            }

            //If we reach the end of this loop and the condition was not met, we return false.
            if(i == 6 && conditionFlag == false)
                return false;
        }
    }

    return true;
}

int main() {
    //If submitting on usaco, you need to uncomment this
    // freopen("lineup.in", "r", stdin);
	// freopen("lineup.out", "w", stdout);
    string foo, cow1, cow2;

    cin >> n;

    sort(cows.begin(), cows.end());


    for (int i = 0; i < n; i++){
        cin >> cow1 >> foo >> foo >> foo >> foo >> cow2;
        if(cow1 > cow2){
            pairs.push_back(make_pair((cow2), (cow1)));
        }
        else{
            pairs.push_back(make_pair((cow1), (cow2)));
        }
    }

    int count = 0;

    //We will traverse through all permutations and check if each pair is satisfied.
    do{
        if(matchesPairs() == true)
            break;
    } while (next_permutation(cows.begin(), cows.end()));

    for (int i = 0; i < 8; i++){
        cout << cows[i] << endl;
    }
}