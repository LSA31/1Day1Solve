#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	vector<int> vect(n, 0);
	int start = 0, end = 0;  // 강의 시간 최댓값, 강의 시간 총합
	for (int i = 0; i < n; i++)
	{
		cin >> vect[i];

		if (start < vect[i])
			start = vect[i];
		end += vect[i];
	}
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0, cnt = 0;  // 레슨 시간 합, 사용한 블루레이 개수

		for (int i = 0; i < n; i++)
		{
			if (sum + vect[i] > mid)
			{
				cnt++;
				sum = 0;
			}
			sum += vect[i];
		}
		if (sum != 0)
			cnt++;
		if (cnt > m)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << start;

	return 0;
}