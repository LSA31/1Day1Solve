#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	long ret = 0;
	cin >> N >> M;

	vector<long> vect(N + 1, 0);
	vector<long> cnt(M, 0);  // 같은 나머지를 갖는 인덱스 카운트
	for (int i = 1; i <= N; i++)
	{
		cin >> vect[i];

		vect[i] += vect[i - 1];  // 구간합 구하기
		vect[i] %= M;  // 나머지 연산

		cnt[vect[i]]++;

		if (vect[i] == 0)
			ret++;
	}
	for (int i = 0; i < M; i++)
	{
		if (cnt[i] == 0)
			continue;
		
		ret += (cnt[i] * (cnt[i] - 1) / 2);  // 나머지 값이 같은 원소들 중 2개를 뽑는 경우
	}
	cout << ret;
}