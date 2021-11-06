#include<bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

// check if the colored
// graph is safe or not
bool isSafe(bool graph[V][V], int color[])
{
	// check for every edge
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++) //the given graph is directed
			if (graph[i][j] && color[j] == color[i])
				return false;
	return true;
}

/* This function solves the m Coloring
problem using recursion. It returns
false if the m colours cannot be assigned,
otherwise, return true and prints
assignments of colours to all vertices.
Please note that there may be more than
one solutions, this function prints one
of the feasible solutions.*/
bool graphColoring(bool graph[V][V], int m, int i,
				int color[V])
{
	// if current index reached end
	if (i == V) {
	
		// if coloring is safe
		if (isSafe(graph, color)) {
		
			// Print the solution
			printSolution(color);
			return true;
		}
		return false;
	}

	// Assign each color from 1 to m
	for (int j = 1; j <= m; j++) {
		color[i] = j;

		// Recur of the rest vertices
		if (graphColoring(graph, m, i + 1, color))
			return true;

		color[i] = 0;
	}

	return false;
}

/* A utility function to print solution */
void printSolution(int color[])
{
	cout << "Solution Exists:" " Following are the assigned colors \n";
	for (int i = 0; i < V; i++)
		cout << " " << color[i];
	cout << "\n";
}

// Driver code
int main()
{
	/* Create following graph and
	test whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3; // Number of colors

	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (!graphColoring(graph, m, 0, color))
		cout << "Solution does not exist";

	return 0;
}
/*
// C++ program for solution of M
// Coloring problem using backtracking
#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

 A utility function to check if
the current color assignment
is safe for vertex v i.e. checks
whether the edge exists or not
(i.e, graph[v][i]==1). If exist
then checks whether the color to
be filled in the new vertex(c is
sent in the parameter) is already
used by its adjacent
vertices(i-->adj vertices) or
not (i.e, color[i]==c) 
bool isSafe(int v, bool graph[V][V],
			int color[], int c)
{
	for(int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
			
	return true;
}

 A recursive utility function
to solve m coloring problem 
bool graphColoringUtil(bool graph[V][V], int m,
					int color[], int v)
{
	
	base case: If all vertices are
	assigned a color then return true 
	if (v == V)
		return true;

    Consider this vertex v and
	try different colors 
	for(int c = 1; c <= m; c++)
	{
		
		Check if assignment of color
		c to v is fine
		if (isSafe(v, graph, color, c))
		{
			color[v] = c;

			 recur to assign colors to
			rest of the vertices 
			if (graphColoringUtil(
				graph, m, color, v + 1) == true)
				return true;

			/* If assigning color c doesn't
			lead to a solution then remove it 
			color[v] = 0;
		}
	}

	/* If no color can be assigned to
	this vertex then return false 
	return false;
}

/* This function solves the m Coloring
problem using Backtracking. It mainly
uses graphColoringUtil() to solve the
problem. It returns false if the m
colors cannot be assigned, otherwise
return true and prints assignments of
colors to all vertices. Please note
that there may be more than one solutions,
this function prints one of the
feasible solutions 
bool graphColoring(bool graph[V][V], int m)
{
	
	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for(int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false)
	{
		cout << "Solution does not exist";
		return false;
	}

	// Print the solution
	printSolution(color);
	return true;
}

/* A utility function to print solution 
void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for(int i = 0; i < V; i++)
		cout << " " << color[i] << " ";
		
	cout << "\n";
}

// Driver code
int main()
{
	
	/* Create following graph and test
	whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)

	bool graph[V][V] = { { 0, 1, 1, 1 },
						{ 1, 0, 1, 0 },
						{ 1, 1, 0, 1 },
						{ 1, 0, 1, 0 }, };
						
	// Number of colors
	int m = 3;
	graphColoring(graph, m);
	return 0;
}
*/


// CPP program for the above approach
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{

	// A node class which stores the color and the edges
	// connected to the node
public:
	int color = 1;
	set<int> edges;
};

int canPaint(vector<node>& nodes, int n, int m)
{

	// Create a visited array of n
	// nodes, initialized to zero
	vector<int> visited(n + 1, 0);

	// maxColors used till now are 1 as
	// all nodes are painted color 1
	int maxColors = 1;

	// Do a full BFS traversal from
	// all unvisited starting points
	for (int sv = 1; sv <= n; sv++)
	{

		if (visited[sv])
			continue;

		// If the starting point is unvisited,
		// mark it visited and push it in queue
		visited[sv] = 1;
		queue<int> q;
		q.push(sv);

		// BFS Travel starts here
		while (!q.empty())
		{

			int top = q.front();
			q.pop();

			// Checking all adjacent nodes
			// to "top" edge in our queue
			for (auto it = nodes[top].edges.begin();
				it != nodes[top].edges.end(); it++)
			{

				// IMPORTANT: If the color of the
				// adjacent node is same, increase it by 1
				if (nodes[top].color == nodes[*it].color)
					nodes[*it].color += 1;

				// If number of colors used shoots m, return
				// 0
				maxColors
					= max(maxColors, max(nodes[top].color,
										nodes[*it].color));
				if (maxColors > m)
					return 0;

				// If the adjacent node is not visited,
				// mark it visited and push it in queue
				if (!visited[*it]) {
					visited[*it] = 1;
					q.push(*it);
				}
			}
		}
	}

	return 1;
}

// Driver code
int main()
{
	
	int n = 4;
	bool graph[n][n] = {
	{ 0, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 1, 1, 0, 1 },
	{ 1, 0, 1, 0 }};
	int m = 3; // Number of colors

		
	// Create a vector of n+1
	// nodes of type "node"
	// The zeroth position is just
	// dummy (1 to n to be used)
	vector<node> nodes(n + 1);

	// Add edges to each node as per given input
	for (int i = 0; i < n; i++)
	{
		for(int j =0;j<n;j++)
		{
			if(graph[i][j])
			{
				// Connect the undirected graph
				nodes[i].edges.insert(i);
				nodes[j].edges.insert(j);
			}
		}
	}

		// Display final answer
		cout << canPaint(nodes, n, m);
		cout << "\n";
	
	return 0;
}
