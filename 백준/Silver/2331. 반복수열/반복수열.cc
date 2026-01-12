#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int value(int n, int p)
{
	int ret = 0;

	while (10 <= n)
	{
		int t = n % 10;
		ret += pow(t, p);

		n /= 10;
	}
	ret += pow(n % 10, p);

	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool check[236197] = { false, };
	int a = 0, P = 0;
	cin >> a >> P;

	vector<int> d;
	d.push_back(a);
	check[a] = true;

	int index = 1;
	while (1)
	{
		int next = value(d[index - 1], P);
		d.push_back(next);

		if (check[next] == true)
			break;

		check[next] = true;
		index++;
	}
	int cnt = 0;
	for (int i = 0; i < index; i++)
	{
		if (d[i] == d[index])
		{
			cout << cnt;
			break;
		}
		cnt++;
	}

	return 0;
}