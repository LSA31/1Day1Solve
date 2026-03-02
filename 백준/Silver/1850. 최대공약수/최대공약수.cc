#include <iostream>
using namespace std;

typedef long long ll;

int GCD(ll a, ll b)
{
	if (a % b == 0)
		return b;
	else
		return GCD(b, a % b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a = 0, b = 0;
	cin >> a >> b;

	ll gcd = GCD(a, b);
	for (ll i = 0; i < gcd; i++)
		cout << 1;
}