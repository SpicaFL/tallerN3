// Punto 8: gestion de calificaciones (n estudiantes x m asignaturas)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // pedimos la cantidad de estudiantes y asignaturas, verificando que sean mayores que cero
    int n, m;
    do {
        cout << "Numero de estudiantes (n): ";
        cin >> n;
    } while (n <= 0);
    do {
        cout << "Numero de asignaturas (m): ";
        cin >> m;
    } while (m <= 0);

    // creamos una matriz donde cada fila representa un estudiante y cada columna una asignatura
    vector<vector<double>> notas(n, vector<double>(m));

    // pedimos las calificaciones de cada estudiante y verificamos que estén entre 0.0 y 5.0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double nota;
            do {
                cout << "Nota del estudiante " << i << " en asignatura " << j << " (0.0 - 5.0): ";
                cin >> nota;

                // si la nota está fuera del rango permitido, mostramos un mensaje de error
                if (nota < 0.0 || nota > 5.0)
                    cout << "Nota invalida, debe estar entre 0.0 y 5.0.\n";
            } while (nota < 0.0 || nota > 5.0);

            // guardamos la nota en la posición correspondiente de la matriz
            notas[i][j] = nota;
        }
    }

    // calculamos el promedio de cada estudiante sumando sus notas y dividiendo entre las asignaturas
    vector<double> promEst(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            promEst[i] += notas[i][j];
        promEst[i] = promEst[i] / m;
    }

    // calculamos el promedio de cada asignatura sumando las notas y dividiendo entre los estudiantes
    vector<double> promAsig(m, 0.0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++)
            promAsig[j] += notas[i][j];
        promAsig[j] = promAsig[j] / n;
    }

    // mostramos el promedio obtenido por cada estudiante
    cout << "\nPromedio de cada estudiante:\n";
    for (int i = 0; i < n; i++)
        cout << "Estudiante " << i << ": " << promEst[i] << endl;

    // mostramos el promedio obtenido en cada asignatura
    cout << "\nPromedio de cada asignatura:\n";
    for (int j = 0; j < m; j++)
        cout << "Asignatura " << j << ": " << promAsig[j] << endl;

    // buscamos al estudiante que tiene el promedio más alto
    // comparamos los promedios y guardamos la posición del mayor
    int mejorEst = 0;
    for (int i = 1; i < n; i++)
        if (promEst[i] > promEst[mejorEst]) mejorEst = i;

    // buscamos la asignatura que tiene el promedio mas bajo
    // comparamos los promedios y guardamos la posición del menor
    int peorAsig = 0;
    for (int j = 1; j < m; j++)
        if (promAsig[j] < promAsig[peorAsig]) peorAsig = j;

    // mostramos el estudiante con mejor promedio y la asignatura con menor promedio
    // también mostramos sus posiciónes y los valores correspondientes
    cout << "\nEstudiante con el promedio mas alto: " << mejorEst
         << " (" << promEst[mejorEst] << ")" << endl;
    cout << "Asignatura con el promedio mas bajo: " << peorAsig
         << " (" << promAsig[peorAsig] << ")" << endl;

    return 0;
}
