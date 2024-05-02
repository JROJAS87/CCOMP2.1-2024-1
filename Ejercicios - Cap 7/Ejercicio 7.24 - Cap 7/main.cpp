// El problema de las Ocho Reinas es otro desafío para los aficionados al ajedrez. En términos simples: ¿Es posible colocar ocho reinas en un tablero de ajedrez vacío de modo que ninguna reina esté "atacando" a otra, es decir, que ninguna pareja de reinas esté en la misma fila, columna o diagonal?  Utiliza el enfoque desarrollado en el ejercicio 7.22 para formular una heurística para resolver el problema de las Ocho Reinas. Ejecuta tu programa. 

//Pista: Es posible asignar un valor a cada casilla del tablero de ajedrez indicando cuántas casillas de un tablero vacío se "eliminan" si se coloca una reina en esa casilla. Cada una de las esquinas tendría asignado el valor 22, como se muestra en la Figura 7.26. Una vez que estos "números de eliminación" se colocan en las 64 casillas, una heurística adecuada podría ser: Colocar la siguiente reina en la casilla con el número de eliminación más pequeño. ¿Por qué esta estrategia es intuitivamente atractiva?



#include <iostream>

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

// Prototipos de las funciones
void proceso();
void ensayar(int i);

// Función principal
int main() {
    cout << "Problema de las 8 Reinas:\n";
    proceso();
    return 0;
}

// Función que realiza el proceso de ensayo para las reinas
void ensayar(int i) {
    int j = 0;
    do {
        j++;
        acertado = false;
        if (f(j) && di(i + j) && dn(i - j)) {
            c(i) = j;
            f(j) = di(i + j) = dn(i - j) = false;
            if (i < 8) {
                ensayar(i + 1);
                if (!acertado)
                    f(j) = di(i + j) = dn(i - j) = true;
            } else
                acertado = true;
        }
    } while (!acertado && j != 8);
}

// Función principal que inicializa las variables y llama a la función de ensayo
void proceso() {
    for (int i = 1; i <= 8; i++)
        f(i) = true;
    for (int i = 2; i <= 16; i++)
        di(i) = true;
    for (int i = -7; i <= 7; i++)
        dn(i) = true;

    ensayar(1);

    if (acertado) {

        cout << "\n\nLa solución es:\n\n";
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

  cout << "\n\n¿Por qué esta estrategia es intuitivamente atractiva?";
  cout << "\n\nRpta: Esta estrategia es intuitivamente atractiva porque minimiza el riesgo de \"ataques\" entre las reinas al priorizar las casillas que tienen menos influencia sobre otras, es decir, aquellas que afectan a menos casillas en la misma fila, columna o diagonal. Al colocar la próxima reina en una casilla con un número de eliminación más pequeño, se reducen las posibilidades de conflicto entre las reinas, lo que aumenta la probabilidad de encontrar una disposición válida en el tablero." << endl; 
}
