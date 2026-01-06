#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, L = 0;
	cin >> N >> L;

	typedef pair<int, int> Node;  // index, value
	deque<Node> mydeque;

	for (int i = 0; i < N; i++)
	{
		int now;
		cin >> now;

		// (deque가 비어있지 않을 때)now보다 큰 값 제거
		while (mydeque.size() && mydeque.back().second > now)  
			mydeque.pop_back();

		mydeque.push_back(Node(i, now));

		if (mydeque.front().first <= i - L)  // 범위ㅇ 벗어나면 첫 번째 노드 제거
			mydeque.pop_front();

		cout << mydeque.front().second << " ";
	}
}