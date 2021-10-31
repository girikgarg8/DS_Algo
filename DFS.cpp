#include <bits/stdc++.h>
using namespace std;
class Graph{
    map <int,list<int> > mp;
    map <int,bool> visited;
    public:
    void addEdge(int a,int b,bool isBidirectional=true){
        mp[a].push_back(b);
        if (isBidirectional){
            mp[b].push_back(a);
        }
    }
    public:
    void DFS(int src){
        DFS(src);
        visited[src]=true;
        cout << src << " ";
        for (auto u:mp[src]){
            if (!visited[u]){
                DFS(u);
            }
        }
    }
};
int main(){
    Graph g1;
    g1.addEdge(10,20);
    g1.addEdge(20,50);
    g1.addEdge(20,40);
    g1.addEdge(40,60);
    g1.addEdge(10,30);
    g1.addEdge(30,40);
    g1.addEdge(30,80);
    g1.addEdge(40,70);
    g1.addEdge(40,60);
    g1.DFS(10);
    return 0;
}