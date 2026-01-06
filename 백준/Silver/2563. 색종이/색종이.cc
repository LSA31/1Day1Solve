#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int paper[101][101] = { 0, };
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int X_start = 0, Y_start = 0;
		cin >> X_start >> Y_start;
		for (int y = Y_start; y < Y_start + 10; y++)
		{
			for (int x = X_start; x < X_start + 10; x++)
			{
				if (paper[y][x] == 0)
				{
					cnt++;
					paper[y][x] = 1;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}