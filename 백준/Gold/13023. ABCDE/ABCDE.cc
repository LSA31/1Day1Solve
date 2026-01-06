#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vect;
vector<bool> visited;
bool arrive; // 도착 확인 변수

void DFS(int index, int depth)
{
	if (depth == 5 || arrive)
	{
		arrive = true;
		return;
	}
	visited[index] = true;

	for (int i = 0; i < vect[index].size(); i++)
	{
		if (visited[vect[index][i]] == false)
			DFS(vect[index][i], depth + 1);
	}
	visited[index] = false;
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
	for (int i = 0; i < n; i++)
	{
		DFS(i, 1);

		if (arrive)
			break;
	}
	if (arrive)
		cout << 1;
	else
		cout << 0;
}