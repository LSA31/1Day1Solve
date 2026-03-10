#include <iostream>
using namespace std;

int main()
{
	int n = 0, x = 0;
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;

		if (a < x)
			cout << a << ' ';
	}
}