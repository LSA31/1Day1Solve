#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int count[100001] = { 0 };

	cin >> n;

	int t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		count[t]++;
	}
	for (int i = 0; i <= 10000; i++)
	{
		while (count[i] > 0)
		{
			cout << i << '\n';
			count[i]--;
		}
	}
}