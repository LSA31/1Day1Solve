#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> dist(N + 1, INT_MAX);
	vector<bool> visited(N + 1, false);
	vector<vector<edge>> mlist(N + 1);
	priority_queue<edge, vector<edge>, greater<edge>> q;

	for (int i = 1; i <= M; i++)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;

		mlist[u].push_back(make_pair(v, w));
	}
	int start = 0, end = 0;
	cin >> start >> end;

	q.push(make_pair(0, start));
	dist[start] = 0;

	while (!q.empty())
	{
		edge cur = q.top();
		q.pop();
		int c_v = cur.second;

		if (visited[c_v]) continue;

		visited[c_v] = true;

		for (int i = 0; i < mlist[c_v].size(); i++)
		{
			edge tmp = mlist[c_v][i];
			int next = tmp.first;
			int value = tmp.second;

			if (dist[next] > dist[c_v] + value)
			{
				dist[next] = dist[c_v] + value;
				q.push(make_pair(dist[next], next));
			}
		}
	}
	cout << dist[end];
}
