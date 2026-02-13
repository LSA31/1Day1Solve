#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		vector<int> triangle(3, 0);
		int Max = 0, index = 0;
		for (int i = 0; i < 3; i++)
		{
			cin >> triangle[i];

			if (Max < triangle[i])
			{
				Max = triangle[i];
				index = i;
			}
		}
		if (triangle[0] == 0 && triangle[1] == 0 && triangle[2] == 0)
			break;

		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			if (i != index)
				sum += (pow(triangle[i], 2));
		}

		if (sum == pow(Max, 2))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	return 0;
}