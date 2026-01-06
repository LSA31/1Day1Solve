#include <iostream>
#include <cmath>
using namespace std;

int dx[4] = { 0,1,0,1 };
int dy[4] = { 0,0,1,1 };
int r, c;

void Z(int n, int x, int y, int sum)  // n, 출발지 x좌표, 출발지 y좌표
{
	if (n == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy == r && xx == c)
			{
				cout << sum;
				return;
			}
			sum++;
		}
	}

	int half = pow(2, n) / 2;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + (half * dx[i]);
		int yy = y + (half * dy[i]);

		if (yy <= r && r <= yy + (half - 1))  // 해당 범위 안에 (r,c)가 있다면 재귀
		{
			if (xx <= c && c <= xx + (half - 1))
				Z(n - 1, xx, yy, sum);
			else
				sum += pow(4, (n - 1));
		}
		else
			sum += pow(4, (n - 1));
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n >> r >> c;

	Z(n, 0, 0, 0);

	return 0;
}