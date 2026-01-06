#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> vect(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	for (int y = 0; y < n - 1; y++)
	{
		for (int x = 0; x < n - 1; x++)
		{
			if (vect[x] > vect[x + 1])
				swap(vect[x], vect[x + 1]);
		}
	}

	for (int i = 0; i < n; i++)
		cout << vect[i] << '\n';
}