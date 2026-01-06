#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long arr[10000001];

bool isPalindrom(int target)
{
	string str = to_string(target); // 정수형 문자열로 변환
	vector<char> vect(str.length() + 1);
	for (int i = 0; i < str.length(); i++) // 문자열 배열로 변환
		vect[i] = str[i];

	int s = 0, e = str.length() - 1;
	while (s < e)
	{
		if (vect[s] != vect[e])
			return false;

		s++;
		e--;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 2; i < 10000001; i++)
		arr[i] = i;

	for (int i = 2; i <= sqrt(10000001); i++)
	{
		if (arr[i] == 0)
			continue;

		for (int j = i + i; j < 10000001; j += i)
		{
			arr[j] = 0;
		}
	}
	int i = n;
	while (true)
	{
		if (arr[i] != 0)
		{
			if (isPalindrom(arr[i]))
			{
				cout << arr[i];
				break;
			}
		}
		i++;
	}
}