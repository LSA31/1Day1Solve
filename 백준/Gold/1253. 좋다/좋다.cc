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

	vector<int>vect(N, 0);
	for (int i = 0; i < N; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	int count = 0;
	for (int k = 0; k < N; k++)
	{
		int find = vect[k];
		int start = 0, end = N - 1;
		
		while (start < end)
		{
			if (vect[start] + vect[end] == find)
			{
				if (start != k && end != k)
				{
					count++;
					break;
				}
				else if (start == k)
					start++;
				else if (end == k)
					end--;
			}
			else if (vect[start] + vect[end] < find)
				start++;
			else if (vect[start] + vect[end] > find)
				end--;
		}
	}
	cout << count;
}