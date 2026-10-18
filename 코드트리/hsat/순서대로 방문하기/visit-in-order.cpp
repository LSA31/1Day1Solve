#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int N, M;
vector<vector<int>> road;
vector<pair<int, int>> check;
vector<vector<bool>> visited;

void DFS(int& answer, int y, int x, int next)
{
    for(int i=1; i<M; i++)
    {
        if((check[i].first == y) && (check[i].second == x))
        {
            if(i != next)
                return;

            next++;
            break;
        }
    }
    if(next == M)
    {
        answer++;
        return;
    }    

    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=N || nx<0 ||nx>=N) continue;
        if((!visited[ny][nx]) && (road[ny][nx] == 0))
        {
            visited[ny][nx] = true;
            DFS(answer, ny, nx, next);

            visited[ny][nx] = false;
        }
    }
}
int main()
{
    cin >> N >> M;
    road.resize(N, vector<int> (N, 0));
    check.resize(M);
    visited.resize(N, vector<bool> (N, false));

    for(int y=0; y<N; y++)
    {
        for(int x=0; x<N; x++)
        {
            cin >> road[y][x];
        }
    }
    for(int i=0; i<M; i++)
    {
        cin >> check[i].first >> check[i].second;
        check[i].first--;
        check[i].second--;
    }
    
    visited[check[0].first][check[0].second] = true;
    int answer = 0;
    DFS(answer, check[0].first, check[0].second, 1);
    cout << answer;

    return 0;
}