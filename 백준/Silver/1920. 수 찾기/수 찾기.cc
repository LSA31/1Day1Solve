#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	vector<int> vect(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int target;
		cin >> target;

		int start = 0, end = n - 1;
		bool find = false;
		while (start <= end)
		{
			int mid_index = (start + end) / 2; // 중간값 인덱스
			int mid = vect[mid_index]; // 중간값

			if (mid > target)
				end = mid_index - 1;
			else if (mid < target)
				start = mid_index + 1;
			else if (mid == target)
			{
				find = true;
				break;
			}
		}
		if (find)
			cout << "1" << '\n';
		else
			cout << "0" << '\n';
	}
}