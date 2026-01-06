#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[101][101] = { 0, };
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				if (arr[y][x] == 0)
				{
					cnt++;
					arr[y][x] = 1;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}