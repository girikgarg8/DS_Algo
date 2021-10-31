// #include <bits/stdc++.h>
// using namespace std;
// class Graph{
//     map <int,list<int> > mp;
//     map <int,bool> visited;
//     stack <int> s1;
//     public:
//     void addEdge(int a,int b,bool isBidirectional=false){
//         mp[a].push_back(b);
//         if (isBidirectional){
//             mp[b].push_back(a);
//         }
//     }
//     void TopologicalSortingUsingDFS(){
//         for (auto u:mp){
//             for (auto j:u.second){
//                 if (!visited[j]){
//                     visited[j]=true;
//                     s1.push(j);
//                 }
//             }
//             }
//         }
//     while (!s1.empty()){
//         cout << s1.top() << " ";
//         s1.pop();
//     }
//     }
// };
// int main(){
//     Graph g1;
//     g1.addEdge(5,0);
//     g1.addEdge(5,2);
//     g1.addEdge(2,3);
//     g1.addEdge(3,1);
//     g1.addEdge(4,1);
//     g1.addEdge(4,0);
//     g1.TopologicalSortingUsingDFS();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    map <int,list <int> > mp;
    map <int,bool> visited;
    list <int> l1;
    void addEdge(int x,int y){
        mp[x].push_back(y);
    }
    void DFS_helper(int src){
        visited[src]=true;
        for (auto ngbr:mp[src]){
            if (visited[ngbr]==false){
                DFS_helper(ngbr);
            }
        }
        l1.push_front(src);
    }
    void DFS(){
        for (auto u:mp){
            if (visited[u.first]==false){
                DFS_helper(u.first);
            }
        }
        print();
    }
    void print(){
        cout << "Topolgogical sort ordering is ";
        for (auto u:l1){
            cout << u << " ";
        }
    }
};
int main(){
    Graph g1;
    g1.addEdge(9,10);
    g1.addEdge(9,7);
    g1.addEdge(7,6);
    g1.addEdge(10,7);
    g1.addEdge(10,12);
    g1.addEdge(10,11);
    g1.addEdge(8,10);
    g1.addEdge(8,3);
    g1.addEdge(7,6);
    g1.addEdge(6,11);
    g1.addEdge(11,13);
    g1.addEdge(12,13);
    g1.addEdge(3,13);
    g1.DFS();
    return 0;    
    }