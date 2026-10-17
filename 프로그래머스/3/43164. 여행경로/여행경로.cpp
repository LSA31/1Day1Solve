#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(string node, const vector<vector<string>> &tickets, vector<bool>& visited, vector<string>& answer)
{
    if(answer.size() == tickets.size()+1)
        return true;
    
    for(int i=0; i<tickets.size(); i++)
    {
        if((!visited[i]) && node == tickets[i][0])
        {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            
            if(DFS(tickets[i][1], tickets, visited, answer))
                return true;
            
            visited[i] = false;
            answer.pop_back();
        }
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    
    vector<bool> visited(tickets.size(), false);
    
    answer.push_back("ICN");
    DFS("ICN", tickets, visited, answer);
    
    return answer;
}