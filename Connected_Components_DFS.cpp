#include <bits/stdc++.h>
using namespace std;
class Graph{
    map <int,list<int> > mp;
    map <int,bool> visited;
    public:
    void addEdge(int a,int b, bool isBidirectional=true){
        mp[a].push_back(b);
        if (isBidirectional){
            mp[b].push_back(a);
        }
    }
    void DFS(int src){
        visited[src]=true;
        for (auto u:mp[src]){
            if (!visited[u])
            DFS(u);
        }
    }
    int numOfConnectedComponents(){
        int num=0;
        for (auto u:mp){
            if (!visited[u.first]){
            num++;
            DFS(u.first);
        }
    }
    return num;
    }
};
int main(){
    Graph g1;
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(0,3);
    g1.addEdge(4,5);
    g1.addEdge(6,7);
    g1.addEdge(7,8);
    g1.addEdge(8,9);
    g1.addEdge(6,9);
    g1.addEdge(7,10);
    cout << "Number of connected components are " << g1.numOfConnectedComponents() ;
    return 0;
}