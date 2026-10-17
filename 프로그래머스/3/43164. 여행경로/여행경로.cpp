#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> visited;

int find_index(const string& str, const vector<vector<string>>& graph)
{
    for(int i=0; i<graph.size(); i++)
    {
        if(str == graph[i][0])
            return i;
    }
    return -1;
}
bool DFS(string node, const vector<vector<string>>& graph, const vector<vector<string>>& tickets, vector<string>& answer)
{
    if(answer.size() == tickets.size()+1)
        return true;
    
    int index = find_index(node, graph);
    
    if(index == -1)
        return false;
    
    for(int i=1; i<graph[index].size(); i++)
    {
        if(!visited[index][i])
        {
            visited[index][i] = true;
            answer.push_back(graph[index][i]);
            
            if(DFS({graph[index][i]}, graph, tickets, answer))
                return true;
            
            visited[index][i] = false;
            answer.pop_back();
        }
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    vector<vector<string>> graph;
    for(int i=0; i<tickets.size(); i++)
    {
        int index = find_index(tickets[i][0], graph);
        
        if(index == -1)
        {
            graph.push_back({tickets[i][0]});
            graph[graph.size()-1].push_back({tickets[i][1]});
        }
        else
            graph[index].push_back({tickets[i][1]});
    }
    visited.assign(graph.size(), vector<bool> ());
    for(int i=0; i<graph.size(); i++)
    {
        visited[i].assign(graph[i].size()+1, false);
    }
    for(int i=0; i<graph.size(); i++)
    {
        sort(graph[i].begin()+1, graph[i].end());
    }
    
    answer.push_back("ICN");
    DFS("ICN", graph, tickets, answer);
    
    return answer;
}