#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sides[3] = { 0, };
	while (1)
	{
		cin >> sides[0] >> sides[1] >> sides[2];

		if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0)
			break;

		sort(sides, sides + 3);

		if (sides[2] >= sides[0] + sides[1])
			cout << "Invalid" << '\n';
		else if (sides[0] == sides[1] && sides[1] == sides[2])
			cout << "Equilateral" << '\n';
		else if (sides[0] != sides[1] && sides[1] != sides[2])
			cout << "Scalene" << '\n';
		else
			cout << "Isosceles" << '\n';
	}
	return 0;
}