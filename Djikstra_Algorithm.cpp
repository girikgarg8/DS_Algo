#include <iostream>
#include <map>
#include <list>
#include <set>
#include <climits>
using namespace std;
class Graph
{
    map<int, list<pair<int, int>>> mp;
    map<int, int> distance;
    set<pair<int, int>> s1;

public:
    void addEdge(int a, int b, int weight, bool isBidirectional = true)
    {
        mp[a].push_back(make_pair(b, weight));
        if (isBidirectional)
        {
            mp[b].push_back(make_pair(a, weight));
            distance[b] = INT_MAX;
        }
        distance[a] = INT_MAX;
    }
    void print(int src)
    {
        for (auto u : mp)
        {
            cout << "Distance of " << u.first << "from " << src << "is " << distance[u.first] << endl;
        }
    }
    void Djisktras_Algorithm(int src)
    {
        distance[src] = 0;
        s1.insert(make_pair(0, src));
        int src1 = src;
        while (!s1.empty())
        {
            auto u = *(s1.begin());
            int node = u.second;
            int DistOfCurrNodeFromSrc = u.first;
            s1.erase(s1.begin());
            for (auto ngbr : mp[node])
            {
                int neigbourNode = ngbr.first;
                int Edgelength = ngbr.second;
                if (distance[neigbourNode] > DistOfCurrNodeFromSrc+Edgelength)
                {
                    auto r = s1.find(make_pair(distance[neigbourNode], neigbourNode));
                    if (r != s1.end())
                    {
                        s1.erase(r);
                    }
                    distance[neigbourNode] = DistOfCurrNodeFromSrc + Edgelength;
                    s1.insert(make_pair(distance[neigbourNode], neigbourNode));
                }
            }
        }
        print(src);
    }
};
int main()
{
    Graph g1;
    g1.addEdge(1, 2, 1);
    g1.addEdge(2, 3, 1);
    g1.addEdge(3, 4, 2);
    g1.addEdge(4, 1, 7);
    g1.addEdge(3, 1, 4);
    g1.Djisktras_Algorithm(1);
    return 0;
}