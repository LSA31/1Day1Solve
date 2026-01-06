#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string croatia[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

	string str = "";
	cin >> str;

	int idx = 0, cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		while (1)
		{
			idx = str.find(croatia[i]);  // 찾은 부분의 첫 인덱스 값을 리턴
			if (idx == -1)
				break;

			str.replace(idx, croatia[i].size(), "#");  // replace 사용 시 큰따옴표 사용
		}
	}
	cout << str.size();

	return 0;
}