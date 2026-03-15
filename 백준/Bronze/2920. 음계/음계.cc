#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	int as = 0, des = 0;
	for (int i = 1; i <= 8; i++)
	{
		cin >> n;

		if (n == i)
			as++;
		else if (n == 9 - i)
			des++;
	}
	if (as == 8)
		cout << "ascending";
	else if (des == 8)
		cout << "descending";
	else
		cout << "mixed";
}