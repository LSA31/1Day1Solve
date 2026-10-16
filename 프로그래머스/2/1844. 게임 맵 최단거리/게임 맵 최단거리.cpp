#include<vector>
#include <queue>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<bool>> visited;

int BFS(int n, int m, vector<vector<int>> maps)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    visited[0][0] = true;
    
    vector<vector<int>> dist(n, vector<int> (m, 0));
    dist[0][0] = 1;
    while(!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        
        Q.pop();
        
        if(y == n-1 && x == m-1)
            return dist[y][x];
        
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if((!(ny>=0 && ny<n && nx>=0 && nx<m)) || maps[ny][nx] == 0)
                continue;
        
            if(!visited[ny][nx])
            {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;
                Q.push(make_pair(ny, nx));
            }
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    visited.assign(n, vector<bool> (m, false));
    
    answer = BFS(n, m, maps);
    
    return answer;
}