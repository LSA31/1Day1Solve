#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int n = str.size();
	vector<int> vect(n);
	for (int i = 0; i < n; i++)
		vect[i] = str[i] - '0';

	for (int y = 0; y < n; y++)
	{
		int Max = y;
		for (int x = y + 1; x < n; x++)
		{
			if (vect[Max] < vect[x])
				Max = x;
		}
		if (vect[y] < vect[Max])
			swap(vect[y], vect[Max]);
	}
	for (int i = 0; i < n; i++)
		cout << vect[i];
}