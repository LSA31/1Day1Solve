#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	cin >> min >> max;

	vector<bool> vect(max - min + 1);

	for (long i = 2; i * i <= max; i++)
	{
		long pow = i * i; // 제곱수
		long start_index = min / pow;

		if (min % pow != 0) // 나머지가 있으면 1을 더해주어야 min보다 큰 제곱수부터 시작됨
			start_index++;

		for (long j = start_index; pow * j <= max; j++)
			vect[(int)((j * pow) - min)] = true;
	}
	int cnt = 0;
	for (int i = 0; i <= max - min; i++)
	{
		if (!vect[i])
			cnt++;
	}
	cout << cnt;
}