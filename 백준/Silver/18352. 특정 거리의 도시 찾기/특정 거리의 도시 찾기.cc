#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

ll N, M, K, X;
vector<vector<ll>> graph;
vector<ll> dist;
vector<bool> visited;

void BFS(int start)
{
	queue<ll> q;
	q.push(start);
	dist[start] = 0;
	visited[start] = true;

	while (!q.empty())
	{
		ll now = q.front();
		q.pop();

		for (ll i = 0; i < graph[now].size(); i++)
		{
			ll next = graph[now][i];

			if (!visited[next])
			{
				dist[next] = dist[now] + 1;
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

	cin >> N >> M >> K >> X;
	graph.resize(N + 1);
	dist.resize(N + 1, -1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		ll a = 0, b = 0;
		cin >> a >> b;

		graph[a].push_back(b);
	}
	BFS(X);

	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
		{
			cout << i << '\n';
			flag = true;
		}
	}
	if (flag == false)
		cout << -1;
}