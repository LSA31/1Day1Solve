#include <iostream>
using namespace std;

int main()
{
	int n;
	int arr[1000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	double sum = 0;
	double Max = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > Max)
			Max = arr[i];
		sum += arr[i];
	}
	cout << sum * 100 / Max / n;
}