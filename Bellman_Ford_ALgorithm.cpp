#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<pair<int, int>>> mp;
    map<int, int> distance;
    int numOfVertices;

public:
    Graph()
    {
        numOfVertices = 0;
    }
    void addEdge(int a, int b, int weight, bool isBidirectional = true)
    {
        mp[a].push_back(make_pair(b, weight));
        distance[a] = INT_MAX;
        distance[b] = INT_MAX;
        if (isBidirectional)
        {
            mp[b].push_back(make_pair(a, weight));
        }
        numOfVertices += 2;
    }
    void print(int src)
    {
        for (auto u : distance)
        {
            cout << "Distance of " << u.first << " from " << src << " is " << u.second << endl;
        }
    }
    void BellMan_Ford_Algo(int src)
    {
        distance[src] = 0;
        for (int i = 0; i < numOfVertices - 1; i++)
        {
            for (auto u : mp)
            {
                for (auto a : mp[u.first])
                {
                    int node = a.first;
                    int weight = a.second;
                    if (distance[u.first] != INT_MAX && distance[u.first] + weight < distance[node])
                    {
                        distance[node] = distance[u.first] + weight;
                    }
                    //distance[u]!=INT_MAX is needed in case the edge u is unreachable from src vertex
                }
            }
        }
        bool flag = false;
        //Negative edge cycle detection
        for (auto u : mp)
        {
            for (auto a : mp[u.first])
            {
                int node = a.first;
                int weight = a.second;
                if (distance[u.first] != INT_MAX && distance[u.first] + weight < distance[node])
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false)
        {
            print(src);
        }
        else
        {
            cout << "Negative edge cycle is present";
        }
    }
};
int main()
{
    Graph g1;
    g1.addEdge(10, 20, 6, false);
    g1.addEdge(10, 30, 4, false);
    g1.addEdge(10, 40, 5, false);
    g1.addEdge(20, 50, -1, false);
    g1.addEdge(30, 20, -2, false);
    g1.addEdge(30, 50, 3, false);
    g1.addEdge(40, 30, -2, false);
    g1.addEdge(40, 60, -1, false);
    g1.addEdge(50, 60, 3, false);
    g1.BellMan_Ford_Algo(10);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
class Graph{
    map <int,list <pair<int,int> > >mp;
    map <int,int> distance;
    int numOfVertices;
    public:
    Graph(){
        numOfVertices=0;
    }
    void addEdge(int a,int b,int weight, bool isBidirectional=true){
        mp[a].push_back(make_pair(b,weight));
        distance[a]=INT_MAX;
        distance[b]=INT_MAX;
        if (isBidirectional){
            mp[b].push_back(make_pair(a,weight));
        }
        numOfVertices+=2;
    }
    void print(int src){
        for (auto u:distance){
            cout << "Distance of " << u.first << " from " << src << " is " << u.second <<endl;
        }
    }
    void BellMan_Ford_Algo(int src){
        distance[src]=0;
        for (int i=0;i<numOfVertices-1;i++){
            for (auto u:mp){
                for (auto a:mp[u.first]){
                    int node=a.first;
                    int weight=a.second;
                    if (distance[u.first]!=INT_MAX && distance[u.first]+weight<distance[node]){
                        distance[node]=distance[u.first]+weight;
                    }
                    //distance[u]!=INT_MAX is needed in case the edge u is unreachable from src vertex
                }
            }
        }
        bool flag=false;
        //Negative edge cycle detection
        for (auto u:mp){
            for (auto a:mp[u.first]){
                int node=a.first;
                int weight=a.second;
                if (distance[u.first]!=INT_MAX && distance[u.first]+weight<distance[node]){
                    flag=true;
                    break;
                }
            }
        }
        if (flag==false){
            print(src);
        }
        else{
            cout << "Negative edge cycle is present";
        }
    }
};
int main(){
    Graph g1;
    g1.addEdge(10,20,6,false);
    g1.addEdge(30,10,4,false);
    g1.addEdge(20,30,-12,false);
    g1.BellMan_Ford_Algo(10);
    return 0;
}*/