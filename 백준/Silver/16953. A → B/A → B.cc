#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;

bool BFS(int a, int b)
{
	queue<pair<LL, int>> Q;

	Q.push(make_pair(a, 1));  // value, depth

	while (!Q.empty())
	{
		LL val = Q.front().first;
		int depth = Q.front().second;
		Q.pop();

		LL MUL = val * 2;
		LL ADD = (val * 10) + 1;

		if (MUL <= b)
		{
			if (MUL == b)
			{
				cout << depth + 1;
				return true;
			}
			Q.push(make_pair(MUL, depth + 1));
		}
		if (ADD <= b)
		{
			if (ADD == b)
			{
				cout << depth + 1;
				return true;
			}
			Q.push(make_pair(ADD, depth + 1));
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LL a = 0, b = 0;
	cin >> a >> b;

	if (!BFS(a, b))
		cout << -1;

	return 0;
}