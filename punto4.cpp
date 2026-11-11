// Punto 4: factorial de cada elemento de un vector aleatorio
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int factorial(int x) {
    int f = 1;
    for (int i = 2; i <= x; i++) {
        f = f * i;
    }
    return f;
}

int main() {
    srand(time(0));
    int n;
    do {
        cout << "Ingrese n (positivo): ";
        cin >> n;
    } while (n <= 0);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11;
    }

    cout << "Elemento\tFactorial\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\t\t" << factorial(v[i]) << endl;
    }

    return 0;
}