#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int ret;
	int start = 1, end = k;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int cnt = 0; // 중앙값보다 작은 수

		for (int i = 1; i <= n; i++) // cnt개수 수하기
		{
			cnt += min(mid / i, n);
		}
		if (cnt < k)
			start = mid + 1;
		else
		{
			end = mid - 1;
			ret = mid;
		}
	}
	cout << ret;
}