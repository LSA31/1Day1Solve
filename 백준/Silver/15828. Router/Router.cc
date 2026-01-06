#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n; // 라우터의 버퍼 크기
    cin >> n;

    queue<int> buffer; // 버퍼를 구현할 큐
    int packet;

    while (true) {
        cin >> packet; // 패킷 입력

        if (packet == -1) { // 입력 종료
            break;
        }

        if (packet == 0) { // 패킷 처리 요청
            if (!buffer.empty()) {
                buffer.pop(); // 큐의 앞에서 하나 제거
            }
        }
        else { // 새로운 패킷 입력
            if ((int)buffer.size() < n) { // 버퍼가 꽉 차지 않은 경우에만 추가
                buffer.push(packet);
            }
        }
    }

    // 남아있는 패킷 출력
    if (buffer.empty()) {
        cout << "empty" << endl;
    }
    else {
        while (!buffer.empty()) {
            cout << buffer.front() << " ";
            buffer.pop();
        }
        cout << endl;
    }

    return 0;
}
