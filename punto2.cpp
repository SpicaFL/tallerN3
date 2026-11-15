// Punto 2: media de n valores aleatorios y elementos mayores que la media
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // inicializamos los números aleatorios para que cambien en cada ejecución
    srand(time(0));

    // pedimos un número entero positivo y verificamos que sea mayor que cero
    int n;
    do {
        cout << "Ingrese n (positivo): ";
        cin >> n;
    } while (n <= 0);

    // creamos un vector de n elementos y lo llamamos con números aleatorios entre 0 y 10
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

    // creamos un segundo vector para guardar los elementos mayores que la media
    vector<int> mayores;
    for (int i = 0; i < n; i++) {
        if (v[i] > media) mayores.push_back(v[i]);
    }

    // mostramos los elementos que superan la media
    // si no hay ninguno, indicamos que no se encontraron
    cout << "Elementos mayores que la media: ";
    if (mayores.size() == 0) cout << "(ninguno)";
    for (size_t i = 0; i < mayores.size(); i++) cout << mayores[i] << " ";
    cout << endl;

    return 0;
}
