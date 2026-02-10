#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<vector<char>> campus;
vector<vector<bool>> visited;
int n, m, cnt;

void dfs(int yy, int xx)
{
	if (campus[yy][xx] == 'P')
		cnt++;

	visited[yy][xx] = true;

	for (int i = 0; i < 4; i++)
	{
		int y = yy + dy[i];
		int x = xx + dx[i];

		if ((y >= 0 && y < n) && (x >= 0 && x < m) &&
			!visited[y][x] && campus[y][x] != 'X')
			dfs(y, x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	campus.resize(n, vector<char>(m, ' '));
	visited.resize(n, vector<bool>(m, false));
	int Iy = 0, Ix = 0;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		cin >> str;

		for (int j = 0; j < m; j++)
		{
			campus[i][j] = str[j];

			if (str[j] == 'I')
			{
				Iy = i;
				Ix = j;
			}
		}
	}
	dfs(Iy, Ix);

	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;

	return 0;
}