#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vect(31, 0);
	for (int i = 0; i < 28; i++)
	{
		int index = 0;
		cin >> index;

		vect[index]++;
	}
	for (int i = 1; i <= 30; i++)
	{
		if (vect[i] == 0)
			cout << i << '\n';
	}
}