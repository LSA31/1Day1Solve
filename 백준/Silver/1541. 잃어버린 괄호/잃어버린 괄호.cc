// 잃어버린 괄호
// -를 기준으로 문자열 분리

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string str, char ch)
{
	vector<string> tmp;
	int start = 0, i = 0;
	while (i < str.size())
	{
		if (str[i] == ch)
		{
			tmp.push_back(str.substr(start, i - start));
			start = i + 1;
		}
		i++;
	}
	tmp.push_back(str.substr(start, i - start));

	return tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	cin >> str;

	vector<string> sub = split(str, '-');
	
	vector<vector<string>> add(sub.size());
	for (int i = 0; i < sub.size(); i++)
	{
		vector<string> tmp = split(sub[i], '+');

		for (int j = 0; j < tmp.size(); j++)
			add[i].push_back(tmp[j]);
	}
	vector<int> sum(sub.size(), 0);
	for (int y = 0; y < sub.size(); y++)
	{
		for (int x = 0; x < add[y].size(); x++)
			sum[y] += stoi(add[y][x]);
	}
	int ret = sum[0];
	for (int i = 1; i < sum.size(); i++)
		ret -= sum[i];

	cout << ret;

	return 0;
}