// Punto 5: determinar si una matriz cuadrada es triangular superior inferior o diagonal
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    do {
        cout << "Ingrese n (tamano de la matriz n x n): ";
        cin >> n;
    } while (n <= 0);

    vector<vector<int>> M(n, vector<int>(n));
    cout << "Ingrese los elementos de la matriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> M[i][j];
        }
    }

    cout << "\nMatriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }

    bool superior = true;
    bool inferior = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && M[i][j] != 0) superior = false;
            if (i < j && M[i][j] != 0) inferior = false;
        }
    }

    cout << endl;
    if (superior && inferior) {
        cout << "La matriz es DIAGONAL (tambien es triangular superior e inferior)." << endl;
    } else if (superior) {
        cout << "La matriz es TRIANGULAR SUPERIOR." << endl;
    } else if (inferior) {
        cout << "La matriz es TRIANGULAR INFERIOR." << endl;
    } else {
        cout << "La matriz no es triangular ni diagonal." << endl;
    }

    return 0;
}