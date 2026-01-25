#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> vect(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	int find_cnt = 0;
	cin >> find_cnt;
	for (int i = 0; i < find_cnt; i++)
	{
		int find = 0;
		cin >> find;

		int start = 0, end = n - 1;
		bool flag = false;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			int midV = vect[mid];

			if (find == midV)
			{
				flag = true;
				cout << 1 << '\n';
				break;
			}
			else if (find < midV)
				end = mid - 1;
			else if (find > midV)
				start = mid + 1;
		}
		if (flag == false)
			cout << 0 << '\n';
	}

	return 0;
}