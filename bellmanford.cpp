#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int nodes, edges;
vector <pii> adj[100];

void bellmanford(int source, int destination){
    int dist[100], par[100];
    for(int i = 0 ; i < 100 ; i++){
        dist[i] = INT_MAX/2;
        par[i] = i;
    }
    dist[source] = 0;

    for(int i = 0 ; i < nodes-1 ; i++){
        for(int n = 1 ; n <= nodes ; n++){
            for(auto [neighbour, w] : adj[n]){
                if(dist[neighbour] > dist[n] + w){
                    dist[neighbour] = dist[n] + w;
                    par[neighbour] = n;
                }
            }
        }
    }

    for(int n = 1 ; n <= nodes ; n++){
            for(auto [neighbour, w] : adj[n]){
                if(dist[neighbour] > dist[n] + w){
                    cout << "negative cycle exists" << endl;
                    cout << "answer is negative infinity" << endl;
                    return;
                }
            }
    }

    cout << "jumps needed to reach destination: " << dist[destination] << endl;

    vector <int> path;
    while(destination != source){
        path.push_back(destination);
        destination = par[destination];
    }
    path.push_back(destination);
    cout << "reverse path: ";
    for(auto x : path) cout << x << " ";
    cout << endl;
    reverse(path.begin(), path.end());
    cout << "forward path: ";
    for(auto x : path) cout << x << " ";
    cout << endl;

}

int main(){
    cout << "enter number of nodes: ";
    cin >> nodes;
    cout << "enter number of edges: ";
    cin >> edges;
    for(int i = 0 ; i < edges ; i++){
        cout << "enter two nodes and weight of edge " << i+1 << ": ";
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        // adj[b].push_back({a, w});
    }

    int source, destination;
    cout << "enter source node: ";
    cin >> source;
    cout << "enter destination node: ";
    cin >> destination;
    bellmanford(source, destination);
}


/*
5 5
1 2 2
2 3 3
3 4 -4
4 2 -2
2 5 100
1 5
*/


