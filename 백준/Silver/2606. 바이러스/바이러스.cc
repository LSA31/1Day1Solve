#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		if (!visited[next])
			dfs(next);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	graph.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (visited[i])
			cnt++;
	}
	cout << cnt;
}