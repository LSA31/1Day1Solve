#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> ret;
vector<bool> visited;
int n;

void dfs(int before, int now)
{
	visited[now] = true;
	ret[now] = before;

	for (int i = 0; i < graph[now].size(); i++)
	{
		int next = graph[now][i];

		if (!visited[next])
			dfs(now, next);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	graph.resize(n + 1);
	visited.resize(n + 1, false);
	ret.resize(n + 1, 0);
	for (int i = 1; i < n; i++)
	{
		int index = 0, val = 0;
		cin >> index >> val;

		graph[index].push_back(val);
		graph[val].push_back(index);
	}
	dfs(0, 1);

	for (int i = 2; i <= n; i++)
		cout << ret[i] << '\n';
}