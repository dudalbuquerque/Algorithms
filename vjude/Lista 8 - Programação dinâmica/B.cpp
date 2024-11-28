#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Problem{
private:
    vector<int> height;
    int N, K;
public:
    void create(int n, int k) {
        height.resize(n);
        N = n;
        K = k;
    }
    void addheight(int h, int index) {
        height[index] = h;
    }
    int minpath(){
        vector<int> cMin(N, INF);
        cMin[0] = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= K; ++j) {
                if (i + j < N) {
                    cMin[i + j] = min(cMin[i + j], cMin[i] + abs(height[i] - height[i + j]));
                }
            }
        }
        return cMin[N - 1];
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    Problem ProblemFrog;
    ProblemFrog.create(N, K);
    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;
        ProblemFrog.addheight(h, i);
    }

    cout << ProblemFrog.minpath() << endl;

    return 0;
}
