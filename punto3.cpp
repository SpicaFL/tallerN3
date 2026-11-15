// Punto 3: igual al punto 2, pero ordenando de menor a mayor los mayores que la media
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // inicializamos los números aleatorios para que cambien en cada ejecución
    srand(time(0));

    //pedimos un número entero positivo y verificamos que sea mayor que cero
    int n;
    do {
        cout << "Ingrese n (positivo): ";
        cin >> n;
    } while (n <= 0);

    // creamos un vector de n elementos con números aleatorios entre 0 y 10
    vector<int> v(n);
    int suma = 0;
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11;
        suma += v[i];
    }

    // calculamos la media dividiendo la suma de los elementos entre n
    double media = (double)suma / n;

    // mostramos el vector generado y la media obtenida
    cout << "Vector: ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\nMedia: " << media << endl;

    // guardamos en un segundo vector los elementos que son mayores que la media
    vector<int> mayores;
    for (int i = 0; i < n; i++) {
        if (v[i] > media) mayores.push_back(v[i]);
    }

    // ordenamos los elementos mayores que la media de menor a mayor
    // comparamos los valores vecinos y los intercambios si están en el orden incorrecto
    int m = mayores.size();
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (mayores[j] > mayores[j + 1]) {
                int aux = mayores[j];
                mayores[j] = mayores[j + 1];
                mayores[j + 1] = aux;
            }
        }
    }

    // mostramos los elementos mayores que la media ya ordenados
    // si no encontramos ninguno, mostramos un mensaje
    cout << "Mayores que la media (ordenados): ";
    if (m == 0) cout << "(ninguno)";
    for (int i = 0; i < m; i++) cout << mayores[i] << " ";
    cout << endl;

    return 0;
}
