#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> vect(205, 0);
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;

		if (t < 0)
			vect[(t * (-1) + 100)]++;
		else
			vect[t]++;
	}
	int v = 0;
	cin >> v;

	if (v < 0)
		cout << vect[(v * (-1)) + 100];
	else
		cout << vect[v];
}