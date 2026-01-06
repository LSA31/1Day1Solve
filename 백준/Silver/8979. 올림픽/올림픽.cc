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

	vector<vector<int>> medal(n + 1, vector<int>(4, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> medal[i][j];
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

	int ret = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (medal[i][0] == k)
			break;

		if ((medal[i][1] == medal[i + 1][1]) && (medal[i][2] == medal[i + 1][2])
			&& (medal[i][3] == medal[i + 1][3]))
			cnt++;
		else
		{
			if (cnt == 0)
				ret++;
			else
			{
				ret += (cnt + 1);
				cnt = 0;
			}
		}
	}
	cout << ret;

	return 0;
}