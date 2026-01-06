#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n = 0;
	cin >> n;

	vector<long long int> honeycomb;
	honeycomb.push_back(1);

	int index = 0;
	int i = 1;
	while (n != 1)
	{
		long long int range = honeycomb[index] + 6 * i;  // 범위의 끝
		honeycomb.push_back(range);

		if (n <= range)
			break;

		index++;
		i++;
	}
	if (n == 1)
		cout << 1;
	else
		cout << i + 1;

	return 0;
}