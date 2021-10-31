#include <bits/stdc++.h>
using namespace std;
class Graph{
    map <int,list<int> > mp;
    map <int,bool> visited;
    queue <int> q1;
    public:
    void addEdge(int a,int b,bool isBidirectional=true){
        mp[a].push_back(b);
        if (isBidirectional){
            mp[b].push_back(a);
        }
    }
    void BFS(int src){
        q1.push(src);
        visited[src]=true;
        while (!q1.empty()){
            int a=q1.front();
            q1.pop();
            for (auto u:mp[a]){
                if (!visited[u]){
                q1.push(u);
                visited[u]=true;
                }
            }
        }
    }
    int numOfConnectedComponents(){
        int num=0;
        for (auto x:mp){
            if (!visited[x.first]){
                num++;
                BFS(x.first);
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