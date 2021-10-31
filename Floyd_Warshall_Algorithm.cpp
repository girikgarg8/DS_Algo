#include <bits/stdc++.h>
#define INF 999
using namespace std;
class Graph
{
public:
    int V;
    int **adj;
    Graph(int num)
    {
        V = num;
    }
    void FloydWarshallAlgorithm(int adj[][4])
    {
        int ans[V][V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                ans[i][j] = adj[i][j];
            }
        }
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                for (int k = 0; k < V; k++)
                {
                    if (ans[j][k] > ans[j][i] + ans[i][k])
                        ans[j][k] = ans[j][i] + ans[i][k];
                }
            }
        }
        for (int x = 0; x < V; x++)
        {
            for (int y = 0; y < V; y++)
            {
                cout << ans[x][y] << " ";
            }
            cout << endl;
        }
        //Check for negative edge weight cycle
        for (int i = 0; i < V; i++)
        {
            if (ans[i][i] < 0)
            {
                cout << "Negative edge weight cycle is present" << endl;
                break;
            }
        }
    }
};
int main()
{
    Graph g1(4);
    int mat[4][4] = {{0, 3, INF, 5}, {2, 0, INF, 4}, {INF, 1, 0, INF}, {INF, INF, 2, 0}};
    g1.FloydWarshallAlgorithm(mat);
    return 0;
}