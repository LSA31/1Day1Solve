#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> vect(n, 0);
	
	int start = 0, end = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> vect[i];

		if (start < vect[i]) // 시작 인덱스: 레슨 최댓값
			start = vect[i];
		end += vect[i]; // 종료 인덱스: 레슨시간 총합
	}
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0, count = 0; // 레슨시간 합, 사용한 블루레이 개수

		for (int i = 0; i < n; i++)
		{
			if (sum + vect[i] > mid) // 현재값을 더했을 때 중간값보다 크면 새로운 블루레이로 교체
			{
				count++;
				sum = 0;
			}
			sum += vect[i]; 
		}
		if (sum != 0)
			count++;
		if (count > m)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << start;
}