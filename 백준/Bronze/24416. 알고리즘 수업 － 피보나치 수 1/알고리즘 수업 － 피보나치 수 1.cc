#include <iostream>
using namespace std;

int fibCnt = 1;

int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
	{
		fibCnt++;
		return (fib(n - 1) + fib(n - 2));
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	fib(n);

	int first = 1, second = 1, now = 0;
	int dpCnt = 1;
	for (int i = 3; i < n; i++)
	{
		dpCnt++;

		now = first + second;

		second = first;
		first = now;
	}
	cout << fibCnt << ' ' << dpCnt;
}