#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Entry {
    string key;
    bool deleted;
    Entry(string k) : key(k), deleted(false) {}
};

int funcaohash(string &K, int m) {
    int h = 0;
    for (int i = 0; i < K.size(); i++) {
        h += K[i] * (i + 1);
    }
    return (19 * h) % m;
}

int probe(int inthash, int i, int m) {
    return (inthash + i * i + 23 * i) % m;
}

class Dictionary {
private:
    int m;
    int cnt;
    vector<Entry*> H;

public:
    Dictionary(int size) : m(size), cnt(0), H(size, nullptr) {}

    void insert(string &k) {
        int intHash = funcaohash(k, m);
        if(find(k) != -1) {
            return;
        }

        for (int i =0 ; i < 20; i++) {
            int ind = probe(intHash, i, m);
            if (H[ind] == nullptr) {
                H[ind] = new Entry(k);
                cnt++;
                return;
            } else if (H[ind]->deleted) {
                H[ind]->key = k;
                H[ind]->deleted = false;
                cnt++;
                return;
            }
        }
    }
    int find(string &k) {
        int intHash = funcaohash(k, m);

        for (int i =0 ; i < 20; i++) {
            int ind = probe(intHash, i, m);
            if (H[ind] != nullptr && H[ind]->key == k && !H[ind]->deleted) {
                return ind;
            }
        }
        return -1;
    }

    void remove1( string &k) {
        int intHash = funcaohash(k, m);

        for (int i =0 ; i < 20; i++) {
            int ind = probe(intHash, i, m);
            if (H[ind] != nullptr && H[ind]->key == k && !H[ind]->deleted) {
                H[ind]->deleted = true;
                cnt--;
                return;
            }
        }
    }

    void saida() {
        cout << cnt << endl;
        for (int i = 0; i < m; i++) {
            if (H[i] != nullptr && !H[i]->deleted) {
                cout << i << ":" << H[i]->key << endl;

            }
        }
    }

    ~Dictionary() {
        for (int i = 0; i < m; i++) {
            if (H[i] != nullptr) {
                delete H[i];
            }
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        Dictionary dict(101);

        for (int i = 0; i < n; i++) {
            string comando_key;
            cin >> comando_key;
            string comando = comando_key.substr(0, 3);
            string key = comando_key.substr(4);

            if (comando == "ADD") {
                dict.insert(key);
            } else if (comando == "DEL") {
                dict.remove1(key);
            }
        }

        dict.saida();
    }

    return 0;
}
