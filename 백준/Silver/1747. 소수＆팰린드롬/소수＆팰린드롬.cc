#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // reverse
using namespace std;

typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LL n = 0;
	cin >> n;

	vector<int> vect(1003002, 0);
	for (int i = 0; i < vect.size(); i++)
		vect[i] = i;
	for (int i = 2; i < vect.size(); i++)  // 에라토스테네스의 체
	{
		if (vect[i] != -1)
		{
			for (int j = i * 2; j < vect.size(); j += i)
			{
				vect[j] = -1;
			}
		}
	}
	vect[0] = -1;
	vect[1] = -1;
	for (LL i = n; i < vect.size(); i++)
	{
		if (vect[i] != -1)
		{
			string str = to_string(vect[i]);
			string rev = str;
			reverse(rev.begin(), rev.end());

			if (str == rev)
			{
				cout << vect[i];
				return 0;
			}
		}
	}

	return 0;
}