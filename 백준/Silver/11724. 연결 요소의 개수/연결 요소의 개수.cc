#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> vect;

void DFS(int index)
{
	if (visited[index] == true) // 현재 노드에 방문했었다면 return
		return;

	visited[index] = true;
	for (int i = 0; i < vect[index].size(); i++)
	{
		if (visited[vect[index][i]] == false)
			DFS(vect[index][i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vect.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int index, value;
		cin >> index >> value;

		vect[index].push_back(value);
		vect[value].push_back(index);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			ret++;
			DFS(i);
		}
	}
	cout << ret;
}