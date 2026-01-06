#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& vect, int i, int j)
{
	swap(vect[i], vect[j]);
}
int partition(vector<int>& vect, int start, int end)
{
	if (start + 1 == end) // 그룹 내의 수가 두개일 때
	{
		if (vect[start] > vect[end])
			swap(vect, start, end);
		return end;
	}
	int middle = (start + end) / 2;
	swap(vect, start, middle);
	
	int pivot = vect[start];
	int i = start + 1, j = end;

	while (i <= j)
	{
		while (start + 1 <= j && pivot < vect[j])
			j--;
		while (i <= end && vect[i] < pivot)
			i++;
		if (i < j)
			swap(vect, i++, j--);
		else
			break;
	}
	vect[start] = vect[j]; // 피벗의 값을 분리된 가운데에 오도록 바꿔주기
	vect[j] = pivot;
	return j;
}
void quicksort(vector<int>& vect, int start, int end, int k)
{
	int pivot = partition(vect, start, end);
	if (pivot == k)
		return;
	else if (k < pivot) // k가 pivot보다 작으면 왼쪽 그룹 quicksort
		quicksort(vect, start, pivot - 1, k);
	else  // 오른쪽 그룹 quicksort
		quicksort(vect, pivot + 1, end, k);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> vect(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	quicksort(vect, 0, n - 1, k - 1);

	cout << vect[k - 1];
}