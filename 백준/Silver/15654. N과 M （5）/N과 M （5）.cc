#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vect;
vector<int> picked;
vector<bool> visited;

void backTracking(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << picked[i] << ' ';
		cout << '\n';

		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == true) continue;

		picked.push_back(vect[i]);
		visited[i] = true;

		backTracking(depth + 1);

		picked.pop_back();
		visited[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vect.resize(n, 0);
	visited.resize(n, false);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	backTracking(0);

	return 0;
}