#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 나이트의 이동 방향
// 나이트는 한 번의 이동에서 두 칸 직진한 다음, 수직 방향으로 한 칸
// 또는, 한 칸 직진한 다음, 수직 방향으로 두 칸 이동함
const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };  // const: 값 변경 불가
const int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

// BFS 함수
int bfs(int n, int startX, int startY, int endX, int endY) {
    // 시작 위치와 목표 위치가 같으면 0 반환
    if (startX == endX && startY == endY) {
        return 0;
    }

    // 방문 여부 체크
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[startX][startY] = true;

    // BFS를 위한 큐: 현재 위치(x, y)와 이동 횟수
    queue<pair<pair<int, int>, int>> q;
    q.push({ {startX, startY}, 0 });

    while (!q.empty()) {
        int curX = q.front().first.first;  // 현재 X 좌표
        int curY = q.front().first.second;  // 현재 Y 좌표
        int moves = q.front().second;  // 현재 좌표까지 도달하는 데 걸린 이동 횟수
        q.pop();  // 이미 방문한 위치 제거

        // 8방향 이동
        for (int i = 0; i < 8; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            // 체스판 범위 내에 있고 아직 방문하지 않은 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                // 목표 위치에 도달하면 이동 횟수 반환
                if (nx == endX && ny == endY) {
                    return moves + 1;
                }
                visited[nx][ny] = true;
                q.push({ {nx, ny}, moves + 1 });
            }
        }
    }

    return -1; // 도달 불가능한 경우
}

int main() {
    int t;
    cin >> t; // 테스트 케이스 개수

    vector<int> results; // 결과 저장용 벡터

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; // 체스판 한 변의 길이

        int startX, startY, endX, endY;
        cin >> startX >> startY; // 나이트의 시작 위치
        cin >> endX >> endY;     // 나이트의 목표 위치

        // BFS 실행 후 결과 저장
        results.push_back(bfs(n, startX, startY, endX, endY));
    }

    // 결과 한 번에 출력
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}