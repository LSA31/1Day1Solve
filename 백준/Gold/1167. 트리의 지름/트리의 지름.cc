#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> vect;
vector<bool> visited;
vector<int> Distance;

void BFS(int index)
{
	queue<int> Q;
	Q.push(index);
	visited[index] = true;

	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();

		for (int i = 0; i < vect[now].size(); i++)
		{
			if (visited[vect[now][i].first] == false)
			{
				visited[vect[now][i].first] = true;
				Q.push(vect[now][i].first);

				Distance[vect[now][i].first] = Distance[now] + vect[now][i].second;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vect.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		int index;
		cin >> index;

		while (1)
		{
			int E, V;
			cin >> E;
			if (E == -1)
				break;
			cin >> V;
			vect[index].push_back(edge(E, V));
		}
	}
	Distance = vector<int>(n + 1, 0);
	visited = vector<bool>(n + 1, false);
	BFS(1);

	int Max = 1;
	for (int i = 2; i <= n; i++)
	{
		if (Distance[Max] < Distance[i])
			Max = i;
	}
	fill(Distance.begin(), Distance.end(), 0); // 거리 배열 초기화
	fill(visited.begin(), visited.end(), false); // 방문 배열 초기화

	BFS(Max); // 거리 배열에서 가장 큰 값을 다시 시작점으로 지정
	sort(Distance.begin(), Distance.end());
	cout << Distance[n];
}