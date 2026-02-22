#include <iostream>
using namespace std;

int main()
{
	long long n = 0;
	long long Max = -1000001, Min = 1000001;

	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		long long num = 0;
		cin >> num;

		if (num > Max)
			Max = num;
		if (num < Min)
			Min = num;
	}
	cout << Min << ' ' << Max;
}