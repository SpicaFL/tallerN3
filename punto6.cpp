// Punto 6: maximo y minimo de una matriz m x n, intercambio de filas y transpuesta
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // pedimos el número de filas y columnas, verificando que ambos sean positivos
    int m, n;
    do {
        cout << "Ingrese filas (m) y columnas (n): ";
        cin >> m >> n;
    } while (m <= 0 || n <= 0);

    // creamos una matriz de m filas y n columnas
    // pedimos al usuario que ingrese cada uno de sus elementos
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // buscamos el valor máximo y mínimo de la matriz y sus posiciones
    // tomamos el primer elemento como valor inicial para comparar
    int max = A[0][0], min = A[0][0];
    int filaMax = 0, colMax = 0, filaMin = 0, colMin = 0;

    // recorremos la matriz para encontrar los valores máximo y mínimo
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // si encontramos un valor mayor, actualizamos el máximo y su posición
            if (A[i][j] > max) {
                max = A[i][j];
                filaMax = i;
                colMax = j;
            }

            // si encontramos un valor menor, actualizamos el mínimo y su posición
            if (A[i][j] < min) {
                min = A[i][j];
                filaMin = i;
                colMin = j;
            }
        }
    }

    // mostramos los valores encontrados y la fila y columna donde están ubicados
    cout << "\nMaximo: " << max << " en fila " << filaMax << ", columna " << colMax << endl;
    cout << "Minimo: " << min << " en fila " << filaMin << ", columna " << colMin << endl;

    // intercambiamos la fila que contiene el máximo con la fila del mínimo
    // usamos una variable auxiliar para no perder los valores durante el intercambio
    for (int j = 0; j < n; j++) {
        int aux = A[filaMax][j];
        A[filaMax][j] = A[filaMin][j];
        A[filaMin][j] = aux;
    }

    // creamos una nueva matriz para guardar la transpuesta
    // intercambiamos las posiciones de filas y columnas
    vector<vector<int>> T(n, vector<int>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];

    // mostramos la matriz original después de intercambiar las filas
    cout << "\nMatriz original con filas intercambiadas:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }

    // mostramos la matriz transpuesta con sus filas y columnas intercambiadas
    cout << "\nMatriz transpuesta:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << T[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
