#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> home;
vector<vector<bool>> visited;
int n;
int dy[4] = { -1,1,0,0 };  // 상하좌우
int dx[4] = { 0,0,-1,1 };

int bfs(int y, int x)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(y, x));
	visited[y][x] = true;

	int cnt = 1;
	while (!Q.empty())
	{
		int now[2] = { Q.front().first, Q.front().second };
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int yy = now[0] + dy[i];
			int xx = now[1] + dx[i];

			if (yy < 0 || n <= yy || xx < 0 || n <= xx
				|| home[yy][xx] == 0 || visited[yy][xx] == true)
				continue;

			Q.push(make_pair(yy, xx));
			visited[yy][xx] = true;
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	home.resize(n, vector<int>(n, 0));
	visited.resize(n, vector<bool>(n, false));
	for (int y = 0; y < n; y++)
	{
		string str = "";
		cin >> str;
		for (int x = 0; x < n; x++)
		{
			home[y][x] = str[x] - '0';
		}
	}

	vector<int> cnt;  
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (home[y][x] == 1 && visited[y][x] == false)
				cnt.push_back(bfs(y, x));
		}
	}

	cout << cnt.size() << '\n';
	
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i < cnt.size(); i++)
		cout << cnt[i] << '\n';

	return 0;
}