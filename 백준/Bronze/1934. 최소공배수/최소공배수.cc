#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		int at = max(a, b), bt = min(a, b);
		while (bt != 0)
		{
			int ret = at % bt;
			at = bt;
			bt = ret;
		}
		cout << a * b / at << '\n';
	}
}