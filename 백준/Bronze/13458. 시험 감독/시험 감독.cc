#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int>A(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int B = 0, C = 0;
	cin >> B >> C;

	long long ret = 0;
	for (int i = 0; i < N; i++)
	{
		long long cnt = 1;
		if (A[i] - B > 0)
		{
			A[i] -= B;

			if (A[i] < C)
				cnt += 1;
			else
			{
				cnt += A[i] / C;

				if (A[i] % C != 0)
					cnt += 1;
			}
		}
		ret += cnt;
	}
	cout << ret;

	return 0;
}