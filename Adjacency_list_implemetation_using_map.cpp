#include <bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>> m1;
    public:
    void addEdge(int a,int b,bool isBidirectional=true){
        m1[a].push_back(b);
    if (isBidirectional){
        m1[b].push_back(a);
    }
    }
    void printAdjacencyList(){
        for (auto i:m1){
            cout << "Adjacency list of " << i.first << " is ";
            for (auto u:i.second){
                cout << u << " ";
            }
            cout <<endl;
        }
    }
};
int main(){
    Graph g1;
    g1.addEdge(10,20);
    g1.addEdge(20,30);
    g1.addEdge(30,40);
    g1.addEdge(40,20);
    g1.printAdjacencyList();
    return 0;
}