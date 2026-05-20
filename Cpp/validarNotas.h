#ifndef VALIDARNOTAS_H
#define VALIDARNOTAS_H

#include <string>


// CLASE: LectorDatos
// Objetivo: Declarar los métodos que blindarán la entrada de datos

class LectorDatos {
public:
    // Constructor por defecto
    LectorDatos();

    // Valida y lee un número entero (ideal para el menú principal)
    int validarEntero(const std::string& mensaje);

    // Valida y lee una nota flotante entre 0 y 10 (Requerimiento APE 04)
    float validarNota(const std::string& mensaje);
};

#endif // VALIDARNOTAS_H