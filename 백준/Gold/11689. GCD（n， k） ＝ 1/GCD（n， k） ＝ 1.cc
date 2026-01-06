#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n;
	cin >> n;

	long ret = n;
	for (long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) // i가 소인수인지 확인
		{
			ret = ret - ret / i; // 결괏값 업데이트

			while (n % i == 0) // 해당 소인수 지우기
				n /= i;
		}
	}
	if (n > 1) // 아직 소인수 구성이 남아있는 경우
		ret = ret - ret / n;

	cout << ret;
}