#include <bits/stdc++.h>
using namespace std;
class Graph{
    map <int,list<int> > m1;
    queue <int> q1;
    map <int,bool> visited;
    map <int,int> distance;
    
    public:
    void addEdge(int a,int b,bool isBidirectional=true){
        m1[a].push_back(b);
        if (isBidirectional){
            m1[b].push_back(a);
        }
    }
    void SSSP(int src){
        q1.push(src);
        visited[src]=true;
        distance[src]=0;
        while (!q1.empty()){
            cout << "Distance of " << q1.front() << " from "<< src << " is " <<distance [q1.front()] <<endl;
            int a=q1.front();
            q1.pop();
            for (auto u:m1[a]){
                if (!visited[u]){
                    q1.push(u);
                    visited[u]=true;
                    distance[u]=distance[a]+1;
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
    g1.SSSP(10);
    return 0;
}
