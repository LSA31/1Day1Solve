#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visited;

void DFS(int node, vector<vector<int>> computers)
{
    visited[node] = true;
    
    for(int i=0; i<computers[node].size(); i++)
    {
        if((!visited[i]) && computers[node][i] == 1)
            DFS(i, computers);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.resize(n, false);
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            DFS(i, computers);
            answer++;
        }
    }
    
    return answer;
}