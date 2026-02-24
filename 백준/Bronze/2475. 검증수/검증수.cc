#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	cin >> a >> b >> c >> d >> e;

	int ret = (a * a + b * b + c * c + d * d + e * e) % 10;
	cout << ret;
}