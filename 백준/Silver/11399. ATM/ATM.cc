#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int> vect(N, 0);
	for (int i = 0; i < N; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	for (int i = 1; i < N; i++)
		vect[i] += vect[i - 1];

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += vect[i];

	cout << sum;

	return 0;
}