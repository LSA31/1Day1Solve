#include <iostream>
#include <vector>
using namespace std;

int M, N, K;
vector<vector<int>> graph;

int dy[4] = { -1, 0, 1, 0 };  // 상하좌우
int dx[4] = { 0,-1, 0, 1 };

void dfs(int y, int x)
{
	// 탐색한 곳을 0으로 바꿔줌
	graph[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];

		// 범위를 초과하거나 이동할 위치에 배추가 없다면
		if ((yy < 0 || N <= yy) || (xx < 0 || M <= xx)
			|| graph[yy][xx] == 0)
			continue;

		dfs(yy, xx);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case = 0;
	cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		cin >> M >> N >> K;

		graph.clear();
		graph.resize(N, vector<int>(M, 0));
		for (int i = 0; i < K; i++)
		{
			int y = 0, x = 0;
			cin >> x >> y;

			graph[y][x] = 1;
		}

		int cnt = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (graph[y][x] == 1)
				{
					dfs(y, x);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}