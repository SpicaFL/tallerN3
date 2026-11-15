// Punto 7: multiplicacion de matrices C = A x B
#include <iostream>
#include <vector>
using namespace std;

// creamos una función que recibe una fila de la matriz y suma todos sus elementos
int sumaFila(const vector<int>& fila) {
    int suma = 0;

    // recorremos la fila y acumulamos sus valores
    for (size_t i = 0; i < fila.size(); i++) {
        suma += fila[i];
    }

    // devolcemos la suma obtenida
    return suma;
}

// función que permite mostrar los elementos de una matriz en pantalla
void imprimir(const vector<vector<int>>& M) {
    for (size_t i = 0; i < M.size(); i++) {
        for (size_t j = 0; j < M[i].size(); j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    // pedimos las dimensiones de las matrices A y B
    // verificamos que las columnas de A sean iguales a las filas de B
    int m, p, q, filasB;
    while (true) {
        cout << "Dimensiones de A (filas m, columnas p): ";
        cin >> m >> p;
        cout << "Dimensiones de B (filas, columnas q): ";
        cin >> filasB >> q;

        // si las dimensiones son válidas, salimos del ciclo
        if (m > 0 && p > 0 && q > 0 && p == filasB) break;

        // si no cumplen la condición, mostramos un error y volvemos a pedirlas
        cout << "Error: las columnas de A deben ser iguales a las filas de B. Intente de nuevo.\n\n";
    }

    // creamos las matrices A, B y C con las dimensiones correspondientes
    // la matriz C se inicializa con ceros para guardad el resultado
    vector<vector<int>> A(m, vector<int>(p));
    vector<vector<int>> B(p, vector<int>(q));
    vector<vector<int>> C(m, vector<int>(q, 0));

    // pedimos al usuario que ingrese los elementos de la matriz A
    cout << "\nElementos de A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    // pedimos al usuario que ingrese los elementos de la matriz B
    cout << "\nElementos de B:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }

    // multiplicamos las matrices A y B para obtener la matriz C
    // multiplicamos los elementos correspondientes y sumamos los resultados
    for (int i = 0; i < m; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];

    // mostramos las matrices A, B y C usando la función imprimir
    cout << "\nMatriz A:\n";
    imprimir(A);
    cout << "\nMatriz B:\n";
    imprimir(B);
    cout << "\nMatriz C = A x B:\n";
    imprimir(C);

    // recorremos las filas de la matriz C y calculamos la suma de cada una
    // utilizamos la función sumaFila para obtener y mostrar los resultados
    cout << "\nSuma de cada fila de C:\n";
    for (int i = 0; i < m; i++) {
        cout << "Fila " << i << ": " << sumaFila(C[i]) << endl;
    }

    return 0;
}
