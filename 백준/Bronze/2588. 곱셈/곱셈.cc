#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string m;
	cin >> n >> m;

	int arr[3];
	for (int i = 2; i >= 0; i--)
	{
		arr[i] = m[i] - '0';

		cout << n * arr[i] << "\n";
	}
	int ret = stoi(m);
	cout << n * ret;
}