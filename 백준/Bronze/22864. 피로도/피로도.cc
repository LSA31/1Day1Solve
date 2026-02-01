#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a = 0, b = 0, c = 0, m = 0;
	cin >> a >> b >> c >> m;

	int day = 24, now = 0, cnt = 0;  // 24시간, 현재 피로도, 일 횟수
	while (day > 0)
	{
		if (now + a <= m)
		{
			now += a;
			cnt++;
		}
		else
		{
			if (now - c < 0)
				now = 0;
			else
				now -= c;
		}

		day--;
	}
	cout << cnt * b;
}