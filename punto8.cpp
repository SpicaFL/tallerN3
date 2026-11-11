// Punto 8: gestion de calificaciones (n estudiantes x m asignaturas)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    do {
        cout << "Numero de estudiantes (n): ";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Numero de asignaturas (m): ";
        cin >> m;
    } while (m <= 0);
    vector<vector<double>> notas(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double nota;
            do {
                cout << "Nota del estudiante " << i << " en asignatura " << j << " (0.0 - 5.0): ";
                cin >> nota;
                if (nota < 0.0 || nota > 5.0)
                    cout << "Nota invalida, debe estar entre 0.0 y 5.0.\n";
            } while (nota < 0.0 || nota > 5.0);
            notas[i][j] = nota;
        }
    }

    vector<double> promEst(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            promEst[i] += notas[i][j];
        promEst[i] = promEst[i] / m;
    }

    vector<double> promAsig(m, 0.0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++)
            promAsig[j] += notas[i][j];
        promAsig[j] = promAsig[j] / n;
    }

    cout << "\nPromedio de cada estudiante:\n";
    for (int i = 0; i < n; i++)
        cout << "Estudiante " << i << ": " << promEst[i] << endl;

    cout << "\nPromedio de cada asignatura:\n";
    for (int j = 0; j < m; j++)
        cout << "Asignatura " << j << ": " << promAsig[j] << endl;

    int mejorEst = 0;
    for (int i = 1; i < n; i++)
        if (promEst[i] > promEst[mejorEst]) mejorEst = i;

    int peorAsig = 0;
    for (int j = 1; j < m; j++)
        if (promAsig[j] < promAsig[peorAsig]) peorAsig = j;

    cout << "\nEstudiante con el promedio mas alto: " << mejorEst
         << " (" << promEst[mejorEst] << ")" << endl;
    cout << "Asignatura con el promedio mas bajo: " << peorAsig
         << " (" << promAsig[peorAsig] << ")" << endl;

    return 0;
}