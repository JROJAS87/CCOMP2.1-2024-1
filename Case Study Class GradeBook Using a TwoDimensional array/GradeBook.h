#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
#include <array>
#include <iostream>
#include <iomanip>

// Definición de la clase GradeBook
class GradeBook {
public:
    // número constante de estudiantes que tomaron el examen
    static const size_t students = 10;

    // constructor que inicializa el nombre del curso y el array de calificaciones
    GradeBook(const std::string& nombre,
              const std::array<int, students>& calificacionesArray)
        : nombreCurso{nombre}, calificaciones{calificacionesArray} {
    }

    // función para establecer el nombre del curso
    void establecerNombreCurso(const std::string& nombre) {
        nombreCurso = nombre; // almacenar el nombre del curso
    }

    // función para obtener el nombre del curso
    const std::string& obtenerNombreCurso() const {
        return nombreCurso;
    }

    // muestra un mensaje de bienvenida al usuario del GradeBook
    void mostrarMensaje() const {
        // llama a obtenerNombreCurso para obtener el nombre del curso de este GradeBook
        std::cout << "Bienvenido al libro de calificaciones para\n" << obtenerNombreCurso()
                  << "!" << std::endl;
    }

    // realiza varias operaciones en los datos (ninguna modifica los datos)
    void procesarCalificaciones() const {
        mostrarCalificaciones(); // muestra el array de calificaciones

        // llama a la función obtenerPromedio para calcular el promedio de calificaciones
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << "\nEl promedio de la clase es: " << obtenerPromedio() << std::endl;

        // llama a las funciones obtenerMinimo y obtenerMaximo
        std::cout << "La calificación más baja es: " << obtenerMinimo()
                  << "\nLa calificación más alta es: " << obtenerMaximo() << std::endl;

        mostrarGraficoBarras(); // muestra el gráfico de distribución de calificaciones
    }

    // encuentra la calificación mínima
    int obtenerMinimo() const {
        int calificacionBaja{100}; // supone que la calificación más baja es 100

        // recorre el array de calificaciones
        for (int calificacion : calificaciones) {
            // si la calificación actual es menor que la calificaciónBaja, asígnala a calificacionBaja
            if (calificacion < calificacionBaja) {
                calificacionBaja = calificacion; // nueva calificación más baja
            }
        }

        return calificacionBaja; // devuelve la calificación más baja
    }

    // encuentra la calificación máxima
    int obtenerMaximo() const {
        int calificacionAlta{0}; // supone que la calificación más alta es 0

        // recorre el array de calificaciones
        for (int calificacion : calificaciones) {
            // si la calificación actual es mayor que calificacionAlta, asígnala a calificacionAlta
            if (calificacion > calificacionAlta) {
                calificacionAlta = calificacion; // nueva calificación más alta
            }
        }

        return calificacionAlta; // devuelve la calificación más alta
    }

    // determina el promedio de calificaciones para el examen
    double obtenerPromedio() const {
        int total{0}; // inicializa el total

        // suma las calificaciones en el array
        for (int calificacion : calificaciones) {
            total += calificacion;
        }

        // devuelve el promedio de las calificaciones
        return static_cast<double>(total) / calificaciones.size();
    }

    // muestra el gráfico de barras que muestra la distribución de calificaciones
    void mostrarGraficoBarras() const {
        std::cout << "\nDistribución de calificaciones:" << std::endl;

        // almacena la frecuencia de las calificaciones en cada rango de 10 calificaciones
        const size_t tamanoFrecuencia{11};
        std::array<unsigned int, tamanoFrecuencia> frecuencia{}; // inicializar a 0s

        // para cada calificación, incrementa la frecuencia apropiada
        for (int calificacion : calificaciones) {
            ++frecuencia[calificacion / 10];
        }

        // para cada frecuencia de calificación, imprime la barra en el gráfico
        for (size_t contador{0}; contador < tamanoFrecuencia; ++contador) {
            // imprime etiquetas de barra ("0-9:", ..., "90-99:", "100:")
            if (0 == contador) {
                std::cout << "  0-9: ";
            } else if (10 == contador) {
                std::cout << "  100: ";
            } else {
                std::cout << contador * 10 << "-" << (contador * 10) + 9 << ": ";
            }

            // imprime la barra de asteriscos
            for (unsigned int estrellas{0}; estrellas < frecuencia[contador]; ++estrellas) {
                std::cout << '*';
            }

            std::cout << std::endl; // comienza una nueva línea de salida
        }
    }

    // muestra el contenido del array de calificaciones
    void mostrarCalificaciones() const {
        std::cout << "\nLas calificaciones son:\n\n";

        // imprime la calificación de cada estudiante
        for (size_t estudiante{0}; estudiante < calificaciones.size(); ++estudiante) {
            std::cout << "Estudiante " << std::setw(2) << estudiante + 1 << ": "
                      << std::setw(3) << calificaciones[estudiante] << std::endl;
        }
    }

private:
    std::string nombreCurso; // nombre del curso para este libro de calificaciones
    std::array<int, students> calificaciones; // array de calificaciones de estudiantes
};

#endif // GRADEBOOK_H
