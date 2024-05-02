// El ejercicio 7.29 te pide modificar el programa de las Ocho Reinas que creaste en el ejercicio 7.24 para resolver el problema de forma recursiva.



#include <iostream>
#include <stack>

using namespace std;

// Definición de variables globales y macros
bool acertado;
int posiciones_en_columna[8];
bool reina_en_fila[8];
bool reina_en_diagonal_normal[15];
bool reina_en_diagonal_inversa[15];

#define c(i) posiciones_en_columna[(i)-1]
#define f(i) reina_en_fila[(i)-1]
#define dn(i) reina_en_diagonal_normal[(i)+7]
#define di(i) reina_en_diagonal_inversa[(i)-2]

// Función iterativa principal
void proceso_iterativo() {
    stack<int> columnas;
    int columna = 1;
    bool solucion = false;

    // Inicializar variables globales
    for (int i = 0; i < 8; i++) {
        posiciones_en_columna[i] = 0;
        reina_en_fila[i] = true;
    }
    for (int i = 0; i < 15; i++) {
        reina_en_diagonal_normal[i] = true;
        reina_en_diagonal_inversa[i] = true;
    }

    while (columna > 0) {
        if (columna == 9) {
            solucion = true;
            break;
        }

        bool colocada = false;
        for (int fila = 1; fila <= 8; fila++) {
            if (f(fila) && di(columna + fila) && dn(columna - fila)) {
                c(columna) = fila;
                f(fila) = di(columna + fila) = dn(columna - fila) = false;
                columnas.push(columna);
                colocada = true;
                columna++;
                break;
            }
        }

        if (!colocada) {
            if (!columnas.empty()) {
                columna = columnas.top();
                columnas.pop();
                f(c(columna)) = di(columna + c(columna)) = dn(columna - c(columna)) = true;
                columna++;
            } else {
                break;
            }
        }
    }

    if (solucion) {
        cout << "\n\nLa solución iterativa es:\n\n";
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (c(j) == i)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    } else {
        cout << "\n\nNO HAY SOLUCION.\n";
    }
}

// Main para la forma iterativa
int main() {
    cout << "Problema de las 8 Reinas (Iterativo):\n";
    proceso_iterativo();
    return 0;
}
