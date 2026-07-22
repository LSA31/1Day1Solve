#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> edge_cnt;  // 해당 노드까지의 거친 간선 개수

void BFS()
{
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for(int i=0; i<graph[now].size(); i++)
        {
            int next = graph[now][i];
            
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
                
                edge_cnt[next] = edge_cnt[now] + 1;  // 이전 노드의 간선 개수에서 하나 추가
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    graph.assign(n+1, {});
    visited.assign(n+1, false);
    edge_cnt.assign(n+1, 0);
    
    for(int i=0; i<edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    for(int i=1; i<n+1; i++)
        sort(graph[i].begin(), graph[i].end());
    
    BFS();
    
    int MAX = 0;
    for(int i=0; i<n+1; i++)
    {
        if(MAX < edge_cnt[i])
            MAX = edge_cnt[i];
    }
    for(int i=0; i<n+1; i++)
    {
        if(edge_cnt[i] == MAX)
            answer++;
    }
    
    return answer;
}