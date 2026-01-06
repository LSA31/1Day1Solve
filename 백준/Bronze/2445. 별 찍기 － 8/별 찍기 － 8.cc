#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int y = 1; y <= n; y++)  //상단 부분 별 찍기
	{
		for (int star = 1; star <= y; star++)
			cout << '*';
		for (int jump = 1; jump <= (n - y) * 2; jump++)
			cout << ' ';
		for (int star = 1; star <= y; star++)
			cout << '*';

		cout << endl;
	}
	for (int y = n - 1; y > 0; y--)
	{
		for (int star = 1; star <= y; star++)
			cout << '*';
		for (int jump = 1; jump <= (n - y) * 2; jump++)
			cout << ' ';
		for (int star = 1; star <= y; star++)
			cout << '*';

		if (y != 1)
			cout << endl;
	}
}