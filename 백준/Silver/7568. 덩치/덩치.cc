#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<pair<int, int>> vect(n);
	for (int i = 0; i < n; i++)
		cin >> vect[i].first >> vect[i].second;

	for (int i = 0; i < n; i++)
	{
		int rank = 1;
		for (int j = 0; j < n; j++)
		{
			if ((vect[i].first < vect[j].first) && (vect[i].second < vect[j].second))
				rank++;
		}
		cout << rank << ' ';
	}

	return 0;
}