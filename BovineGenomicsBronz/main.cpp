#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<string> spottyDna;
vector<string> nonSpottyDna;

void dnaSpotty(int col, int *array){

    for (int i = 0; i < n; i++){
        if (spottyDna[i].at(col) == 'A')
            array[0] = 1;
        else if (spottyDna[i].at(col) == 'T')
            array[1] = 1;
        else if (spottyDna[i].at(col) == 'C')
            array[2] = 1;
        else
            array[3] = 1;
    }
}

void dnaNonSpotty(int col, int *array){

    for (int i = 0; i < n; i++){
        if (nonSpottyDna[i].at(col) == 'A')
            array[0] = 1;
        else if (nonSpottyDna[i].at(col) == 'T')
            array[1] = 1;
        else if (nonSpottyDna[i].at(col) == 'C')
            array[2] = 1;
        else
            array[3] = 1;
    }
}

bool split(int column){

    //These boolean columns hold true or false for each ATCG
    int spottyColumnDNA[] = {0,0,0,0};
    dnaSpotty(column, spottyColumnDNA);
    int nonSpottyColumnDNA[] = {0,0,0,0};
    dnaNonSpotty(column, nonSpottyColumnDNA);

    for (int i = 0; i < 4; i++){
        if (spottyColumnDNA[i] == 1 && nonSpottyColumnDNA[i] == 1)
            return false;
    }
    return true;
}

int main(){

    cin >> n >> m;
    string line;

    for (int i = 0; i < n; i++){
        cin >> line;
        spottyDna.push_back(line);
    }

    for (int i = 0; i < n; i++){
        cin >> line;
        nonSpottyDna.push_back(line);
    }

    int counter = 0;

    for (int i = 0; i < m; i++){

        if (split(i)){
            counter++;
        }
    }
    cout << counter << endl;
}