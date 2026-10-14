#include <string>
#include <vector>

using namespace std;

int cnt;

void DFS(int index, int sum, int target, vector<int> numbers)
{
    if(index == numbers.size())
    {
        if(sum == target)
            cnt++;
        
        return;
    }
    DFS(index+1, sum+numbers[index], target, numbers);
    DFS(index+1, sum-numbers[index], target, numbers);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(0, 0, target, numbers);
    
    answer = cnt;
    
    return answer;
}