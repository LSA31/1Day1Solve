#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0, b = 0;
	cin >> n >> m >> b;

	vector<int> vect(257, 0);
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int num = 0;
			cin >> num;
			vect[num]++;
		}
	}
	long long time = 21e8, height = 0;
	for (int i = 0; i < 257; i++)
	{
		long long t = 0, block = b;
		for (int j = 0; j < 257; j++)
		{
			if (vect[j] == 0 || i == j) continue;

			if (i < j)
			{
				t += ((vect[j] * (j - i)) * 2);
				block += ((vect[j] * (j - i)));
			}
			else
			{
				t += (vect[j] * (i - j));
				block -= ((vect[j] * (i - j)));
			}
		}
		if (block < 0) continue;
		if (t <= time)
		{
			time = t;
			height = i;
		}
	}
	cout << time << ' ' << height;

	return 0;
}