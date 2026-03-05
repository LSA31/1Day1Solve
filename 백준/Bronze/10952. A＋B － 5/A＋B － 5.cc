#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		if (a == 0 && b == 0) return 0;

		cout << a + b << '\n';
	}
}