#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int y;
    int x;
    int t;
    int dir;
};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
//위0, 왼쪽1, 아래2, 오른쪽3
vector<vector<int>> signal =
{
    {},
    {3,0,2},
    {0,1,3},
    {1,0,2},
    {2,1,3},
    {3,0},
    {0,1},
    {1,2},
    {2,3},
    {3,2},
    {0,3},
    {1,0},
    {2,1}
};

int N, T;
int road[1001][1001][4];
bool visited[1001][1001];
bool state_visited[1001][1001][4][4];

int BFS()
{
    queue<node> Q;
    Q.push({0, 0, 0, 0});

    visited[0][0] = true;
    state_visited[0][0][0][0] = true;

    int answer = 1;

    while(!Q.empty())
    {
        node now = Q.front();
        Q.pop();

        int y = now.y;
        int x = now.x;
        int t = now.t;
        int dir = now.dir;

        if(t >= T)
            return answer;

        int now_signal = road[y][x][t%4];

        if(dir != signal[now_signal][0])
            continue;

        for(int i=0; i<signal[now_signal].size(); i++)
        {
            int next = signal[now_signal][i];

            int ny = y + dy[next];
            int nx = x + dx[next];

            if(ny<0 || ny>=N || nx<0 || nx>=N)
                continue;

            int nt = t + 1;

            if(state_visited[ny][nx][nt%4][next])
                continue;

            state_visited[ny][nx][nt%4][next] = true;
            Q.push({ny, nx, nt, next});

            if(!visited[ny][nx])
            {
                visited[ny][nx] = true;
                answer++;
            }
        }
    }
    return answer;
}
int main() {
    
    cin >> N >> T;
    for(int y=0; y<N; y++)
    {
        for(int x=0; x<N; x++)
        {
            for(int t=0; t<4; t++)
            {
                cin >> road[y][x][t];
            }
        }
    }

    cout << BFS();

    return 0;
}