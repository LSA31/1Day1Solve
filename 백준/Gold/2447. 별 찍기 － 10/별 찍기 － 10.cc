#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> vect;

void star(int i, int j, int n)
{
	if (n == 3)
	{
		for (int y = i; y < i + 3; y++)
		{
			for (int x = j; x < j + 3; x++)
			{
				if (y == i + 1 && x == j + 1)
					vect[y][x] = ' ';
				else
					vect[y][x] = '*';
			}
		}
		return;
	}
	for (int y = i; y < i + n; y += n / 3)
	{
		for (int x = j; x < j + n; x += n / 3)
		{
			if (((y - (n / 3)) % n == 0) && (x - (n / 3)) % n == 0)
				continue;
			else
				star(y, x, n / 3);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vect.resize(n + 1, vector<char>(n + 1, ' '));

	star(0, 0, n);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << vect[y][x];
		}
		cout << '\n';
	}

	return 0;
}