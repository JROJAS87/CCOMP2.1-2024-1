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

// Prototipos de las funciones recursivas
void proceso_recursivo();
void ensayar_recursivo(int i);

// Función recursiva que realiza el proceso de ensayo para las reinas
void ensayar_recursivo(int i) {
    int j = 0;
    do {
        j++;
        acertado = false;
        if (f(j) && di(i + j) && dn(i - j)) {
            c(i) = j;
            f(j) = di(i + j) = dn(i - j) = false;
            if (i < 8) {
                ensayar_recursivo(i + 1);
                if (!acertado)
                    f(j) = di(i + j) = dn(i - j) = true;
            } else
                acertado = true;
        }
    } while (!acertado && j != 8);
}

// Función recursiva principal
void proceso_recursivo() {
    // Inicializar variables globales
    acertado = false;
    for (int i = 1; i <= 8; i++)
        f(i) = true;
    for (int i = 2; i <= 16; i++)
        di(i) = true;
    for (int i = -7; i <= 7; i++)
        dn(i) = true;

    ensayar_recursivo(1);

    if (acertado) {
        cout << "\n\nLa solución recursiva es:\n\n";
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (c(j) == i)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    } else
        cout << "\n\nNO HAY SOLUCION.\n";
}

// Main para la forma recursiva
int main() {
    cout << "Problema de las 8 Reinas (Recursivo):\n";
    proceso_recursivo();
    return 0;
}