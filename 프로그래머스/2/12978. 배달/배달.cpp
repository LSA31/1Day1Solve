#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    priority_queue<edge, vector<edge>, greater<edge>> Q;
    vector<vector<edge>> mlist(N+1);
    vector<int> mdistance(N+1, INT_MAX);
    vector<bool> visited(N+1, false);
    
    for(int i=0; i<road.size(); i++)
    {
        mlist[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        mlist[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    Q.push(make_pair(0, 1));
    mdistance[1] = 0;
    
    while(!Q.empty())
    {
        edge now = Q.top();
        Q.pop();
        
        int now_index = now.second;
        
        if(visited[now_index])
            continue;
        
        visited[now_index] = true;
        
        for(int i=0; i<mlist[now_index].size(); i++)
        {
            edge next = mlist[now_index][i];
            int next_index = next.first;
            int next_value = next.second;
            
            if(mdistance[next_index] > mdistance[now_index] + next_value)
            {
                mdistance[next_index] = mdistance[now_index] + next_value;
                Q.push(make_pair(mdistance[next_index], next_index));
            }
        }
    }
    for(int i=1; i<N+1; i++)
    {
        if(mdistance[i] <= K)
            answer++;
    }

    return answer;
}