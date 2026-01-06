#include <iostream>
#include <vector>
using namespace std;

int n, s, e, m;
vector<vector<int>> graph;
vector<bool> visited;
int cnt;
bool flag;

void dfs(int node)
{
	if (node == e)
	{
		cout << cnt;
		flag = true;
		return;
	}

	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{	
		if (visited[graph[node][i]] == true)
			continue;

		cnt++;
		dfs(graph[node][i]);
		cnt--;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s >> e >> m;

	graph.resize(n + 1, vector<int>(0));
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x = 0, y = 0;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(s);

	if (!flag)
		cout << -1;

	return 0;
}