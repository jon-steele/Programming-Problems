#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string blocks[100][2];
int alphabet[26];
bool combo[100];

vector<int> alph(int row, int side){
    vector<int> alph(26);

    //j iterates through the length of the given word on this board
    for (int j = 0; j < blocks[row][side].length(); j++){
        alph[((int) blocks[row][side].at(j)) - 97]++;
    }

    return alph;
}

int main(){

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> blocks[i][0];
        cin >> blocks[i][1];
    }

    for (int i = 0; i < n; i++){
        //We gain the frequency counter for each character for both words
        //on the ith board
        vector<int> word1 = alph(i, 0);
        vector<int> word2 = alph(i, 1);

        //next we max them together, store the result, and iterate to the next baord.
        for (int j = 0; j < 26; j++){
            alphabet[j] = alphabet[j] + max(word1[j], word2[j]);
        }
    }

    for (int i = 0; i < 26; i++){
        cout << alphabet[i] << endl;
    }
}