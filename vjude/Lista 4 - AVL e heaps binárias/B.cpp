#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class HeapMin{
private:
    vector<int> heap;
public:
    void insert(int value){
        heap.push_back(value);
        HeapBottomUp();
    }
    
    void resultado() {
        int min, min1, sum = 0;
        int result = 0;
        while (heap.size() > 1) {
            min = removeMin();
            min1 = removeMin();
            sum = min + min1;
            result += sum;
            insert(sum);
        }
        cout << result << endl;
    }
    
    void HeapBottomUp() {
        int n = heap.size();
        for (int i = floor(n / 2) - 1; i >= 0; i--) {
            int k = i;
            int v = heap[k];
            bool blheap = false;
            while (!blheap && 2 * k + 1 < n) {
                int j = 2 * k + 1;
                if (j + 1 < n && heap[j] > heap[j + 1]) { 
                    j++;
                }
                if (v <= heap[j]) {
                    blheap = true;
                } else {
                    heap[k] = heap[j];
                    k = j;
                }
            }
            heap[k] = v;
        }
    }

    int removeMin() {
        if (heap.empty()) {
            return -1;
        }
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        HeapBottomUp();
        return min;
    }

};

int main(){
    int n;
    cin >> n;

    while(n != 0) {
        HeapMin heapmin;
        int v;
        for (int j = 0; j<n; j++) {
            cin >> v;
            heapmin.insert(v);
        }
        heapmin.resultado();
        cin >> n;
    }
    return 0;
}
