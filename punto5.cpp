// Punto 5: determinar si una matriz cuadrada es triangular superior inferior o diagonal
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //pedimos el tamaño de la matriz y verificamos que sea un número positivo
    int n;
    do {
        cout << "Ingrese n (tamano de la matriz n x n): ";
        cin >> n;
    } while (n <= 0);

    // creamos una matriz cuadrada de n filas y n columnas
    // pedimos al usuario que ingrese cada uno de sus elementos
    vector<vector<int>> M(n, vector<int>(n));
    cout << "Ingrese los elementos de la matriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> M[i][j];
        }
    }

    // mostramos la matriz ingresada en pantalla
    cout << "\nMatriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }

    // inicializamos dos variables para comprobar si la matriz es triangular superior o inferior
    bool superior = true;
    bool inferior = true;

    // recorremos la matriz y revisamos los elementos que están fuera de la diagonal principal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // si hay un valor distinto de cero debajo de la diagonal, no es triangular superior
            if (i > j && M[i][j] != 0) superior = false;

            // si hay un valor distinto de cero encima de la diagonal, no es triangular inferior
            if (i < j && M[i][j] != 0) inferior = false;
        }
    }

    // determinamos el tipo de matriz según las condiciones anteriores
    cout << endl;
    if (superior && inferior) {
        // si cumple ambas condiciones, significa que es una matriz diagonal
        cout << "La matriz es DIAGONAL (tambien es triangular superior e inferior)." << endl;
    } else if (superior) {
        cout << "La matriz es TRIANGULAR SUPERIOR." << endl;
    } else if (inferior) {
        cout << "La matriz es TRIANGULAR INFERIOR." << endl;
    } else {
        // si no cumple ninguna condición, no es triangular ni diagonal
        cout << "La matriz no es triangular ni diagonal." << endl;
    }

    return 0;
}
