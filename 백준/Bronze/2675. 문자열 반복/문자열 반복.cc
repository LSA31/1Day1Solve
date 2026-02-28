#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int r = 0;
		string str = "";
		cin >> r >> str;

		for (int j = 0; j < str.size(); j++)
		{
			for (int z = 0; z < r; z++)
			{
				cout << str[j];
			}
		}
		cout << '\n';
	}
}