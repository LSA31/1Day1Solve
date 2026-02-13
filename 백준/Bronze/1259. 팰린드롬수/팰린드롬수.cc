#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	while (1)
	{
		cin >> str;

		if (str == "0") break;

		string rev = str;
		reverse(rev.begin(), rev.end());

		if (str == rev)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}