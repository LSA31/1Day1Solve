#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	string aa = to_string(a);
	string bb = to_string(b);
	aa += bb;
	int sum = stoi(aa) - c;

	cout << a + b - c << '\n' << sum;
}