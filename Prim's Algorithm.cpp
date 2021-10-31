#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<pair<int, int>> > mp;
    map<int, bool> visited;
    int cost;
    set<pair<int, int>> s1;
public:
    Graph()
    {
        cost = 0;
    }
    void addEdge(int a,int b,int weight,bool isBidirectional=true){
        mp[a].push_back(make_pair(b,weight));
        if (isBidirectional){
            mp[b].push_back(make_pair(a,weight));
        }
    }
    int Prims_Algorithm(int src)
    {
        s1.insert(make_pair(0, src));
        visited[src]=true;
        while (!s1.empty())
        {
            auto x = *(s1.begin());
            int node=x.second;
            int weightOfCurrentNode=x.first;
            if (visited[node]==false){
                cost+=weightOfCurrentNode;
                visited[node]=true;
            }
            s1.erase(s1.begin());
            for (auto u :mp[node]){
                if (visited[u.first]==false){
                    s1.insert(make_pair(u.second,u.first));
                }
            } 
        }
        return cost;
    }
};
int main(){
    Graph g1;
    g1.addEdge(0,2,2);
    g1.addEdge(0,3,2);
    g1.addEdge(1,2,2);
    g1.addEdge(2,3,3);
    g1.addEdge(3,1,2);
    g1.addEdge(1,0,1);
    cout << "Minimum cost of the MST is " << g1.Prims_Algorithm(0);
    return 0;
}