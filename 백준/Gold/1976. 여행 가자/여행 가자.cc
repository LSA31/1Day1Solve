#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
void unionfunc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	parent.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> num;

			if (num == 1)
				unionfunc(i, j);
		}
	}
	
	cin >> num;
	int P = find(num);
	bool ret = true;
	for (int i = 1; i < M; i++)
	{
		cin >> num;

		if (find(num) != P)
		{
			ret = false;
			break;
		}
	}
	if (ret)
		cout << "YES";
	else
		cout << "NO";
}