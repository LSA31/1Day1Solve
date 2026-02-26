#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	map<string, int> who;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		cin >> str;

		who[str] = 1;
	}
	
	vector<string> ret;
	for (int i = 0; i < m; i++)
	{
		string str = "";
		cin >> str;

		if (who[str] == 1)
			ret.push_back(str);
	}

	sort(ret.begin(), ret.end());
	cout << ret.size() << '\n';
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << '\n';

	return 0;
}