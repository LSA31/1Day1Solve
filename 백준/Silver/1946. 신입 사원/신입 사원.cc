#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case = 0;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int n = 0;
		cin >> n;

		vector<pair<int, int>> score(n);
		for (int i = 0; i < n; i++)
			cin >> score[i].first >> score[i].second;

		sort(score.begin(), score.end());

		int cnt = 1, Min = score[0].second;
		for (int i = 1; i < n; i++)
		{
			if (score[i].second < Min)
			{
				Min = score[i].second;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}