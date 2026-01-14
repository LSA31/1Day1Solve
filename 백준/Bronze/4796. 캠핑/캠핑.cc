#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l = 0, p = 0, v = 0;
	int test_case = 1;
	while (1)
	{
		cin >> l >> p >> v;

		if (l == 0 && p == 0 && v == 0)
			break;

		int ret = (l * (v / p)) + min(l, v % p);
		cout << "Case " << test_case << ": " << ret << '\n';
		test_case++;
	}
	return 0;
}