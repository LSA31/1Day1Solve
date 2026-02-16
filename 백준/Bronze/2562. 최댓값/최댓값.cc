#include <iostream>
using namespace std;

int main()
{
	int Max = 0, index = 0;
	for (int i = 1; i <= 9; i++)
	{
		int n = 0;
		cin >> n;

		if (n > Max)
		{
			Max = n;
			index = i;
		}
	}
	cout << Max << '\n' << index;
}