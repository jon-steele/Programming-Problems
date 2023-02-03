#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > coords;
vector<pair<char, int> > instructions;
int totalTime, n;

//duplicate is going to take the last coordinate pushed onto coord, and iterate through the beginning to see if there is a match. if there is, we return the index.
int duplicateIndex(){
    int x = coords.back().first;
    int y = coords.back().second;

    for (int i = coords.size() - 2; i >= 0; i--){
        if (x == coords.at(i).first && y == coords.at(i).second)
            return i;
    }
//If none found, return 0
return 0;
}

int main() {


    int minimum = 9999999;
    totalTime = 0;
    char direction;
    int time;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> direction >> time;
        totalTime = totalTime + time;

        instructions.push_back(make_pair(direction, time));
    }

    coords.push_back(make_pair(0,0));
    int t = 0;
    pair<char, int> instruction;

    while (t < totalTime){
        
        instruction = (pair<char, int>) instructions.front();
        instructions.erase(instructions.begin());
        time = instruction.second;

        for (int i = 0; i < time; i++){
            switch (instruction.first){
                case 'N':
                    coords.push_back(make_pair(coords.back().first, coords.back().second + 1));
                    break;
                case 'E':
                    coords.push_back(make_pair(coords.back().first + 1, coords.back().second));
                    break;
                case 'S':
                    coords.push_back(make_pair(coords.back().first, coords.back().second - 1));
                    break;
                case 'W':
                    coords.push_back(make_pair(coords.back().first - 1, coords.back().second));
                    break;
                default:
                    cout << "error";
                    break;
            }

            //Now, after we push the coordinate onto the stack, we need to check if we have been here before.
            if (duplicateIndex() > 0){
                minimum = min(minimum, (t - duplicateIndex() + 1));
            }

            t++;
        }
    }
        if (minimum == 9999999)
            cout << -1 << endl;
        else
            cout << minimum << endl;
}