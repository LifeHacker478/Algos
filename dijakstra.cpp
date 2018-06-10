#include <bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef pair<li, li> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;


li dist[10000];
li visited[100000];


int main()
{
	int vertices, edges, u, v ,w, src;
	cin >> vertices >> edges;
    cin >> src;
	vvpi graph(vertices);

	for(int i = 1; i <= edges; ++i) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

    // algo starts here.

    for(int i = 0; i < vertices; ++i) {
    	dist[i] = INT_MAX;
    	visited[i] = 0;
    }

    priority_queue<pi, vector<pi>, greater<pi> > PQ;

    PQ.push(make_pair(dist[0], 0));

    dist[src] = 0;

    PQ.push(make_pair(dist[src], 0));

    while(!PQ.empty()) {
        int minDistVertex = PQ.top().second;
        PQ.pop();
        for(int i = 0; i < graph[minDistVertex].size(); ++i) {
            int vertex = graph[minDistVertex][i].second;
            int weight = graph[minDistVertex][i].first;
            if(dist[vertex] > weight + dist[minDistVertex]) {
                dist[vertex] = weight + dist[minDistVertex];
                PQ.push(make_pair(dist[vertex], vertex));
            }
        }
    }

    for(int i = 0; i < vertices; ++i) {
        cout << i << " " << dist[i] << endl;
    }
}