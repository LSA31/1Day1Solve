#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;

int V, E, K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<edge>> mlist;
priority_queue<edge, vector<edge>, greater<edge>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;

	mdistance.resize(V + 1, INT_MAX);
	visited.resize(V + 1, false);
	mlist.resize(V + 1);

	for (int i = 1; i <= E; i++)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;

		mlist[u].push_back(make_pair(v, w));
	}
	q.push(make_pair(0, K));  // 시작 노드 거리값 0으로 초기화
 	mdistance[K] = 0;

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

			if (mdistance[next] > mdistance[c_v] + value)  // 다익스트라
			{
				mdistance[next] = mdistance[c_v] + value;
				q.push(make_pair(mdistance[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (visited[i])
			cout << mdistance[i] << '\n';
		else
			cout << "INF" << '\n';
	}
}