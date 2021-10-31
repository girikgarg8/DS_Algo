#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<int>> mp;
    map<int, bool> visited;
    map<int, int> indegree;
    queue<int> q1;

public:
    void addEdge(int x, int y)
    {
        mp[x].push_back(y);
    }
    void calculateIndegree()
    {
        for (auto u : mp)
        {
            for (auto z : u.second)
            {
                indegree[z]++;
            }
        }
    }
    void TopologicalSort()
    {
        calculateIndegree();
        for (auto u : mp)
        {
            if (indegree[u.first] == 0)
            {
                q1.push(u.first);
            }
        }
        while (!q1.empty())
        {
            int a = q1.front();
            cout << a << " ";
            q1.pop();
            for (auto ngbr : mp[a])
            {
                indegree[ngbr]--;
                if (indegree[ngbr] == 0)
                {
                    q1.push(ngbr);
                }
            }
        }
    }
};
int main()
{
    Graph g1;
    g1.addEdge(10, 20);
    g1.addEdge(60, 20);
    g1.addEdge(20, 50);
    g1.addEdge(20, 30);
    g1.addEdge(30, 40);
    g1.addEdge(70, 40);
    g1.addEdge(70, 80);
    g1.TopologicalSort();
    return 0;
}