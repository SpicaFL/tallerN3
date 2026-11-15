// Punto 1: operaciones sobre una matriz n x n aleatoria
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    //pedimos el tamaño de la matriz y la llenamos con números aleatorios entre 0 y 50
    srand(time(0));
    int n;
    cout << "Ingrese n: ";
    cin >> n;

    // creamos la matriz de n filas y n columnas
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = rand() % 51;

    // mostramos la matriz generada en pantalla
    cout << "\nMatriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }

    //extraemos las diagonales principal y secundaria y calculamos sus sumas
    vector<int> diagP(n), diagS(n);
    int sumaP = 0, sumaS = 0;
    for (int i = 0; i < n; i++) {
        diagP[i] = M[i][i];
        diagS[i] = M[i][n - 1 - i];
        sumaP += diagP[i];
        sumaS += diagS[i];
    }

    // mostramos los elementos de cada diagonal y la suma correspondinete
    cout << "\nDiagonal principal: ";
    for (int i = 0; i < n; i++) cout << diagP[i] << " ";
    cout << "\nSuma diagonal principal: " << sumaP << endl;
    cout << "Diagonal secundaria: ";
    for (int i = 0; i < n; i++) cout << diagS[i] << " ";
    cout << "\nSuma diagonal secundaria: " << sumaS << endl;

    // guardamos la primera fila y la última columna en dos vectores
    vector<int> fila(n), col(n), resultado(n);
    for (int i = 0; i < n; i++) {
        fila[i] = M[0][i];
        col[i] = M[i][n - 1];
    }

    // elevamos al cuadrado los elementos de ambos vectores y los sumamos posición por posición
    for (int i = 0; i < n; i++) {
        resultado[i] = fila[i] * fila[i] + col[i] * col[i];
    }

    // mostramos los dos vectores originales y el vector resultante
    cout << "\nPrimera fila: ";
    for (int i = 0; i < n; i++) cout << fila[i] << " ";
    cout << "\nUltima columna: ";
    for (int i = 0; i < n; i++) cout << col[i] << " ";
    cout << "\nVector resultado (fila^2 + col^2): ";
    for (int i = 0; i < n; i++) cout << resultado[i] << " ";
    cout << endl;

    // recorremos la matriz para contar cuántos números primos contiene
    int primos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = M[i][j];
            bool esPrimo = true;

            //los números menores que 2 no son primos
            if (x < 2) esPrimo = false;

            // comprobamos si el número tiene divisores distintos de 1 y de sí mismo
            for (int d = 2; d * d <= x && esPrimo; d++) {
                if (x % d == 0) esPrimo = false;
            }

            // si es primo, aumentamos el contador
            if (esPrimo) primos++;
        }
    }
    cout << "\nCantidad de primos: " << primos << endl;

    // contamos los números pares, impares y divisibles por 3 de la matriz
    int pares = 0, impares = 0, div3 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] % 2 == 0) pares++;
            else impares++;
            if (M[i][j] % 3 == 0) div3++;
        }
    }

    // mostramos la cantidad de elementos encontrados en cada caso
    cout << "Pares: " << pares << endl;
    cout << "Impares: " << impares << endl;
    cout << "Divisibles por 3: " << div3 << endl;

    // sumamos los elementos de cada columna y guardamos los resultados en un vector
    const double PI = acos(-1.0);
    vector<int> sumaCol(n, 0);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            sumaCol[j] += M[i][j];

    // convertimos cada suma de grados a radianes y calculamos su seno
    // mostramos los resultados en una tabla con dos columnas
    cout << "\nSuma columna (X)\tSeno (Y)\n";
    for (int j = 0; j < n; j++) {
        double rad = sumaCol[j] * PI / 180.0;
        cout << sumaCol[j] << "\t\t\t" << sin(rad) << endl;
    }

    //convertimos la matriz en un vector de una sola dimensión
    // mientras guardamos los elementos, también calculamos su suma total
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

    // calculamos el promedio de todos los elementos de la matriz
    double promedio = total / (n * n);
    cout << "\nPromedio: " << promedio << endl;

    // verificamos que el promedio no sea cero para poder realizar la división
    if (promedio == 0) {
        cout << "El promedio es 0, no se puede dividir." << endl;
    } else {
        //dividimos cada elemento del vector entre el promedio y mostramos los resultados
        cout << "Vector dividido por el promedio:\n";
        for (int i = 0; i < n * n; i++) {
            v[i] = v[i] / promedio;
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
