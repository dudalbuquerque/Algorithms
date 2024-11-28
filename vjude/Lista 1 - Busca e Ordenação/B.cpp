#include <iostream>
#include <algorithm>

using namespace std;

int hoarepartition(int lista[], int inicio, int fim) {
    int pivo = lista[inicio];
    int i = inicio;
    int j = fim+1;
    do  {
        do  {
            i++;
        }while(lista[i]< pivo && i<fim);
        do  {
            j--;
        }while(lista[j]>pivo);
        swap(lista[i], lista[j]);
    }while(i<j);
    swap(lista[i], lista[j]);
    swap(lista[inicio], lista[j]);
    return j;
}

void quicksort(int lista[], int inicio, int fim) {
    if (inicio < fim) {
        int s = hoarepartition(lista, inicio, fim);
        quicksort(lista, inicio, s - 1);
        quicksort(lista, s + 1, fim);
    }
}
int binarysearch(int lista[], int n, int diferenca) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        int m = lista[i] + diferenca;
        if (binary_search(lista + i + 1, lista + n, m)) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int n, diferenca;
    cin >> n >> diferenca;

    int lista[n];
    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }

    int inicio = 0;
    int fim = n - 1;

    quicksort(lista, inicio, fim);
    int contador = binarysearch(lista, n, diferenca);

    cout << contador;
    return 0;
}