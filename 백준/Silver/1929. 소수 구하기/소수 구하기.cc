#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	
	vector<int> vect(b + 1);

	for (int i = 2; i <= b; i++)
	{
		vect[i] = i;
	}
	for (int i = 2; i <= sqrt(b); i++) // 배열의 제곱근까지 반복
	{
		if (vect[i] == 0)
			continue;

		for (int j = i + i; j <= b; j += i) // i의 배수들 0 (삭제)
		{
			vect[j] = 0;
		}
	}
	for (int i = a; i <= b; i++)
	{
		if (vect[i] != 0)
			cout << i << '\n';
	}
}