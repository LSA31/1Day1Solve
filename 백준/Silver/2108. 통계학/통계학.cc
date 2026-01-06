// 통계학
// 반올림 round()

#include <iostream>
#include <cmath>  // 반올림 함수
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vect;
int check[8001];  

void Mean()
{
	double sum = 0;
	for (int i = 1; i <= N; i++)
		sum += vect[i];

	int mean = round(sum / N);

	cout << mean << '\n';
}
void Middle()
{
	sort(vect.begin() + 1, vect.end());

	cout << vect[(N + 1) / 2] << '\n';
}
void MAX()
{
	vector<int> tmp;
	int MAx = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (check[i] > MAx)
			MAx = check[i];
	}
	
	for (int i = 0; i <= 4000; i++)
	{
		if (check[i] == MAx)
			tmp.push_back(i);
	}
	for (int i = 4001; i <= 8000; i++)
	{
		if (check[i] == MAx)
			tmp.push_back(-1 * (i - 4000));
	}
	
	if (tmp.size() == 1)
		cout << tmp[0] << '\n';
	else
	{
		sort(tmp.begin(), tmp.end());
		cout << tmp[1] << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	vect.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> vect[i];

		if (vect[i] < 0)  // 음수는 4001~8000까지에 저장
			check[4000 - vect[i]]++;
		else
			check[vect[i]]++;
	}
	Mean();
	Middle();
	MAX();
	cout << vect[N] - vect[1];

	return 0;
}