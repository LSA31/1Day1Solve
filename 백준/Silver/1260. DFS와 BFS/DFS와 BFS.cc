#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> vect;
vector<bool> visited;

void DFS(int index)
{
	cout << index << " ";
	visited[index] = true;

	for (int i = 0; i < vect[index].size(); i++)
	{
		if (visited[vect[index][i]] == false)
			DFS(vect[index][i]);
	}
}
void BFS(int index)
{
	queue<int> Q;
	Q.push(index);
	visited[index] = true;

	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		cout << now << " ";

		for (int i = 0; i < vect[now].size(); i++)
		{
			if (visited[vect[now][i]] == false)
			{
				visited[vect[now][i]] = true;
				Q.push(vect[now][i]);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;

	vect.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int index, value;
		cin >> index >> value;

		vect[index].push_back(value);
		vect[value].push_back(index);
	}
	for (int i = 1; i <= n; i++)
		sort(vect[i].begin(), vect[i].end());

	DFS(start);
	cout << '\n';
	fill(visited.begin(), visited.end(), false); // visited배열 false로 초기화
	BFS(start);
}