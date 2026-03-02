#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LL n = 0;
	cin >> n;
	
	LL ret = n;
	for (LL p = 2; p <= sqrt(n); p++)
	{
		if (n % p == 0)  // p가 소인수라면
		{
			ret = ret - (ret / p);

			while (n % p == 0)  // 해당 소인수 지우기
				n /= p;
		}
	}
	if (n > 1)
		ret = ret - (ret / n);

	cout << ret;
}