//http://www.usaco.org/index.php?page=viewproblem2&cpid=573
//Test case:
// 4 1 8 4 3
// Output: 2.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bessie_points = 0;
vector<int> elise_cards;
vector<int> bessie_cards;
vector<int> bessie_hi_cards;
vector<int> bessie_low_cards;
int n, card;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> card;
        elise_cards.push_back(card);
    }

    for (int i = 1; i < 2 * n; i++)
    {
        bool bessie_card = true;
        for (int j = 0; j < n; j++)
        {
            if (elise_cards[j] == i)
            {
                bessie_card = false;
                break;
            }
        }
        if (bessie_card == true)
        {
            bessie_cards.push_back(i);
        }
                
    }

    sort(bessie_cards.begin(), bessie_cards.end());
    reverse(bessie_cards.begin(), bessie_cards.end());

    for (int i = 0; i < n / 2; i++)
    {
        bessie_hi_cards.push_back(bessie_cards[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        bessie_low_cards.push_back(bessie_cards[n - 1 - i]);
    }

    // I rearrange the cards from worst to best
    reverse(bessie_hi_cards.begin(), bessie_hi_cards.end());
    reverse(bessie_low_cards.begin(), bessie_low_cards.end());

    // Lets simulate this greedy search using two for loops

    // One for the first N / 2 cards (highest wins)
    
    for (int i = 0; i < n / 2; i++)
    {
        bool point = false;
        // Search for the minimum highest card above elise's, then pop
        // if none are found, match with bessie's worst high card (the min)
        for (int j = 0; j < bessie_hi_cards.size(); j++)
        {
            if (bessie_hi_cards[j] > elise_cards[i])
            {
                // If we've found a card that is better, we use it.
                point = true;
                bessie_points++;
                bessie_hi_cards.erase(bessie_hi_cards.begin() + j);
                break;
            }
        }
        if (point == false)
        {
            // If bessie didn't get the point, we need to pop her worst card
            bessie_hi_cards.erase(bessie_hi_cards.begin());
        }  
    }

    // One for the second N / 2 cards (lowest wins)

    for (int i = n / 2; i < n; i++)
    {
        bool point = false;
        // Search for the minimum lowest card below elise's, then pop
        // if none are found, match with bessie's worst low card (the max)
        for (int j = 0; j < bessie_low_cards.size(); j++)
        {
            if (bessie_low_cards[j] < elise_cards[j])
            {
                // If we've found a card that is better, we use it.
                point = true;
                bessie_points++;
                bessie_low_cards.erase(bessie_low_cards.begin() + j);
                break;
            }
        }
        if (point == false)
        {
            // If bessie didn't get the point, we need to pop her worst card
            bessie_low_cards.erase(bessie_low_cards.begin());
        }  
    }

    cout << bessie_points << endl;
    
    return 0;
}