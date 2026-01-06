#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	queue<int> Q;
	for (int i = 1; i <= n; i++)
		Q.push(i);

	while (Q.size() > 1)
	{
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}
	cout << Q.front();
}