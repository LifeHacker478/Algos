#include <bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef pair<li, li> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;


li distFromTree[10000];
li visited[100000];
li parent[100000];


int main()
{
	int vertices, edges, u, v ,w;
	cin >> vertices >> edges;
	vvpi graph(vertices);

	for(int i = 1; i <= edges; ++i) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

    // algo starts here.

    for(int i = 0; i < vertices; ++i) {
    	distFromTree[i] = INT_MAX;
    	visited[i] = 0;
    }

    priority_queue<pi, vector<pi>, greater<pi> > PQ;

    PQ.push(make_pair(distFromTree[0], 0));

    distFromTree[0] = 0;

    PQ.push(make_pair(distFromTree[0], 0));

    while(!PQ.empty()) {

        li minNode = PQ.top().second;

        PQ.pop();

        visited[minNode]  = 1;

        for(li i = 0; i < graph[minNode].size(); ++i) {
        	li node = graph[minNode][i].second;
        	li weight = graph[minNode][i].first;
        	if(!visited[node] && distFromTree[node] > weight) {
        		distFromTree[node] = weight;
        		PQ.push(make_pair(distFromTree[node], node));
        		parent[node] = minNode;
        	}
        }
    }

    for(int i = 0; i < vertices; ++i) {
    	cout << i << " " << parent[i] << endl;
    }
    

}