#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
	int n;
	vector<vector<int>> adj;

public:
	Graph(int v)
	{
		n = v;
		adj.resize(v);
	}

	void addEdge(int a, int b)
	{
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	void DFS(int v, vector<bool> &visited)
	{
		visited[v] = true;
		cout <<v<< " "<<endl;
		for (int i:adj[v])
		{
			if (!visited[i])
				DFS(i, visited);
		}
	}

	void BFS(int s)
	{
		vector<bool> visited(n, false);
		queue<int> q;
		visited[s] = true;
		q.push(s);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			cout << v << " ";
			for (int i : adj[v])
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}
};

int main()
{
	int vertex, edge, a, b, start, choice;
	cout << "Enter number of vertices and edges: ";
	cin >> vertex >> edge;
	Graph g(vertex);
	cout << "Enter edges (u v) format: \n";
	while (edge--)
	{
		cin >> a >> b;
		g.addEdge(a, b);
	}

	cout << "Enter the starting node for traversal: ";
	cin >> start;
	cout << "choose method:\n";
	cout << "1.DFS\n2.BFS\n";
	cout << "Enter your choice:";
	cin >> choice;
	vector<bool> visited(vertex, false);
	switch (choice)
	{
	case 1:
		cout << "DFS: ";
		g.DFS(start, visited);
		cout << "\n";
		break;
	case 2:
		cout << "BFS:";
		g.BFS(start);
		cout << "\n";
		break;
	default:
		cout << "Invalid choice";
	}

	return 0;
}