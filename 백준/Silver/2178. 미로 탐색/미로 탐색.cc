#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int arr[101][101];
bool visited[101][101] = { false };
int n, m;

void BFS(int i, int j)
{
	queue<pair<int, int>> Q;

	Q.push(make_pair(i, j));
	visited[i][j] = true;

	while (!Q.empty())
	{
		int now[2];
		now[0] = Q.front().first;
		now[1] = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++)
		{
			int y = now[0] + dx[k];
			int x = now[1] + dy[k];

			if (0 <= y && y < n && 0 <= x && x < m)
			{
				if (arr[y][x] != 0 && !visited[y][x]) // 경로가 0이 아니고 방문한 적 없는 곳일 때
				{
					visited[y][x] = true;
					arr[y][x] = arr[now[0]][now[1]] + 1;
					Q.push(make_pair(y, x));
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < m; x++)
		{
			arr[y][x] = str[x] - '0';
		}
	}
	BFS(0, 0);
	cout << arr[n - 1][m - 1];
}