#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> vect(9, vector<int>(9, 0));
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cin >> vect[y][x];
		}
	}
	int Max = 0;
	int My, Mx;
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (vect[y][x] >= Max)
			{
				Max = vect[y][x];
				My = y + 1;
				Mx = x + 1;
			}
		}
	}
	cout << Max << '\n' << My << ' ' << Mx;
}