#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double h = 0, w = 0, n = 0, m = 0;
	cin >> h >> w >> n >> m;

	cout << (int)ceil(h / (n + 1)) * (int)ceil(w / (m + 1));

	return 0;
}