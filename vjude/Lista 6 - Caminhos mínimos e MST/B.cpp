#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    vector<list<pair<int, int>>> adjList;
    vector<int> Mark;

public:
    void create_graph(int n) {
        Mark.resize(n, 0);
        adjList.resize(n);
    }

    void addEdge(int i, int j, int weight) {
        adjList[i].push_back({j, weight});
        adjList[j].push_back({i, weight});
    }

    int n() const {
        return adjList.size();
    }

    void setMark(int v, int value) {
        Mark[v] = value;
    }

    int getMark(int v) {
        return Mark[v];
    }

    void PRIM(int s, vector<int>& D, vector<int>& V) {
        int n = adjList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (int i = 0; i < n; i++) {
            D[i] = INF;
            V[i] = -1;
            setMark(i, 0);
        }

        D[s] = 0;
        min_heap.push({0, s});

        for(int i = 0; i < n; i++){
            int p, v;
            do {
                if (min_heap.empty()) return;
                p = min_heap.top().first;
                v = min_heap.top().second;
                min_heap.pop();
            } while (getMark(v) != 0);

            setMark(v, 1);
            V[v] = p;
            for (auto &adj : adjList[v]) {
                int w = adj.first;
                int weight = adj.second;
                if (getMark(w) == 0 && D[w] > weight) {
                    D[w] = weight;
                    min_heap.push({D[w], w});
                }
            }
        }
    }
};

int main() {
    bool stop = false;
    while(!stop){
        int n, m;
        cin >> n >> m;

        if(n==0 && m == 0){
            stop = true;
        }else{
            Graph g;
            g.create_graph(n);
            for (int x = 1; x <= m; x++) {
                int v1, v2, w;
                cin >> v1 >> v2 >> w;
                g.addEdge(v1, v2, w);
            }

            vector<int> D(n, INF);
            vector<int> V(n, -1);
            g.PRIM(0, D, V);

            bool connected = true;
            int maxw = 0;
            for(int i = 0; i < n; i++){
                if(g.getMark(i) == 0){
                    connected = false;
                }else{
                    if(D[i] != INF && D[i] > maxw){
                        maxw = D[i];
                    }
                }
            }

            if(connected){
                cout << maxw << endl;
            }else{
                cout << "IMPOSSIBLE" << endl;
            }
        }
    }
    return 0;
}
