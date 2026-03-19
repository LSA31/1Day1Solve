#include <iostream>
using namespace std;

int main()
{
	int x = 0;
	cin >> x;

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		x -= (a * b);
	}
	if (x == 0)
		cout << "Yes";
	else
		cout << "No";
}