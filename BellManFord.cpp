#include <bits/stdc++.h>

using namespace std;

typedef long long int li;


int dist[100000];

int main()
{
	li vertices, edges, u, v ,w, src, i, j;
	cin >> vertices >> edges;
	
	vector<pair<li, pair<li, li> > > graph(vertices);

    for(i = 0; i < edges; ++i) {
        cin >> u >> v >> w;
        graph.push_back(make_pair(w, make_pair(u, v)));
    }

    cin >> src;

    // algo starts

    dist[src] = 0;
    for(i = 0; i < vertices; ++i) {
    	dist[i] = INT_MAX;
    }
    
    for(j = 1; j <= vertices - 1; ++j) {
		for(i = 0; i < graph.size(); ++i) {
		    u = graph[i].second.first;
		    v = graph[i].second.second;
		    w = graph[i].first;
		    if(dist[u] != INT_MAX && dist[u] + w > dist[v]) {
		    	dist[v] = dist[u] + w;
		    }
		}
	}

	for(i = 0; i < vertices; ++i) {
		cout << i << " " << dist[i] << endl;
	}
}