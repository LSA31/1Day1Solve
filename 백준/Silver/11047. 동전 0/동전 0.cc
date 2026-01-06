#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sum;
	cin >> n >> sum;

	vector<int> vect(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (vect[i] <= sum)
		{
			cnt += (sum / vect[i]);
			sum %= vect[i];
		}
	}
	cout << cnt;
}