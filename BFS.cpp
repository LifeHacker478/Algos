#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

vector<li> visited(100000);
vector<vector<li> > graph(100000);



void BFS(li src)
{
	queue<li> Q;
	Q.push(src);
	visited[src] = 1;
	while(!Q.empty()) {
		li child = Q.front();
		Q.pop();
		cout << child << " ";
		for(vector<li> :: iterator it = graph[child].begin(); it != graph[child].end(); ++it) {
			if(!visited[*it]) {
			    Q.push(*it);
			    visited[*it] = 1;
			}
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

	BFS(0);
}