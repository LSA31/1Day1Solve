#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long Min = 0, Max = 0;
	cin >> Min >> Max;

	vector<bool> check(Max - Min + 1, false);
	for (long long i = 2; i * i <= Max; i++)
	{
		long long pow = i * i;
		long long start = (Min / pow);

		if (Min % pow != 0)
			start++;

		for (long long j = start; j * pow <= Max; j++)
			check[(int)((j * pow) - Min)] = true;
	}
	int cnt = 0;
	for (int i = 0; i < check.size(); i++)
	{
		if (check[i] == false)
			cnt++;
	}
	cout << cnt;
}