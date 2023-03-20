// http://www.usaco.org/index.php?page=viewproblem2&cpid=788
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<vector<pair<int, int> > > adjacencies;
int videos;
bool visited[5001];

// dfs will recurse through our tree of adjacencies, iterating int videos when a compatable video is found. 
void dfs(int video, int relevance){
    visited[video] = true;
    videos++;
    for (int i = 0; i < adjacencies[video].size(); i++)
    {
        // If the adjacent video has not been visited, and it has a compatable relevance, we can dfs onto it.
        if (visited[adjacencies[video][i].first] == 0 && adjacencies[video][i].second >= relevance)
            dfs(adjacencies[video][i].first, relevance);
    }
}

int main()
{
    // Inputs
    int n, questions_size, p, q, r;
    cin >> n;
    cin >> questions_size;
    adjacencies.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> p >> q >> r;
        adjacencies[p].push_back(make_pair(q, r));
        adjacencies[q].push_back(make_pair(p, r));
    }

    pair<int, int> questions[questions_size];
    memset(questions, 0, sizeof(questions));
    for (int i = 0; i < questions_size; i++)
    {
        cin >> p >> q;
        questions[i] = make_pair(p, q); // first is the relevance, second is the video.
    }

    // For each question, we dfs to find the number of relevant videos
    for (int i = 0; i < questions_size; i++)
    {
        videos = 0;
        memset(visited, 0, sizeof(visited));

        dfs(questions[i].second, questions[i].first);
        cout << videos - 1 << endl;
    }
    
    return 0;
}