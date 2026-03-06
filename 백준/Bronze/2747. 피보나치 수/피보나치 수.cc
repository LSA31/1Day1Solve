#include <iostream>
#include <vector>
using namespace std;

vector<int> vect;

void fibonacci(int n)
{
	vect[1] = 1;

	for (int i = 2; i <= n; i++)
		vect[i] = (vect[i - 1] + vect[i - 2]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vect.resize(n + 1, 0);

	fibonacci(n);

	cout << vect[n];
}