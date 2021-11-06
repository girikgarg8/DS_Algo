#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isValid(int i, int j, int m, int n)
{
	if (i < 0 || j < 0 || i >= m || j >= n)
	{
		return false;
	}

	return true;
}
void shortestPathHelper(vector<vector<int>> &field, vector<vector<bool>> &visited, int i, int j, int &minLength, int curLength)
{
	// Find the number of rows in the field.
	int m = field.size();

	// Find the number of columns in the field.
	int n = field[0].size();

	if (j == n - 1)
	{
		// Generated a valid path. So, update the shortest path length.
		minLength = min(minLength, curLength);
		return;
	}

	if (curLength >= minLength)
	{
		// Path being generated is longer than the shortest path found so far.
		return;
	}

	visited[i][j] = true;

	// Move to the adjacent cells.
	for (int k = 0; k < 4; k++)
	{
		int x = i + direction[k][0];
		int y = j + direction[k][1];

		if (isValid(x, y, m, n) && field[x][y] == 1 && visited[x][y] == false)
		{
			// If the cell is safe and not visited before, then add it to the current path.
			shortestPathHelper(field, visited, x, y, minLength, curLength + 1);
		}
	}

	// Backtrack to the previous cell.
	visited[i][j] = false;
}
void markUnsafeCells(vector<vector<int>> &field)
{
	// Find the number of rows in the field.
	int m = field.size();

	// Find the number of columns in the field.
	int n = field[0].size();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// Cell contains a landmine.
			if (field[i][j] == 0)
			{
				// Mark all neighbouring unsafe cells as -1.
				for (int k = 0; k < 4; k++)
				{
					int x = i + direction[k][0];
					int y = j + direction[k][1];

					if (isValid(x, y, m, n))
					{
						field[x][y] = 0;
					}
				}
			}
		}
	}
}
int shortestPath(vector<vector<int>> &field){

// Find the number of rows in the field.
	int m = field.size();

	// Find the number of columns in the field.
	int n = field[0].size();

	int minLength = INT_MAX;

	// Mark all the unsafe cells as 0 instead of 1.
	markUnsafeCells(field);
    for (int i = 0; i < m; i++)
	{
		if (field[i][0] == 1)
		{
			vector<vector<bool>> visited(m, vector<bool>(n, false));

			// Generate the path starting from the current cell.
			shortestPathHelper(field, visited, i, 0, minLength,0);

			if (minLength == n - 1)
			{
				break;
			}
		}
	}

	if (minLength == INT_MAX)
	{
		// No valid path exists.
		return -1;
	}

	return minLength;
}

//BFS based approach now
/*
int shortestPath(vector<vector<int>> &field)
{
	// Find the number of rows in the field.
	int m = field.size();

	// Find the number of columns in the field.
	int n = field[0].size();

	const int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	// Create a matrix to store the length of the shortest path ending at each cell.
	vector<vector<int>> dist(m, vector<int>(n, -1));

	// Mark all the unsafe cells as 0 instead of 1.
	markUnsafeCells(field, direction);

	queue<pair<int, int>> q;

	// Push all the safe cells, present in the first column, into the queue.
	for (int i = 0; i < m; i++)
	{
		if (field[i][0] == 1)
		{
			q.push({i, 0});
			dist[i][0] = 0;
		}
	}

	// Apply BFS.
	while (!q.empty())
	{
		pair<int, int> coord = q.front();
		q.pop();

		// Let i and j be the row and column index of the current cell.
		int i = coord.first;
		int j = coord.second;

		// Check if the cell is present in the last column.
		if (j == n - 1)
		{
			// Found the shortest path.
			return dist[i][j];
		}

		// Update the distance of the adjacent unvisited safe cells and push them into the queue.
		for (int k = 0; k < 4; k++)
		{
			int x = i + direction[k][0];
			int y = j + direction[k][1];

			if (isValid(x, y, m, n) && field[x][y] == 1 && dist[x][y] == -1)
			{
				dist[x][y] = dist[i][j] + 1;
				q.push({x, y});
			}
		}
	}

	// No valid path exists.
	return -1;
}

*/


