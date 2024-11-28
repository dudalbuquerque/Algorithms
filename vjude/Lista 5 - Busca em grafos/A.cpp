#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>


using namespace std;

class Graph{
private:
    map<string, vector<string>> adjList;
    map<string, int> ranking;

public:
    void addEdge(string& u, string& v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void setMark() {
        for(auto& i : adjList) {
            ranking[i.first] = -1;
        }
    }

    void BFSranking(string& start){
        queue<string> Q;
        Q.push(start);
        ranking[start] = 0;

        while(!Q.empty()) {
            string v = Q.front();
            Q.pop();
            int rankatual = ranking[v];

            for(string& j : adjList[v]) {
                if(ranking[j] == -1) {
                    ranking[j] = rankatual + 1;
                    Q.push(j);
                }
            }
        }
    }

    void printranking() {
        vector<pair<string, int>> sortranking;
        vector<string> undefined;

        for(auto& pessoa_classific: ranking) {
            if(pessoa_classific.second == -1) {
                undefined.push_back(pessoa_classific.first);
            }else {
                sortranking.push_back(pessoa_classific);
            }
        }
        sort(sortranking.begin(), sortranking.end(), [](pair<string, int>& rank1,pair<string, int>& rank2) {
            if (rank1.second != rank2.second) {
                return rank1.second < rank2.second;
            }return rank1.first < rank2.first;
        });

        sort(undefined.begin(), undefined.end());
        int tot;
        tot = sortranking.size() + undefined.size();
        cout << tot << endl;
        for (auto& name_rank : sortranking) {
            cout << name_rank.first << " " << name_rank.second << endl;
        }
        for (auto& name : undefined) {
            cout << name << " undefined" << endl;
        }
    }

};

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >>  n;
        Graph g;
        for(int j = 0; j < n; j++) {
            string p1, p2, p3;
            cin >> p1 >> p2 >> p3;
            g.addEdge(p1,p2);
            g.addEdge(p1,p3);
            g.addEdge(p2,p3);
        }
        g.setMark();
        string start = "Ahmad";
        g.BFSranking(start);
        g.printranking();
    }
    return 0;
}
