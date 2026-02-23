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
		string str = "";
		cin >> str;

		int ret = 0, cnt = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'X')
				cnt = 0;
			else
				cnt++;

			ret += cnt;
		}
		cout << ret << '\n';
	}

	return 0;
}