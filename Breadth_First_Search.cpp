#include <bits/stdc++.h>
using namespace std;
class Graph{
    map <int,list<int> > m1;
    queue <int> q1;
    map <int,bool> visited;
    public:
    void addEdge(int a,int b,bool isBidirectional=true){
        m1[a].push_back(b);
        if (isBidirectional){
            m1[b].push_back(a);
        }
    }
    void BFS(int src){
        q1.push(src);
        visited[src]=true;
        while (!q1.empty()){
            cout << q1.front() << " ";
            int a=q1.front();
            q1.pop();
            for (auto u:m1[a]){
                if (!visited[u]){
                    q1.push(u);
                    visited[u]=true;
                }
            }
        }
    }
};
int main(){
    Graph g1;
    g1.addEdge(10,20);
    g1.addEdge(20,40);
    g1.addEdge(10,30);
    g1.addEdge(30,40);
    g1.addEdge(40,50);
    g1.addEdge(30,60);
    g1.BFS(10);
    return 0;
}