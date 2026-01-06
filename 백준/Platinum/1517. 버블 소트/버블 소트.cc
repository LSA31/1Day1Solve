#include <iostream>
#include <vector>
using namespace std;

vector<int> vect;
vector<int> tmp;  // 임시 배열
long result;

void mergeSort(int start, int end)
{
	if (end - start < 1)
		return;

	int M = (start + end) / 2;
	mergeSort(start, M);
	mergeSort(M + 1, end);

	for (int i = start; i <= end; i++)
		tmp[i] = vect[i];

	int i = start;
	int index1 = start, index2 = M + 1;
	while (index1 <= M && index2 <= end)
	{
		if (tmp[index1] > tmp[index2])
		{
			vect[i] = tmp[index2];
			result += (index2 - i);  // 이동한 index 크기 = swap이 일어난 횟수
			i++;
			index2++;
		}
		else
			vect[i++] = tmp[index1++];
	}
	while (index1 <= M)
		vect[i++] = tmp[index1++];
	while (index2 <= end)
		vect[i++] = tmp[index2++];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vect = vector<int>(n + 1, 0);
	tmp = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> vect[i];

	mergeSort(1, n);

	cout << result << '\n';
}