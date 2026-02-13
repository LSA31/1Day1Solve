#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> vect(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		for (int j = 2; j < vect[i]; j++)
		{
			if (vect[i] % j == 0)
			{
				flag = true;
				break;
			}
		}
		if (vect[i] != 0 && vect[i] != 1 && flag == false)
			cnt++;
	}
	cout << cnt;
}