#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> ret;

void dfs(int node)
{
	visited[node] = true;
	ret.push_back(node);

	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];

		if (!visited[next])
			dfs(next);
	}
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		ret.push_back(node);

		for (int i = 0; i < graph[node].size(); i++)
		{
			int next = graph[node][i];

			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(v);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << ' ';
	cout << '\n';

	ret.clear();
	visited.assign(n + 1, false);

	bfs(v);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << ' ';
}