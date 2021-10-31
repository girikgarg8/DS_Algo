//DSU with union by rank and path compression algorithm
#include <bits/stdc++.h>
using namespace std;
class Graph{
    list <pair<int,int> > l1;
    int *parent;
    int *rank;
    int V;
    public:
    Graph(int V){
        this->V=V;
        parent=new int[V];
        rank=new int[V];
        for (int i=0;i<V;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int a){
        if (parent[a]==-1){
            return a;
        }
        return parent[a]=find(parent[a]);
    }
    void union_of_sets(int x,int y){
        int s1=find(x);
        int s2=find(y);
        if (s1!=s2){
            int a=rank[s1];
            int b=rank[s2];
            if (a>=b){
            parent[s2]=s1;
            rank[s2]+=b;
        }
        else if (a<b){
            parent[s1]=s2;
            rank[s1]+=a;
        }
    }
    }
    void addEdge(int x,int y){
        l1.push_back(make_pair(x,y));
    }
    bool contains_cycle(){
        for (auto u:l1){
            int a=u.first;
            int b=u.second;
            int x=find(a);
            int y=find(b);
            if (x==y){
                return true;
            }
            else if (x!=y){
                union_of_sets(x,y);
            }
        }
        return false;
    }
};