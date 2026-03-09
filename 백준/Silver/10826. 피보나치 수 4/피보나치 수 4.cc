#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string ret = "";
	int carry = 0, index = 0;

	while (index < a.size() && index < b.size())
	{
		int num = (a[index] - '0') + (b[index] - '0') + carry;
		carry = num / 10;
		num %= 10;
		ret += char(num + '0');
		index++;
	}
	while (index < a.size())
	{
		int num = (a[index] - '0') + carry;
		carry = num / 10;
		num %= 10;
		ret += char(num + '0');
		index++;
	}
	while (index < b.size())
	{
		int num = (b[index] - '0') + carry;
		carry = num / 10;
		num %= 10;
		ret += char(num + '0');
		index++;
	}

	if (carry > 0)
		ret += char(carry + '0');

	reverse(ret.begin(), ret.end());
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<string> fibo(n + 1, "0");
	if (n != 0)
	{
		fibo[1] = "1";
		for (int i = 2; i <= n; i++)
			fibo[i] = add(fibo[i - 1], fibo[i - 2]);
	}
	cout << fibo[n];

	return 0;
}