#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<bool>> visited;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs(int y, int x)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!Q.empty())
	{
		int now[2] = { Q.front().first, Q.front().second };
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int yy = now[0] + dy[i];
			int xx = now[1] + dx[i];

			if (yy < 0 || N <= yy || xx < 0 || M <= xx  // 범위를 벗어나거나 이미 방문했거나 값이 0이라면
				|| visited[yy][xx] == true || maze[yy][xx] == 0)
				continue;

			Q.push(make_pair(yy, xx));
			visited[yy][xx] = true;
			maze[yy][xx] = maze[now[0]][now[1]] + 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	maze.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));
	for (int y = 0; y < N; y++)
	{
		string str = "";
		cin >> str;

		for (int x = 0; x < M; x++)
		{
			maze[y][x] = str[x] - '0';
		}
	}
	bfs(0, 0);

	cout << maze[N - 1][M - 1];

	return 0;
}