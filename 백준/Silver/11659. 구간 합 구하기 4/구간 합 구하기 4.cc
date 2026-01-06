#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<int>vect(N + 1);
	vect[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> vect[i];

		vect[i] += vect[i - 1];
	}
	for (int i = 0; i < M; i++)
	{
		int start = 0, end = 0;
		cin >> start >> end;

		cout << vect[end] - vect[start - 1] << '\n';
	}
}