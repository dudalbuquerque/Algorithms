#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    vector<vector<int>> matrix;
    vector<int> Mark;

public:
    void create_graph(int n) {
        Mark.resize(n, 0);
        matrix.resize(n, vector<int>(n, INF));
    }

    void addEdge(int i, int j, int weight) {
        matrix[i][j] = weight;
        matrix[j][i] = weight;
    }

    int n() const {
        return matrix.size();
    }

    int first(int v) {
        for (int i = 0; i < n(); i++) {
            if (matrix[v][i] != INF) {
                return i;
            }
        }
        return n();
    }

    int next(int v, int w) {
        for (int i = w + 1; i < n(); i++) {
            if (matrix[v][i] != INF) {
                return i;
            }
        }
        return n();
    }

    int getWeight(int i, int j) {
        return matrix[i][j];
    }

    void setMark(int v, int value) {
        Mark[v] = value;
    }

    int getMark(int v) {
        return Mark[v];
    }

    void PRIM(int s, vector<int>& D, vector<int>& V) {
        int m = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;

        for (int i = 0; i < m; i++) {
            D[i] = INF;
            V[i] = -1;
            setMark(i, 0); // UNVISITED == 0
        }

        D[0] = 0;
        min_heap.push({0, s});

        for(int i = 0; i < m; i++){
            int p, v;
            do {
                if (min_heap.empty()) return;
                p = min_heap.top()[0];
                v = min_heap.top()[1];
                min_heap.pop();
            } while (getMark(v) != 0);

            setMark(v, 1);
            V[v] = p;
            int w = first(v);
            while (w < m) {
                if (getMark(w) == 0 && D[w] > getWeight(v, w)) {
                    D[w] = getWeight(v, w);
                    min_heap.push({D[w], w});
                }
                w = next(v, w);
            }
        }
    }
};
int main() {
    int c, o;
    cin >> c >> o;

    for(int w = 1; (c != 0 || o != 0); w++) {
        Graph g;
        g.create_graph(c);
        for(int x = 0; x < o; x++) {
            int i, j, p;
            cin >> i >> j >> p;
            g.addEdge(i, j, p);
        }
        vector<int> D(c, INF);
        vector<int> V(c, -1);
        g.PRIM(0, D, V);

        
        int mp =0;
        for(int z = 0; z < c; z++){
            mp += D[z];
        }
        cout << "Caso " << w << ": " << mp << endl;
        cin >> c >> o;
    }
    return 0;
}