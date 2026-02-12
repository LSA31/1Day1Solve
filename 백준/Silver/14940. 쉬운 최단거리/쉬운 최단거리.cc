#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> vect;
vector<vector<int>> ret;
vector<vector<bool>> visited;
int n, m;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void BFS(int yy, int xx)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(yy, xx));
	visited[yy][xx] = true;
	ret[yy][xx] = 0;

	int cnt = 0;
	while (!Q.empty())
	{
		int now[2] = { Q.front().first, Q.front().second };
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int y = now[0] + dy[i];
			int x = now[1] + dx[i];

			if (y < 0 || n <= y || x < 0 || m <= x
				|| visited[y][x] == true || vect[y][x] == 0)
				continue;

			Q.push(make_pair(y, x));
			visited[y][x] = true;
			ret[y][x] = ret[now[0]][now[1]] + 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vect.resize(n, vector<int>(m));
	ret.resize(n, vector<int>(m, -1));
	visited.resize(n, vector<bool>(m, false));

	int startY = 0, startX = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> vect[y][x];

			if (vect[y][x] == 2)
			{
				startY = y;
				startX = x;
			}
			if (vect[y][x] == 0)
				ret[y][x] = 0;
		}
	}
	BFS(startY, startX);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cout << ret[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}