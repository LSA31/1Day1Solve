#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> vect;
	for (int i = 1; i <= n; i++)
		vect.push_back(i);

	for (int p = 0; p < m; p++)
	{
		int i, j;
		cin >> i >> j;

		swap(vect[i - 1], vect[j - 1]);
	}
	for (int i = 0; i < n; i++)
		cout << vect[i] << ' ';
}