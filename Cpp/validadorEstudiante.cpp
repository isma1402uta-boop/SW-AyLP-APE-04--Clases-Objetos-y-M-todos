#include "validadorEstudiante.h"
#include <iostream>
#include <limits>
#include <cctype> // Necesaria para operaciones nativas de caracteres (isalpha, isspace)

using namespace std;

// Constructor
ValidadorEstudiante::ValidadorEstudiante() {}


// MÉTODO PRIVADO: Algoritmo matemático del Registro Civil de Ecuador
bool ValidadorEstudiante::esCedulaRealEcuatoriana(const string& cedula) {
    
    // 1. Validar código de provincia (Primeros dos dígitos)
    int provincia = (cedula[0] - '0') * 10 + (cedula[1] - '0');
    if ((provincia < 1 || provincia > 24) && provincia != 30) {
        return false; 
    }

    // 2. Validar el tercer dígito (Debe ser menor a 6 para personas naturales)
    int tercerDigito = cedula[2] - '0';
    if (tercerDigito >= 6) {
        return false;
    }

    // 3. Algoritmo de Coeficientes de Módulo 10
    int coeficientes[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int suma = 0;

    for (int i = 0; i < 9; i++) {
        int valor = (cedula[i] - '0') * coeficientes[i];
        if (valor > 9) {
            valor -= 9; // Si el producto es de dos dígitos, se restan 9
        }
        suma += valor;
    }

    // Calcular dígito verificador esperado
    int digitoVerificadorCalculado = (suma % 10 == 0) ? 0 : 10 - (suma % 10);
    int digitoVerificadorReal = cedula[9] - '0';

    // Compara el cálculo matemático con el último dígito real
    return (digitoVerificadorCalculado == digitoVerificadorReal);
}



// MÉTODO PÚBLICO: Captura y blindaje de Cédula en consola
string ValidadorEstudiante::validarCedula(const string& mensaje) {
    string cedula;
    while (true) {
        cout << mensaje;
        cin >> cedula;
        
        // Limpieza absoluta del búfer para que conviva perfectamente con getlines posteriores
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // FILTRO 1: Longitud exacta
        if (cedula.length() != 10) {
            cout << "-> [ERROR] La cedula debe tener exactamente 10 digitos.\n";
        } 
        // FILTRO 2: Solo caracteres del '0' al '9'
        else if (cedula.find_first_not_of("0123456789") != string::npos) {
            cout << "-> [ERROR] La cedula solo debe contener caracteres numericos.\n";
        } 
        // FILTRO 3: Validación lógica real en el territorio nacional
        else if (!esCedulaRealEcuatoriana(cedula)) {
            cout << "-> [ERROR] El numero de cedula no existe o es invalido en Ecuador.\n";
        } 
        else {
            return cedula; // Cédula totalmente legítima y segura
        }
    }
}


// MÉTODO PÚBLICO: Captura de Nombres y Apellidos en español
string ValidadorEstudiante::validarTexto(const string& mensaje) {
    string texto;
    while (true) {
        cout << mensaje;
        getline(cin, texto); // Permite capturar apellidos o nombres compuestos con espacios

        // FILTRO 1: Validar que no se envíe en blanco o lleno de puros espacios virtuales
        if (texto.empty() || texto.find_first_not_of(' ') == string::npos) {
            cout << "-> [ERROR] El campo no puede quedar vacio. Intente de nuevo.\n";
            continue; 
        }

        bool caracteresValidos = true;
        
        // FILTRO 2: Inspección analítica de cada letra
        for (size_t i = 0; i < texto.length(); i++) {
            char c = texto[i];
            
            // Si es un carácter alfabético estándar en inglés o un espacio, avanza
            if (isalpha(c) || isspace(c)) {
                continue;
            }
            
            // Excepciones nativas añadidas para la gramática hispana (tildes y diéresis)
            if (c == 'ñ' || c == 'Ñ' || 
                c == 'á' || c == 'é' || c == 'í' || c == 'ó' || c == 'ú' ||
                c == 'Á' || c == 'É' || c == 'Í' || c == 'Ó' || c == 'Ú') {
                continue; 
            }
            
            // Si encuentra un número o símbolo no autorizado, levanta la bandera de error
            caracteresValidos = false;
            break;
        }

        if (!caracteresValidos) {
            cout << "-> [ERROR] El campo solo debe contener letras y espacios (sin numeros ni simbolos).\n";
        } else {
            return texto; // Retorna el string sanitizado y correcto
        }
    }
}