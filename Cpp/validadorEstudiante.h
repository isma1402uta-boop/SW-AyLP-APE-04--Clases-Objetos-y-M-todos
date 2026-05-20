#ifndef VALIDADOR_ESTUDIANTE_H
#define VALIDADOR_ESTUDIANTE_H

#include <string>

// CLASE: ValidadorEstudiante
// Objetivo: Blindar la identidad del alumno (Cédula, Nombres, Apellidos)
class ValidadorEstudiante {
private:
    // Método auxiliar matemático interno para verificar la cédula de Ecuador
    bool esCedulaRealEcuatoriana(const std::string& cedula);

public:
    // Constructor por defecto
    ValidadorEstudiante();

    // Captura y valida estructuralmente la cédula en la consola
    std::string validarCedula(const std::string& mensaje);

    // Captura y valida nombres o apellidos (admite espacios, tildes y Ñ)
    std::string validarTexto(const std::string& mensaje);
};

#endif // VALIDADOR_ESTUDIANTE_H