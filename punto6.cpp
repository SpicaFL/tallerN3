// Punto 6: maximo y minimo de una matriz m x n, intercambio de filas y transpuesta
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    do {
        cout << "Ingrese filas (m) y columnas (n): ";
        cin >> m >> n;
    } while (m <= 0 || n <= 0);

    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    int max = A[0][0], min = A[0][0];
    int filaMax = 0, colMax = 0, filaMin = 0, colMin = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
                filaMax = i;
                colMax = j;
            }
            if (A[i][j] < min) {
                min = A[i][j];
                filaMin = i;
                colMin = j;
            }
        }
    }
    cout << "\nMaximo: " << max << " en fila " << filaMax << ", columna " << colMax << endl;
    cout << "Minimo: " << min << " en fila " << filaMin << ", columna " << colMin << endl;
    for (int j = 0; j < n; j++) {
        int aux = A[filaMax][j];
        A[filaMax][j] = A[filaMin][j];
        A[filaMin][j] = aux;
    }
    vector<vector<int>> T(n, vector<int>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];

    cout << "\nMatriz original con filas intercambiadas:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }

    cout << "\nMatriz transpuesta:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << T[i][j] << "\t";
        cout << endl;
    }

    return 0;
}