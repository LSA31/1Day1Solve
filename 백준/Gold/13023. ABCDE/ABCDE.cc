#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> friends;
vector<bool> visited;
bool flag;

void dfs(int node, int cnt)  // 현재 노드, 조건 만족 수
{
	if (cnt == 4)  // 4가지 조건 모두 만족 시
	{
		flag = true;
		return;
	}

	visited[node] = true;
	
	for (int i = 0; i < friends[node].size(); i++)
	{
		int next = friends[node][i];
		if (visited[next] == false)
			dfs(next, cnt + 1);
	}
	visited[node] = false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	friends.resize(N);
	visited.resize(N, false);
	for (int i = 0; i < M; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		dfs(i, 0);

		if (flag == true)
			break;
	}
	if (flag == false)
		cout << 0;
	else
		cout << 1;

	return 0;
}