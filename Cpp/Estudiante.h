#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#include <string>

class Estudiantes {
private:
    // Atributos privados protegidos (Encapsulamiento)
    std::string cedula;
    std::string nombre;
    std::string apellido;
    float nota1;
    float nota2;
    float nota3;
    float promedio;

public:
    // Constructores
    Estudiantes(); // Constructor por defecto
    Estudiantes(std::string _cedula, std::string _nombre, std::string _apellido, float _n1, float _n2, float _n3);

    // Métodos Get y Set
    void setCedula(std::string _cedula);
    std::string getCedula() const;

    void setNombre(std::string _nombre);
    std::string getNombre() const;

    void setApellido(std::string _apellido);
    std::string getApellido() const;

    void setNota1(float _n1);
    float getNota1() const;

    void setNota2(float _n2);
    float getNota2() const;

    void setNota3(float _n3);
    float getNota3() const;

    // Solo se permite obtener el promedio, la modificación es interna
    float getPromedio() const; 

    // Métodos de Lógica del Negocio
    void calcularPromedio();
    bool determinarAprobacion() const; 
    void mostrarInformacion() const;
};

#endif // ESTUDIANTES_H