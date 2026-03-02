#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return GCD(b, a % b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		cout << a * b / GCD(a, b) << '\n';
	}
}