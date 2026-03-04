#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vect(1001, false);
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		int n = 0;
		cin >> n;

		n %= 42;

		if (!vect[n])
		{
			cnt++;
			vect[n] = true;
		}
	}
	cout << cnt;
}