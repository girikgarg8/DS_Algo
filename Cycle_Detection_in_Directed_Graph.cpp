#include <iostream>
#include <map>
#include <list>
using namespace std;
class Graph
{
    map<int, list<int>> mp;
    // map <int,bool> visited;
    map<int, int> flag;
    bool containsCycleflag;

public:
    Graph()
    {
        containsCycleflag = false;
    }
    void addEdge(int a, int b)
    {
        mp[a].push_back(b);
    }
    void DFS_helper(int src)
    {
        flag[src] = 1;
        int y;
        for (auto x : mp[src])
        {
            if (flag[x] == 0)
            {
                y = x;
                DFS_helper(x);
            }
            else if (flag[x] == 1)
            {
                containsCycleflag = true;
            }
        }
        flag[y] = 2;
    }
    void DFS()
    {
        for (auto u : mp)
        {
            if (flag[u.first] == 0)
            {
                DFS_helper(u.first);
            }
        }
    }
    bool containsCycle()
    {
        DFS();
        return containsCycleflag;
    }
};
int main()
{
    Graph g1;
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 5);
    g1.addEdge(3, 1);
    g1.addEdge(1, 4);
    cout << g1.containsCycle() << endl;
    Graph g2;
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 5);
    g2.addEdge(1, 4);
    cout << g2.containsCycle() << endl;
    return 0;
}