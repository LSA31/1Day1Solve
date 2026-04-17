#include <iostream>
#include <vector>
using namespace std;

vector<vector<long>> graph;
vector<bool> visited;
long depth;

void DFS(long node)
{
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{
		long next = graph[node][i];

		if (!visited[next])
		{
			depth++;
			DFS(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n = 0, m = 0;
	cin >> n >> m;

	graph.resize(n + 1);
	visited.resize(n + 1, false);

	for (long i = 0; i < m; i++)
	{
		long a = 0, b = 0;
		cin >> a >> b;

		graph[b].push_back(a);
	}

	vector<long> dist(n + 1, 0);
	long MAX = 0;
	for (long i = 1; i <= n; i++)
	{
		DFS(i);

		if (MAX < depth)
			MAX = depth;

		dist[i] = depth;
		depth = 0;
		visited.assign(n + 1, false);
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == MAX)
			cout << i << ' ';
	}
}