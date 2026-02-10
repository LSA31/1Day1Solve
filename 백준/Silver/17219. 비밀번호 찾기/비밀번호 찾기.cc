#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	map<string, string> file;
	for (int i = 0; i < n; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;

		file[str1] = str2;
	}
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		cout << file[str] << '\n';
	}

	return 0;
}