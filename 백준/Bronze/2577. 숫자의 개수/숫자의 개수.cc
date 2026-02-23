#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	int ret = a * b * c;
	string str = to_string(ret);
	vector<int> vect(11, 0);
	for (int i = 0; i < str.size(); i++)
	{
		int index = str[i] - '0';
		vect[index]++;
	}
	for (int i = 0; i < 10; i++)
		cout << vect[i] << '\n';

	return 0;
}