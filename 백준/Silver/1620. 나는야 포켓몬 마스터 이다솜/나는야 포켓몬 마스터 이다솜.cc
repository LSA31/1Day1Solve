#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	map<string, int> dic;
	vector<string> dic2;
	for (int i = 1; i <= n; i++)
	{
		string str = "";
		cin >> str;

		dic[str] = i;
		dic2.push_back(str);
	}
	for (int i = 0; i < m; i++)
	{
		string str = "";
		cin >> str;

		if ('0' <= str[0] && str[0] <= '9')
			cout << dic2[stoi(str) - 1] << '\n';
		else
			cout << dic[str] << '\n';
	}
}