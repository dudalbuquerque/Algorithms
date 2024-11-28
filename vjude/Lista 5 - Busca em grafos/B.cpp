#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<int> indegree;

public:
    void create_graph(int n) {
        adjList.resize(n);
        indegree.resize(n, 0);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    
    void kahn(){
        for(int i = 0; i < adjList.size(); i++){
            for(auto it : adjList[i]){
                indegree[it]++;
            }
        }
        vector<int> topovector;
        priority_queue<int, vector<int>, greater<int>> que;
        for(int i = 0; i < adjList.size(); i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        
        while(!que.empty()){
            int node = que.top();
            que.pop();
            topovector.push_back(node);
            for(auto it : adjList[node]){
                indegree[it]--;
                if (indegree[it] == 0){
                    que.push(it);
                }
            }
        }
        if(topovector.size() != adjList.size()){
            cout << "Sandro fails.";
        }else{
            for(int i = 0; i < topovector.size(); i++){
                cout << topovector[i]+1 << " ";
            } 
        }
    }

};

int main() {
    Graph g;
    int n, m, x, y;
    cin >> n >> m;

    g.create_graph(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g.addEdge(x - 1, y - 1);
    }
    g.kahn();

    return 0;
}
