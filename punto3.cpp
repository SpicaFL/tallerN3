// Punto 3: igual al punto 2, pero ordenando de menor a mayor los mayores que la media
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n;
    do {
        cout << "Ingrese n (positivo): ";
        cin >> n;
    } while (n <= 0);

    vector<int> v(n);
    int suma = 0;
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11;
        suma += v[i];
    }
    double media = (double)suma / n;

    cout << "Vector: ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\nMedia: " << media << endl;

    vector<int> mayores;
    for (int i = 0; i < n; i++) {
        if (v[i] > media) mayores.push_back(v[i]);
    }

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

    cout << "Mayores que la media (ordenados): ";
    if (m == 0) cout << "(ninguno)";
    for (int i = 0; i < m; i++) cout << mayores[i] << " ";
    cout << endl;

    return 0;
}