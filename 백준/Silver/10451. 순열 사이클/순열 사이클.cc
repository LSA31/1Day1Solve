#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> graph;
vector<bool> visited;

void dfs(int start)
{	
	if (visited[start] == false)
	{
		visited[start] = true;
		dfs(graph[start]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case = 0;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++)
	{
		cin >> n;
		graph.resize(n + 1, 0);
		visited.resize(n + 1, false);

		for (int i = 1; i <= n; i++)
			cin >> graph[i];

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[graph[i]] == false)
			{
				dfs(graph[i]);

				cnt++;
			}
		}
		cout << cnt << '\n';

		visited.clear();
		graph.clear();
	}
	return 0;
}