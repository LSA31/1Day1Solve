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

	vector<vector<int>> vect(N + 1, vector<int>(N + 1, 0));
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> vect[y][x];

			vect[y][x] = vect[y - 1][x] + vect[y][x - 1] - vect[y - 1][x - 1] + vect[y][x];  // 구간합 구하기
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << (vect[y2][x2] - vect[y1 - 1][x2] - vect[y2][x1 - 1] + vect[y1 - 1][x1 - 1]) << "\n";
	}
}