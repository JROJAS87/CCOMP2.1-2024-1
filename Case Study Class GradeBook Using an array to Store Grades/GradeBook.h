#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <array>
#include <iomanip> // Manipuladores de flujo parametrizados
#include <iostream>
#include <string>

class GradeBook {
public:
  // Constantes
  static const size_t students = 10;
  static const size_t tests = 3;

  // Constructor de dos argumentos inicializa courseName y grades array
  GradeBook(const std::string &name,
            std::array<std::array<int, tests>, students> &gradesArray)
      : courseName(name), grades(gradesArray) {}

  // Función para establecer el nombre del curso
  void setCourseName(const std::string &name) {
    courseName = name; // Guardar el nombre del curso
  }

  // Función para obtener el nombre del curso
  const std::string &getCourseName() const { return courseName; }

  // Mostrar un mensaje de bienvenida al usuario de GradeBook
  void displayMessage() const {
    // Llamar a getCourseName para obtener el nombre del curso
    std::cout << "Bienvenido al libro de calificaciones para\n"
              << getCourseName() << "!" << std::endl;
  }

  // Realizar diversas operaciones en los datos
  void processGrades() const {
    outputGrades(); // Mostrar la matriz de calificaciones

    // Llamar a las funciones getMinimum y getMaximum
    std::cout << "\nLa calificación más baja en el libro de calificaciones es "
              << getMinimum()
              << "\nLa calificación más alta en el libro de calificaciones es "
              << getMaximum() << std::endl;

    outputBarChart(); // Mostrar el gráfico de distribución de calificaciones
  }

  // Encontrar la calificación mínima en todo el libro de calificaciones
  int getMinimum() const {
    int lowGrade{100}; // Suponer que la calificación más baja es 100

    // Iterar a través de las filas de la matriz de calificaciones
    for (auto const &student : grades) {
      // Iterar a través de las columnas de la fila actual
      for (auto const &grade : student) {
        if (grade < lowGrade) { // Si la calificación es menor que lowGrade
          lowGrade = grade; // La calificación es la nueva calificación más baja
        }
      }
    }

    return lowGrade; // Devolver la calificación más baja
  }

  // Encontrar la calificación máxima en todo el libro de calificaciones
  int getMaximum() const {
    int highGrade{0}; // Suponer que la calificación más alta es 0

    // Iterar a través de las filas de la matriz de calificaciones
    for (auto const &student : grades) {
      // Iterar a través de las columnas de la fila actual
      for (auto const &grade : student) {
        if (grade > highGrade) { // Si la calificación es mayor que highGrade
          highGrade =
              grade; // La calificación es la nueva calificación más alta
        }
      }
    }

    return highGrade; // Devolver la calificación más alta
  }

  // Determinar la calificación promedio para un conjunto particular de
  // calificaciones
  double getAverage(const std::array<int, tests> &setOfGrades) const {
    int total{0}; // Inicializar el total

    // Sumar las calificaciones en el arreglo
    for (int grade : setOfGrades) {
      total += grade;
    }

    // Devolver el promedio de las calificaciones
    return static_cast<double>(total) / setOfGrades.size();
  }

  // Mostrar el gráfico de barras que muestra la distribución de calificaciones
  void outputBarChart() const {
    std::cout << "\nDistribución de calificaciones en general:" << std::endl;

    // Almacena la frecuencia de las calificaciones en cada rango de 10
    // calificaciones
    const size_t frequencySize{11};
    std::array<unsigned int, frequencySize> frequency{}; // Inicializar a 0s

    // Por cada calificación, incrementar la frecuencia apropiada
    for (auto const &student : grades) {
      for (auto const &test : student) {
        ++frequency[test / 10];
      }
    }

    // Por cada frecuencia de calificación, imprimir la barra en el gráfico
    for (size_t count{0}; count < frequencySize; ++count) {
      // Imprimir la etiqueta de la barra ("0-9:", ..., "90-99:", "100:")
      if (0 == count) {
        std::cout << "  0-9: ";
      } else if (10 == count) {
        std::cout << "  100: ";
      } else {
        std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
      }

      // Imprimir la barra de asteriscos
      for (unsigned int stars{0}; stars < frequency[count]; ++stars)
        std::cout << '*';

      std::cout << std::endl; // Iniciar una nueva línea de salida
    }
  }

  // Mostrar el contenido de la matriz de calificaciones
  void outputGrades() const {
    std::cout << "\nLas calificaciones son:\n\n";
    std::cout << "            "; // Alinear las cabeceras de columna

    // Crear una cabecera de columna para cada prueba
    for (size_t test{0}; test < tests; ++test) {
      std::cout << "Prueba " << test + 1 << "  ";
    }

    std::cout << "Promedio" << std::endl;

    // Crear filas/columnas de texto representando las calificaciones de la
    // matriz
    for (size_t student{0}; student < grades.size(); ++student) {
      std::cout << "Estudiante " << std::setw(2) << student + 1;

      // Imprimir las calificaciones del estudiante
      for (size_t test{0}; test < grades[student].size(); ++test) {
        std::cout << std::setw(8) << grades[student][test];
      }

      // Llamar a la función miembro getAverage para calcular el promedio del
      // estudiante Pasar una fila de calificaciones como argumento
      double average = getAverage(grades[student]);
      std::cout << std::setw(9) << std::setprecision(2) << std::fixed << average
                << std::endl;
    }
  }

private:
  std::string courseName; // Nombre del curso para este libro de calificaciones
  std::array<std::array<int, tests>, students> &grades;
};

#endif // GRADEBOOK_H
