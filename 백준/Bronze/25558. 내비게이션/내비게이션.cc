#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	long long sx = 0, sy = 0, ex = 0, ey = 0;
	cin >> N >> sx >> sy >> ex >> ey;

	int ret = 0;
	long long Min = LLONG_MAX;
	for (int i = 1; i <= N; i++)
	{
		int M = 0;
		cin >> M;

		long long sum = 0;
		long long startX = sx, startY = sy;
		for (int j = 0; j < M; j++)
		{
			long long x = 0, y = 0;
			cin >> x >> y;

			sum += (abs(startX - x) + abs(startY - y));
			startX = x;
			startY = y;
		}
		sum += (abs(startX - ex) + abs(startY - ey));

		if (Min > sum)
		{
			Min = sum;
			ret = i;
		}
	}
	cout << ret;
}