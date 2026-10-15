#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<bool> visited;

bool canChange(string a, string b)
{
    int diff = 0;
    
    for(int i=0; i<a.size(); i++)
    {
        if(a[i] != b[i])
            diff++;
        if(diff > 1)
            return false;
    }
    return diff == 1;
}
int BFS(string begin, string target, vector<string> words)
{
    queue<pair<string, int>> Q;
    
    Q.push({begin, 0});
    
    while(!Q.empty())
    {
        string now = Q.front().first;
        int depth = Q.front().second;
        Q.pop();
        
        for(int i=0; i<words.size(); i++)
        {
            if(!visited[i])
            {
                bool change = canChange(now, words[i]);
                if(change)
                {
                    Q.push({words[i], depth+1});
                    visited[i] = true;
                    
                    if(words[i] == target)
                        return depth + 1;
                }
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool exist = find(words.begin(), words.end(), target) != words.end();
    if(!exist)
        return 0;
    
    visited.assign(words.size(), false);
    
    answer = BFS(begin, target, words);
    
    return answer;
}