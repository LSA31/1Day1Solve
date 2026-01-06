#include <iostream>
using namespace std;

int students[20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p = 0;
	cin >> p;

	for (int test_case = 1; test_case <= p; test_case++)
	{
		cin >> test_case;
		
		int cnt = 0;
		for (int i = 0; i < 20; i++)
		{
			int now = 0;
			cin >> now;

			bool flag = false;
			for (int j = 0; j < i; j++)
			{
				if (students[j] > now)
				{
					for (int z = i; z >= j; z--)
						students[z + 1] = students[z];

					students[j] = now;

					cnt += (i - j);

					flag = true;

					break;
				}
			}
			if (flag == false)
				students[i] = now;
		}
		cout << test_case << ' ' << cnt << '\n';
	}
	return 0;
}