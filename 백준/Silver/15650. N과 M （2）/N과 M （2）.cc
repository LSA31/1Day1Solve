#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> picked;

void backTracking(int start, int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < picked.size(); i++)
			cout << picked[i] << ' ';
		cout << '\n';

		return;
	}
	for (int i = start; i <= n; i++)
	{
		picked.push_back(i);
		backTracking(i + 1, depth + 1);
		picked.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	backTracking(1, 0);

	return 0;
}