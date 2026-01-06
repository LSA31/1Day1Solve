#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int alphabet[26] = { 0, };
	string str = "";
	cin >> str;

	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;

	for (int i = 0; i < str.size(); i++)
	{
		int index = str[i] - 'a';
		if (alphabet[index] == -1)
			alphabet[index] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << ' ';

	return 0;
}