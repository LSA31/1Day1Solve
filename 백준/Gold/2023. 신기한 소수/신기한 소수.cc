#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ret;
int prime[5] = { 1,3,5,7,9 };
int N;

bool isPrime(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void dfs(int num, int jarisu)
{
	if (jarisu == N)
	{
		ret.push_back(num);  //마지막에도 소수인지 검사해야되나??
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		int t = num * 10 + prime[i];
		if (isPrime(t) == true)
			dfs(t, jarisu + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dfs(2, 1);  // N의 자리가 2,3,5,7
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);


	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << '\n';

	return 0;
}