// Un palíndromo es una cadena que se lee igual de adelante hacia atrás que de atrás hacia adelante. Ejemplos de palíndromos incluyen "radar" y "Able was I ere I saw Elba". Una frase palindrómica es un palíndromo si se ignoran los signos de puntuación y los espacios. Escribe una función recursiva `testPalindrome` que devuelva true si una cadena es un palíndromo, y false en caso contrario. Ignora todos los espacios, comas, puntos y signos de interrogación en la oración. Por lo tanto, "red roses run no risk, sir, on nurses order." se considera un palíndromo. Ten en cuenta que, al igual que con un arreglo, el operador de corchetes ([]) se puede utilizar para iterar a través de los caracteres en una cadena.



#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Función recursiva para verificar si una cadena es un palíndromo
bool testPalindrome(string str, int start, int end) {
    // Caso base: cuando solo hay un carácter o ningún carácter
    if (start >= end) {
        return true;
    }

    // Ignorar espacios, comas, puntos y signos de interrogación
    while (!isalpha(str[start]) && start < end) {
        start++;
    }
    while (!isalpha(str[end]) && end > start) {
        end--;
    }

    // Convertir a minúsculas para comparación insensible a mayúsculas y minúsculas
    char c1 = tolower(str[start]);
    char c2 = tolower(str[end]);

    // Verificar si los caracteres son iguales
    if (c1 != c2) {
        return false;
    }

    // Llamada recursiva con los índices actualizados
    return testPalindrome(str, start + 1, end - 1);
}

int main() {
    string sentence;
    cout << "Ingrese una oracion: ";
    getline(cin, sentence);

    if (testPalindrome(sentence, 0, sentence.length() - 1)) {
        cout << "La oracion es un palindromo." << endl;
    } else {
        cout << "La oracion no es un palindromo." << endl;
    }

    return 0;
}
