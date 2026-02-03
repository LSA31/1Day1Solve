#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	cin >> str;

	char wolf[4] = { 'w','o','l','f' };
	int index = 0;
	while (index < str.size())
	{
		int n = 0;
		for (int i = index; i < str.size(); i++) // 단어별 n의 개수 찾기
		{
			if (str[i] == 'o')
			{
				n = (i - index);
				break;
			}
			else if (str[i] == 'l' || str[i] == 'f')
			{
				cout << 0;
				return 0;
			}
		}
		if (n == 0 || (index + n * 4 > str.size()))
		{
			cout << 0;
			return 0;
		}
		for (int i = index; i < index + (n * 4); i++)  // 단어가 순서대로 되어 있는지
		{
			if (str[i] != wolf[(i - index) / n])
			{
				cout << 0;
				return 0;
			}
			i += (n - 1);
		}
		index += (n * 4);
	}
	cout << 1;
	
	return 0;
}