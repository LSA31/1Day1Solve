#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> vect(n + 1, 0);
	for (int t = 0; t < m; t++)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int z = i; z <= j; z++)
			vect[z] = k;
	}
	for (int i = 1; i <= n; i++)
		cout << vect[i] << ' ';
}