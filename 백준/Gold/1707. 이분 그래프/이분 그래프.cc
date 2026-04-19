#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> check;
bool ret;

void DFS(int node)
{
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		
		if (!visited[next])
		{
			check[next] = (check[node] + 1) % 2;
			// 이미 방문한 노드는 같은 집합이 아니므로 이전 노드와 다른 집합으로 처리
			DFS(next);
		}
		else if (check[node] == check[next])
			ret = false;
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
		int V = 0, E = 0;
		cin >> V >> E;

		graph.assign(V + 1, vector<int>());
		visited.assign(V + 1, false);
		check.assign(V + 1, 0);
		ret = true;

		int u = 0, v = 0;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= V; i++)
		{
			// 그래프가 끊어져 있을 수 있기 때문에, 모든 정점에서 확인
			if (!visited[i])
				DFS(i);

			if (!ret)
				break;
		}
		if (ret)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}