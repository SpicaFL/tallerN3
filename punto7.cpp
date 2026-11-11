// Punto 7: multiplicacion de matrices C = A x B
#include <iostream>
#include <vector>
using namespace std;

int sumaFila(const vector<int>& fila) {
    int suma = 0;
    for (size_t i = 0; i < fila.size(); i++) {
        suma += fila[i];
    }
    return suma;
}

void imprimir(const vector<vector<int>>& M) {
    for (size_t i = 0; i < M.size(); i++) {
        for (size_t j = 0; j < M[i].size(); j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int m, p, q, filasB;
    while (true) {
        cout << "Dimensiones de A (filas m, columnas p): ";
        cin >> m >> p;
        cout << "Dimensiones de B (filas, columnas q): ";
        cin >> filasB >> q;
        if (m > 0 && p > 0 && q > 0 && p == filasB) break;
        cout << "Error: las columnas de A deben ser iguales a las filas de B. Intente de nuevo.\n\n";
    }
    vector<vector<int>> A(m, vector<int>(p));
    vector<vector<int>> B(p, vector<int>(q));
    vector<vector<int>> C(m, vector<int>(q, 0));

    cout << "\nElementos de A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "\nElementos de B:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "\nMatriz A:\n";
    imprimir(A);
    cout << "\nMatriz B:\n";
    imprimir(B);
    cout << "\nMatriz C = A x B:\n";
    imprimir(C);

    cout << "\nSuma de cada fila de C:\n";
    for (int i = 0; i < m; i++) {
        cout << "Fila " << i << ": " << sumaFila(C[i]) << endl;
    }

    return 0;
}