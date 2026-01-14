#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<vector<int>> vect;
vector<vector<bool>> visited;

void bfs(int rain, int y, int x)
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

			if (yy < 0 || n <= yy || xx < 0 || n <= xx
				|| visited[yy][xx] == true || vect[yy][xx] <= rain)
				continue;

			visited[yy][xx] = true;
			Q.push(make_pair(yy, xx));
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vect.resize(n, vector<int>(n, 0));

	int Max = 0, Min = 101;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> vect[y][x];

			if (Max < vect[y][x])
				Max = vect[y][x];
			if (Min > vect[y][x])
				Min = vect[y][x];
		}
	}
	int ret = 0;
	for (int i = Min; i <= Max; i++)
	{
		int cnt = 0;
		visited.resize(n, vector<bool>(n, false));
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (vect[y][x] > i && visited[y][x] == false)
				{
					bfs(i, y, x);
					cnt++;
				}
			}
		}
		if (ret < cnt)
			ret = cnt;
		visited.clear();
	}
	if (ret == 0)
		cout << 1;
	else
		cout << ret;

	return 0;
}