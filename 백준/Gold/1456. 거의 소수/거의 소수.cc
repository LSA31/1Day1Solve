#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LL a = 0, b = 0;
	cin >> a >> b;

	vector<LL> vect;
	for (LL i = 0; i <= sqrt(b) + 1; i++)
		vect.push_back(i);

	// 소수 구하기
	for (LL i = 2; i < vect.size(); i++)
	{
		if (vect[i] != 0)
		{
			for (LL j = i * 2; j < vect.size(); j += i)
			{
				if (vect[j] != 0)
					vect[j] = 0;
			}
		}
	}

	LL cnt = 0;
	for (LL i = 2; i < vect.size(); i++)
	{
		if (vect[i] != 0)
		{
			LL index = i * i;
			while (index <= b)
			{
				if (a <= index)
					cnt++;

				if (index > b / i)  // 오버플로우 방지 
					break;

				index *= i;
			}
		}
	}
	cout << cnt;

	return 0;
}