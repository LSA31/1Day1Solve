#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<int> vect(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	int start = 0, end = n - 1;
	int count = 0;
	while (start < end)
	{
		if (vect[start] + vect[end] > m)
			end--;
		else if (vect[start] + vect[end] < m)
			start++;
		else if (vect[start] + vect[end] == m)
		{
			start++;
			end--;
			count++;
		}
	}
	cout << count;
}