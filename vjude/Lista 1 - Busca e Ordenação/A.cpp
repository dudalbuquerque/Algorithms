#include <iostream>

using namespace std;

void merge(long long int lista1[], int inicio, long long int fim) {
    int temp[fim+1];
    for (int i = inicio; i <= fim; i++) {
        temp[i] = lista1[i];
    }
    long long int m = (inicio + fim) / 2;
    int i1 = inicio;
    long long int i2 = m + 1;
    for (int c = inicio; c <= fim; c++) {
        if (i1 == m + 1) {
            lista1[c] = temp[i2++];
        } else if (i2 > fim) {
            lista1[c] = temp[i1++];
        } else if (temp[i1] <= temp[i2]) {
            lista1[c] = temp[i1++];
        }
        else {
            lista1[c] = temp[i2++];
        }
    }
}

void mergesort(long long int lista1[], int inicio, long long int fim) {
    if (inicio < fim) {
        long long int m = (inicio + fim) / 2;
        mergesort(lista1, inicio, m);
        mergesort(lista1, m + 1, fim);
        merge(lista1, inicio, fim);
    }
}

int main() {
    long long int n;
    cin >> n;

    long long int soma = 0;
    long long int lista1[n];
    for (int i = 0; i < n; i++) {
        cin >> lista1[i];
        soma += lista1[i];
    }

    int mc;
    cin >> mc;
    int lista2[mc];
    for (int i = 0; i < mc; i++) {
        cin >> lista2[i];
    }

    mergesort(lista1, 0, n - 1);

    for (int i=0; i < mc; i++) {
        long long int pagamento = soma;
        long long int qnt_elementos = (n);
        long long int indice = (qnt_elementos -(lista2[i]));
        pagamento = (pagamento - lista1[indice]);
        cout << pagamento << std::endl;
    }

    return 0;
}