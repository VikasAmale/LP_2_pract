#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

int a[10][10];
int p[10];

int find(int x)
{
	while (p[x] != x)
	{
		x = p[x];
	}
	return x;
}

void kruskal(int n)
{
	int u, v, min, t = 1, cost = 0;
	while (t < n)
	{
		min = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] && a[i][j] < min)
				{
					min = a[i][j];
					u = i;
					v = j;
				}
			}
		}
		int pu = find(u);
		int pv = find(v);
		if (pu != pv)
		{
			cout << u << " - " << v << " : " << min << endl;
			cost += min;
			p[pu] = pv;
			t++;
		}

		a[u][v] = a[v][u] = 0;
	}

	cout << "Total Cost: " << cost << endl;
}

void prim(int n)
{
	int vis[10] = {0}, u, v, min, cost = 0;
	vis[0] = 1;
	for (int e = 1; e < n; e++)
	{
		min = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (vis[i])
			{
				for (int j = 0; j < n; j++)
				{
					if (!vis[j] && a[i][j] && a[i][j] < min)
					{
						min = a[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		vis[v] = 1;
		cout << u << " - " << v << " : " << min << endl;
		cost += min;
	}

	cout << "Total Cost: " << cost << endl;
}

int main()
{
	int n, ch;
	cout << "Enter number of nodes: ";
	cin >> n;
	cout << "Enter cost matrix (0 for no edge):\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		p[i] = i;
	}

	cout << "1. Prim's\n2. Kruskal's\nEnter choice: ";
	cin >> ch;

	if (ch == 1)
	{
		prim(n);
	}
	else if (ch == 2)
	{
		kruskal(n);
	}
	else
	{
		cout << "Wrong choice!\n";
	}
	return 0;
}
 