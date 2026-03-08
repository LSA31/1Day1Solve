#include <iostream>
using namespace std;

typedef long long LL;

LL pisano(LL m)
{
	LL previous = 1, current = 1;
	LL k = 0;
	for (LL i = 0; i < m * m; i++)  // k(m) <= m^2 - 1
	{
		k = (previous + current) % m;
		previous = current;
		current = k;

		if (previous == 1 && current == 1)
			return i + 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p = 0;
	cin >> p;

	for (int i = 0; i < p; i++)
	{
		LL n = 0, m = 0;
		cin >> n >> m;

		cout << n << ' ' << pisano(m) << '\n';
	}
}