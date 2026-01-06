#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> vect(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vect[i].first;
		vect[i].second = i;  // index 값
	}
	
	sort(vect.begin(), vect.end());

	int MAX = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		t = vect[i].second - i;

		if (t > MAX)
			MAX = t;
	}
	cout << MAX + 1;
}