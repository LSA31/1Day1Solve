#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LL n = 0;
	cin >> n;

	LL sum = 0, Max = 0;  // 예산 요청의 총합, 최댓값, 최솟값
	vector<LL> budget(n, 0);
	for (LL i = 0; i < n; i++)
	{
		cin >> budget[i];

		if (Max < budget[i])
			Max = budget[i];
		sum += budget[i];
	}
	
	LL m = 0;
	cin >> m;

	if (sum <= m)  // case 1
		cout << Max;
	else  // case 2
	{
		LL start = 0, end = Max, ret = 0;
		while (start <= end)
		{
			LL mid = (start + end) / 2;

			LL sum2 = 0;
			for (int i = 0; i < n; i++)
				sum2 += min(budget[i], mid);

			if (sum2 > m)
				end = (mid - 1);
			else
			{
				start = (mid + 1);

				if (ret < sum2) 
					ret = mid;
			}
		}
		cout << ret;
	}

	return 0;
}