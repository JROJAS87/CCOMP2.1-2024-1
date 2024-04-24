#include <array>
#include "GradeBook.h" // Definición de la clase GradeBook
using namespace std;

int main() {
   // array de calificaciones de estudiantes
   const array<int, GradeBook::students> calificaciones{ 
      87, 68, 94, 100, 83, 78, 85, 91, 76, 87}; // asumiendo que GradeBook::students es el tamaño
   string nombreCurso{"CS101 Introducción a la programación en C++"};

   GradeBook miLibroCalificaciones(nombreCurso, calificaciones);
   miLibroCalificaciones.mostrarMensaje();
   miLibroCalificaciones.procesarCalificaciones();
}
