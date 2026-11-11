// Punto 1: operaciones sobre una matriz n x n aleatoria
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n;
    cout << "Ingrese n: ";
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = rand() % 51;

    cout << "\nMatriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
    vector<int> diagP(n), diagS(n);
    int sumaP = 0, sumaS = 0;
    for (int i = 0; i < n; i++) {
        diagP[i] = M[i][i];
        diagS[i] = M[i][n - 1 - i];
        sumaP += diagP[i];
        sumaS += diagS[i];
    }
    cout << "\nDiagonal principal: ";
    for (int i = 0; i < n; i++) cout << diagP[i] << " ";
    cout << "\nSuma diagonal principal: " << sumaP << endl;
    cout << "Diagonal secundaria: ";
    for (int i = 0; i < n; i++) cout << diagS[i] << " ";
    cout << "\nSuma diagonal secundaria: " << sumaS << endl;
    vector<int> fila(n), col(n), resultado(n);
    for (int i = 0; i < n; i++) {
        fila[i] = M[0][i];
        col[i] = M[i][n - 1];
    }
    for (int i = 0; i < n; i++) {
        resultado[i] = fila[i] * fila[i] + col[i] * col[i];
    }
    cout << "\nPrimera fila: ";
    for (int i = 0; i < n; i++) cout << fila[i] << " ";
    cout << "\nUltima columna: ";
    for (int i = 0; i < n; i++) cout << col[i] << " ";
    cout << "\nVector resultado (fila^2 + col^2): ";
    for (int i = 0; i < n; i++) cout << resultado[i] << " ";
    cout << endl;

    int primos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = M[i][j];
            bool esPrimo = true;
            if (x < 2) esPrimo = false;
            for (int d = 2; d * d <= x && esPrimo; d++) {
                if (x % d == 0) esPrimo = false;
            }
            if (esPrimo) primos++;
        }
    }
    cout << "\nCantidad de primos: " << primos << endl;

    int pares = 0, impares = 0, div3 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] % 2 == 0) pares++;
            else impares++;
            if (M[i][j] % 3 == 0) div3++;
        }
    }
    cout << "Pares: " << pares << endl;
    cout << "Impares: " << impares << endl;
    cout << "Divisibles por 3: " << div3 << endl;
    const double PI = acos(-1.0);
    vector<int> sumaCol(n, 0);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            sumaCol[j] += M[i][j];

    cout << "\nSuma columna (X)\tSeno (Y)\n";
    for (int j = 0; j < n; j++) {
        double rad = sumaCol[j] * PI / 180.0;
        cout << sumaCol[j] << "\t\t\t" << sin(rad) << endl;
    }

    vector<double> v(n * n);
    int k = 0;
    double total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[k] = M[i][j];
            total += M[i][j];
            k++;
        }
    }
    double promedio = total / (n * n);
    cout << "\nPromedio: " << promedio << endl;
    if (promedio == 0) {
        cout << "El promedio es 0, no se puede dividir." << endl;
    } else {
        cout << "Vector dividido por el promedio:\n";
        for (int i = 0; i < n * n; i++) {
            v[i] = v[i] / promedio;
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}