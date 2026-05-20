#include "Estudiantes.h"
#include <iostream>
#include <iomanip> 

using namespace std;

// Constructor por defecto
Estudiantes::Estudiantes() {
    cedula = "";
    nombre = "";
    apellido = "";
    nota1 = 0.0f;
    nota2 = 0.0f;
    nota3 = 0.0f;
    promedio = 0.0f;
}

// Constructor parametrizado
Estudiantes::Estudiantes(string _cedula, string _nombre, string _apellido, float _n1, float _n2, float _n3) {
    cedula = _cedula;
    nombre = _nombre;
    apellido = _apellido;
    nota1 = _n1;
    nota2 = _n2;
    nota3 = _n3;
    calcularPromedio(); 
}

// Métodos Get y Set
void Estudiantes::setCedula(string _cedula) { cedula = _cedula; }
string Estudiantes::getCedula() const { return cedula; }

void Estudiantes::setNombre(string _nombre) { nombre = _nombre; }
string Estudiantes::getNombre() const { return nombre; }

void Estudiantes::setApellido(string _apellido) { apellido = _apellido; }
string Estudiantes::getApellido() const { return apellido; }

void Estudiantes::setNota1(float _n1) { nota1 = _n1; calcularPromedio(); }
float Estudiantes::getNota1() const { return nota1; }

void Estudiantes::setNota2(float _n2) { nota2 = _n2; calcularPromedio(); }
float Estudiantes::getNota2() const { return nota2; }

void Estudiantes::setNota3(float _n3) { nota3 = _n3; calcularPromedio(); }
float Estudiantes::getNota3() const { return nota3; }

float Estudiantes::getPromedio() const { return promedio; }

void Estudiantes::calcularPromedio() {
    promedio = (nota1 + nota2 + nota3) / 3.0f;
}

bool Estudiantes::determinarAprobacion() const {
    return (promedio >= 7.0f);
}

void Estudiantes::mostrarInformacion() const {
    cout << "---------------------------------------------\n";
    cout << "Cedula:   " << cedula << "\n";
    cout << "Alumno:   " << apellido << " " << nombre << "\n";
    cout << fixed << setprecision(2); 
    cout << "Nota 1:   " << nota1 << "  |  Nota 2: " << nota2 << "  |  Nota 3: " << nota3 << "\n";
    cout << "Promedio: " << promedio << "\n";
    
    if (determinarAprobacion()) {
        cout << "Estado:   [APROBADO]\n";
    } else {
        cout << "Estado:   [REPROBADO]\n";
    }
    cout << "---------------------------------------------\n";
}