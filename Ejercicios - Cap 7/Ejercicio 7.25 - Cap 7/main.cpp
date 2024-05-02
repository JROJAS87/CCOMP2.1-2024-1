// En este ejercicio, desarrollarás varios enfoques de fuerza bruta para resolver el problema de las Ocho Reinas presentado en el ejercicio 7.24.
// 1) Resuelve el ejercicio de las Ocho Reinas utilizando la técnica de fuerza bruta aleatoria desarrollada en el ejercicio 7.23.
// 2) Utiliza una técnica exhaustiva, es decir, prueba todas las combinaciones posibles de ocho reinas.
// 3) ¿Por qué crees que el enfoque exhaustivo de fuerza bruta puede no ser apropiado para resolver el problema del Recorrido del Caballo?
// 4) Compara y contrasta los enfoques de fuerza bruta aleatoria y exhaustiva en general.



#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

using namespace std;

// Función para verificar si una combinación es válida
bool esValida(int queen_positions[]) {
    for (int i = 1; i <= 8; i++) {
        for (int j = i + 1; j <= 8; j++) {
            if (queen_positions[i] == queen_positions[j] || abs(queen_positions[i] - queen_positions[j]) == abs(i - j)) {
                return false; // Dos reinas están en la misma fila o en la misma diagonal
            }
        }
    }
    return true; // La combinación es válida
}

// Función para imprimir el tablero con las reinas
void imprimirTablero(int queen_positions[]) {
    cout << "La solución es:\n\n";
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (queen_positions[j] == i)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}





// Función principal para el ejercicio 1
void ejercicio1() {
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios
    int queen_positions[9]; // Arreglo para almacenar la posición de las reinas (usamos del índice 1 al 8)

    while (true) {
        // Generar una configuración aleatoria de las reinas
        for (int i = 1; i <= 8; i++) {
            queen_positions[i] = rand() % 8 + 1; // Colocar la reina en una posición aleatoria de la columna i
        }

        // Verificar si la configuración es válida
        if (esValida(queen_positions)) {
            imprimirTablero(queen_positions);
            break;
        }
    }
}





// Función principal para el ejercicio 2
void ejercicio2() {
    int soluciones = 0;
    int queen_positions[9]; // Arreglo para almacenar la posición de las reinas (usamos del índice 1 al 8)

    // Generar todas las combinaciones posibles de ubicaciones de las reinas
    for (queen_positions[1] = 1; queen_positions[1] <= 8; queen_positions[1]++) {
        for (queen_positions[2] = 1; queen_positions[2] <= 8; queen_positions[2]++) {
            for (queen_positions[3] = 1; queen_positions[3] <= 8; queen_positions[3]++) {
                for (queen_positions[4] = 1; queen_positions[4] <= 8; queen_positions[4]++) {
                    for (queen_positions[5] = 1; queen_positions[5] <= 8; queen_positions[5]++) {
                        for (queen_positions[6] = 1; queen_positions[6] <= 8; queen_positions[6]++) {
                            for (queen_positions[7] = 1; queen_positions[7] <= 8; queen_positions[7]++) {
                                for (queen_positions[8] = 1; queen_positions[8] <= 8; queen_positions[8]++) {
                                    // Verificar si la combinación es válida
                                    if (esValida(queen_positions)) {
                                        soluciones++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Imprimir el número total de soluciones encontradas
    cout << "Número total de soluciones encontradas: " << soluciones << endl;
}





// Función principal que permite ejecutar los dos ejercicios
int main() {
  
    cout << "Ejercicio 1: Resolución del problema de las Ocho Reinas con fuerza bruta aleatoria\n";
    ejercicio1();
  
    cout << "\n\nEjercicio 2: Resolución del problema de las Ocho Reinas con fuerza bruta exhaustiva:\n";
    ejercicio2();

  cout << "\nEjercicio 3: El enfoque exhaustivo de fuerza bruta puede no ser apropiado para resolver el problema del Recorrido del Caballo debido al gran número de combinaciones que deben probarse. Esto llevaría a un tiempo de ejecución extremadamente largo y no garantizaría encontrar una solución óptima.\n";

  cout << "\nEjercicio 4: En comparación, el enfoque de fuerza bruta aleatoria es más rápido y puede proporcionar soluciones aceptables en un tiempo razonable, pero no garantiza la solución óptima. Por otro lado, el enfoque exhaustivo de fuerza bruta garantiza encontrar la solución óptima si existe, pero puede ser extremadamente lento y no es práctico para problemas con un espacio de búsqueda grande.\n";
    return 0;
}
