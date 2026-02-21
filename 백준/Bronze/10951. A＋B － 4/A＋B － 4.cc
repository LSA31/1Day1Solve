#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		if (cin.eof()) break;

		cout << a + b << '\n';
	}
}