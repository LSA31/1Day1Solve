#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> vect(n);
	for (int i = 0; i < n; i++) // 종료 시간을 정렬 우선으로 하기 위해 second:시작 시간/first:종료 시간
	{
		cin >> vect[i].second;
		cin >> vect[i].first;
	}
	sort(vect.begin(), vect.end());

	int cnt = 0, end = 0;
	for (int i = 0; i < n; i++)
	{
		if (vect[i].second >= end) // 현재 회의 시작 시간이 앞에 회의 종료 시간 이상이면
		{
			cnt++;
			end = vect[i].first;
		}
	}
	cout << cnt;
}