#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int pisano(LL n)
{
	LL previous = 1, current = 1;
	LL k = 0;
	for (LL i = 0; i < n * n; i++)  // k(m) <= m^2 - 1
	{
		k = (previous + current) % n;
		previous = current;
		current = k;

		if (previous == 1 && current == 1)
			return i + 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LL n = 0;
	cin >> n;

	LL k = pisano(1000000);  // 반복되는 주기 = 1,500,000
	LL index = n % k;

	vector<LL> fibo(index + 2, 0);
	fibo[1] = 1;
	for (LL i = 2; i <= index; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000;

	cout << fibo[index];
}