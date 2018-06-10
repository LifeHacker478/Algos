#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

vector<li> visited(100000);
vector<vector<li> > graph(100000);



void DFS(li vertex)
{
    visited[vertex] = 1;

    cout << vertex << " ";

    for(int i = 0; i < graph[vertex].size(); ++i) {
    	if(!visited[graph[vertex][i]]) {
    		DFS(graph[vertex][i]);
    	}
    }
}

int main()
{

	li vertices, edges, u, v;
	cin >> vertices >> edges;

	for(int i = 1; i <= edges; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// algo starts here

	DFS(0);
}