#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

class Graph {
private:
    vector<vector<P>> adj;

public:
    void create(int n) {
        adj.resize(n);
    }

    void addEdge(int server1, int server2, int w) {
        adj[server1].push_back({server2, w});
        adj[server2].push_back({server1, w});
    }

    void dijkstra(int S, int T) {
        vector<int> dist(adj.size(), INF);
        priority_queue<P, vector<P>, greater<P>> min_heap;

        dist[S] = 0;
        min_heap.push({0, S});

        while (!min_heap.empty()) {
            int u = min_heap.top().second;
            min_heap.pop();

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    min_heap.push({dist[v], v});
                }
            }
        }

        if (dist[T] == INF) {
            cout << "unreachable" << endl;
        } else {
            cout << dist[T] << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;

    for (int x = 1; x <= N; x++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        Graph g;
        g.create(n);

        for (int i = 0; i < m; i++) {
            int server1, server2, w;
            cin >> server1 >> server2 >> w;
            g.addEdge(server1, server2, w);
        }

        cout << "Case #" << x << ": ";
        g.dijkstra(S, T);
    }

    return 0;
}
