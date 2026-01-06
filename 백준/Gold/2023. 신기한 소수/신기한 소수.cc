#include <iostream>
#include <vector>
using namespace std;

int n;

bool isPrime(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void DFS(int num, int jarisu)
{
	if (jarisu == n)
	{
		if (isPrime(num))
		{
			cout << num << '\n';
		}
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (i % 2 == 0) // 짝수인 경우
			continue;
		if (isPrime(num * 10 + i))
			DFS(num * 10 + i, jarisu + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}