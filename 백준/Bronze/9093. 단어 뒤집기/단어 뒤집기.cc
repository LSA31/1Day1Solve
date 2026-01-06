#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> word;
vector<string> ans;

void Reverse(int idx)
{
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = word[i].size() - 1; j >= 0; j--)
			ans[idx].push_back(word[i][j]);

		if (i != word.size() - 1)
			ans[idx].push_back(' ');
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	string IGNORE = "";
	getline(cin, IGNORE);

	ans.resize(T, "");
	for (int i = 0; i < T; i++)
	{
		string str = "";
		getline(cin, str);

		word.clear();
		int start = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ' ')
			{
				word.push_back(str.substr(start, j - start));
				start = j + 1;
			}
		}
		word.push_back(str.substr(start, str.size() - start));
		Reverse(i);
	}
	for (int i = 0; i < T; i++)
	{
		cout << ans[i];

		if (i != T - 1)
			cout << '\n';
	}

	return 0;
}