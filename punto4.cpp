// Punto 4: factorial de cada elemento de un vector aleatorio
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// creamos una función que recibe un número entero y devuelve su factorial
int factorial(int x) {
    int f = 1;

    // multiplicamos los números desde 2 hasta el valor recibido
    for (int i = 2; i <= x; i++) {
        f = f * i;
    }

    //devolvemos el factorial calculado
    return f;
}

int main() {
    // inicializamos los números aleatorios para que cambien en cada ejecución
    srand(time(0));

    // pedimos un número entero positivo y verificamos que sea mayor que cero
    int n;
    do {
        cout << "Ingrese n (positivo): ";
        cin >> n;
    } while (n <= 0);

    // creamos un vector de n elementos y lo llenamos con números aleatorios entre 0 y 10
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11;
    }

    // recorremos el vector y calculamos el factorial de cada elemento usando la función
    // mostramos cada número junto con su factorial en una tabla
    cout << "Elemento\tFactorial\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\t\t" << factorial(v[i]) << endl;
    }

    return 0;
}
