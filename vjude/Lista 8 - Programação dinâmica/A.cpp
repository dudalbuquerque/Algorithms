#include <iostream>
#include <vector>
using namespace std;

class KNAPSACK{
private:
    vector<int> v;
    vector<int> w;
public:
    void add(int itm, int weight) {
        v.push_back(itm);
        w.push_back(weight);
    }
    int knapsack(int n, int W) {
        vector<vector<int>> F(n + 1, vector<int>(W +1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= W; j++) {
                if (w[i-1] <= j) {
                    F[i][j] = max(F[i - 1][j], v[i-1] + F[i-1][j - w[i-1]]);
                }else {
                    F[i][j] = F[i-1][j];
                }
            }
        }
        return F[n][W];
    }

};

int main() {
    int S, N;
    cin >> S >> N;

    KNAPSACK K;
    for(int x=0; x < N; x++) {
        int size_item, item;
        cin >> size_item >> item;
        K.add(item, size_item);
    }

    cout << K.knapsack(N , S);
    return 0;
}
