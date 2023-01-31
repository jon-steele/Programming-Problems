#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string cows[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<pair<int, int> > pairs;
vector<int> pairedCows;

// Bessie = 0
// Buttercup = 1
// Belinda = 2
// Beatrice = 3
// Bella = 4
// Blue = 5
// Betsy = 6
// Sue = 7

int cowNumber(string name){

    if (name == "Bessie")
        return 0;
    else if (name == "Buttercup")
        return 1;
    else if (name == "Belinda")
        return 2;
    else if (name == "Beatrice")
        return 3;
    else if (name == "Bella")
        return 4;
    else if (name == "Blue")
        return 5;
    else if (name == "Betsy")
        return 6;
    else if (name == "Sue")
        return 7;
    else {
        return 999;
    }
}

int main() {

    string foo, cow1, cow2;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> cow1 >> foo >> foo >> foo >> foo >> cow2;
        if(cow1 > cow2){
            pairs.push_back(make_pair(cowNumber(cow2), cowNumber(cow1)));
        }
        else{
            pairs.push_back(make_pair(cowNumber(cow1), cowNumber(cow2)));
        }
        pairedCows.push_back(cowNumber(cow1));
        pairedCows.push_back(cowNumber(cow2));

    }

    //Now we have all the cows we need to print, along with the ones that are now pairs. 

}