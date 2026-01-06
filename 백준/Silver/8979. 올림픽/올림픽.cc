#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;

	vector<string> medal(n + 1, "");
	for (int y = 0; y < n; y++)
	{
		char s = ' ';
		for (int x = 0; x < 4; x++)
		{
			cin >> s;

			medal[y].push_back(s);
		}
	}

	for (int y = 0; y < n - 1; y++)
	{
		for (int x = y + 1; x < n; x++)
		{
			if (medal[y][1] < medal[x][1]) // 1. 금메달 기준 정렬
				swap(medal[y], medal[x]);
			else if (medal[y][1] == medal[x][1])  
			{
				if (medal[y][2] < medal[x][2])  // 2. 은메달 개수 비교
					swap(medal[y], medal[x]);
				else if (medal[y][2] == medal[x][2])  
				{
					if (medal[y][3] < medal[x][3])  // 3. 동메달 개수 비교
						swap(medal[y], medal[x]);
				}
			}
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (medal[i][0] - '0' == k)
			break;

		if (medal[i].substr(1, 3) == medal[i + 1].substr(1, 3))
			continue;
		else
			cnt++;
	}
	cout << cnt;

	return 0;
}