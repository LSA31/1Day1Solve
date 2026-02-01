#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int money = 0;
	cin >> money;
	money = 1000 - money;  // 거스름돈

	int arr[6] = { 500, 100, 50, 10, 5,1 };
	int cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		int t = 0;
		if (money >= arr[i])
		{
			t = money / arr[i];
			money %= arr[i];
			cnt += t;
		}
	}
	cout << cnt;

	return 0;
}