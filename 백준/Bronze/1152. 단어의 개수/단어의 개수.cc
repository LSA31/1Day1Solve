#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	getline(cin, str);

	if (str.size() == 1 && str == " ")
	{
		cout << 0;
		return 0;
	}
	int word = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 || i == str.size() - 1)
		{
			if (str[i] == ' ')
				continue;
		}
		if (str[i] == ' ')
			word++;
	}
	cout << word;

	return 0;
}