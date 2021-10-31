#include <bits/stdc++.h>
using namespace std;
class Graph{
    map <int,list<int> > m1;
    queue <int> q1;
    map <int,bool> visited;
    map <int,int> distance;
    map <int,int> parent; //This map is needed when I want to find the path also
    public:
    void addEdge(int a,int b,bool isBidirectional=false){
        m1[a].push_back(b);
    if (isBidirectional){
        m1[b].push_back(a);
    }
    }
    void MinNumberOfMoves(int src,int dest){
        queue <int> q1;
        q1.push(src);
        visited[src]=true;
        distance[src]=0;
        while (!q1.empty()){
            int a=q1.front();
            if (a==dest){
                cout << "Minimum number of moves required are " << distance[dest] <<endl; 
                //To print the path, treat the dest as the source and use the parent map 
                int temp=dest;
                while (temp!=src){
                    cout << temp << "<--";
                    temp=parent[temp];
                }
                cout << src;
                return ;
            }
            else{
            q1.pop();
            for (auto u:m1[a]){
                if (!visited[u]){
                    q1.push(u);
                    visited[u]=true;
                    distance[u]=distance[a]+1;
                    parent[u]=a;
                }
            }
        } 
    }
    }
};
int main(){
    Graph g1;
    int SnakesAndLadders[50]{0};
    SnakesAndLadders[2]=13;
    SnakesAndLadders[5] = 2;
    SnakesAndLadders[9] = 18;
    SnakesAndLadders[18] = 11;
    SnakesAndLadders[25] = 10;
    SnakesAndLadders[17] = -13;
    SnakesAndLadders[24] = -8;
    SnakesAndLadders[20] = -14;
    SnakesAndLadders[32] = -2;
    SnakesAndLadders[34] = -22;
    for (int i=0;i<=36;i++){
        for (int j=1;j<=6;j++){
            g1.addEdge(i,i+j+SnakesAndLadders[i+j]);
        }
    }
    g1.MinNumberOfMoves(0,36);
    return 0;
}