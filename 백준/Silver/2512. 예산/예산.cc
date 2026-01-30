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

	LL sum = 0;  // 예산 요청의 총합
	vector<LL> budget(n, 0);
	for (LL i = 0; i < n; i++)
	{
		cin >> budget[i];

		sum += budget[i];
	}
	sort(budget.begin(), budget.end());
	
	LL m = 0;
	cin >> m;

	if (sum <= m)  // case 1
		cout << budget[n - 1];  // 최댓값
	else  // case 2
	{
		LL start = 0, end = budget[n - 1], ret = 0;
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
				ret = mid;
			}
		}
		cout << ret;
	}

	return 0;
}