#include <iostream>
#include <vector>
#include "Estudiantes.h"          // Estructura y lógica del alumno
#include "validadorEstudiante.h" // Validación de cédula real, nombres y apellidos
#include "validarNotas.h"         // Clase encargada de validar números y rangos de notas

using namespace std;

// Constante global para asegurar el requerimiento mínimo de la guía práctica
const int MIN_ESTUDIANTES = 5;

int main() {
    // Instanciamos los objetos encargados de la seguridad y captura de datos
    LectorDatos lector;               // Maneja entradas numéricas de notas y menús
    ValidadorEstudiante validadorEst; // Maneja la rigurosidad de los datos personales

    // Vector dinámico para almacenar la lista de objetos de tipo Estudiantes
    vector<Estudiantes> listaEstudiantes;

    int opcion;
    do {
        cout << "\n====================================================\n";
        cout << "   SISTEMA ACADEMICO DE CALIFICACIONES (APE 04)     \n";
        cout << "====================================================\n";
        cout << "1. Registrar Estudiantes (Minimo global: " << MIN_ESTUDIANTES << ")\n";
        cout << "2. Mostrar Listado Completo y Estadisticas de Notas\n";
        cout << "3. Salir del Sistema\n";
        cout << "----------------------------------------------------\n";
        
        // REQUERIMIENTO 7: Validar la entrada del menú principal
        opcion = lector.validarEntero("Seleccione una opcion: ");
        cout << endl;

        switch (opcion) {
            case 1: {
                cout << "=== REGISTRO DE NUEVOS ESTUDIANTES ===\n";
                cout << "Estudiantes registrados actualmente: " << listaEstudiantes.size() << "\n";
                int cantidad = lector.validarEntero("Cual es la cantidad de estudiantes a registrar ahora?: ");
                
                // REQUERIMIENTO 1 OPTIMIZADO: Valida que el total acumulado alcance el mínimo exigido
                while ((listaEstudiantes.size() + cantidad) < MIN_ESTUDIANTES) {
                    cout << "-> [ERROR] El sistema requiere un total minimo acumulado de " << MIN_ESTUDIANTES << " estudiantes.\n";
                    cout << "   Faltan al menos " << (MIN_ESTUDIANTES - listaEstudiantes.size()) << " por registrar.\n";
                    cantidad = lector.validarEntero("Por favor, ingrese una cantidad valida: ");
                }

                // REQUERIMIENTO 1 OPTIMIZADO: Reserva de memoria anticipada para evitar realojamientos costosos    
                listaEstudiantes.reserve(listaEstudiantes.size() + cantidad);

                // Ciclo estructurado para capturar la información de cada alumno
                for (int i = 0; i < cantidad; i++) {
                    cout << "\n--- REGISTRANDO ESTUDIANTE #" << (i + 1) << " DE " << cantidad << " ---\n";
                    
                    // Captura con validación avanzada de identidad (Cédula real de Ecuador)
                    string cedula = validadorEst.validarCedula("Ingrese el numero de cedula: ");
                    string nombre = validadorEst.validarTexto("Ingrese los nombres: ");
                    string apellido = validadorEst.validarTexto("Ingrese los apellidos: ");
                    
                    // REQUERIMIENTO 2 Y 7: Ingresar las 3 notas validando el rango (0.00 - 10.00)
                    float n1 = lector.validarNota("Ingrese la Nota del Parcial 1 (0.00 - 10.00): ");
                    float n2 = lector.validarNota("Ingrese la Nota del Parcial 2 (0.00 - 10.00): ");
                    float n3 = lector.validarNota("Ingrese la Nota del Parcial 3 (0.00 - 10.00): ");

                    // REQUERIMIENTO 3: El constructor parametrizado calcula internamente el promedio
                    Estudiantes nuevoAlumno(cedula, nombre, apellido, n1, n2, n3);
                    
                    // Almacenamiento eficiente de O(1) gracias a la reserva previa de memoria
                    listaEstudiantes.push_back(nuevoAlumno);
                    cout << "-> [EXITO] Estudiante almacenado correctamente.\n";
                }
                break;
            }
            case 2: {
                // Validación de seguridad por si intentan ver reportes sin datos previos
                if (listaEstudiantes.empty()) {
                    cout << "-> [AVISO] El sistema no registra alumnos guardados. Primero use la opcion [1].\n";
                } else {
                    cout << "====================================================\n";
                    cout << "        REQUERIMIENTO 4: LISTADO DE ESTUDIANTES     \n";
                    cout << "====================================================\n";
                    
                    int totalAprobados = 0;
                    int totalReprobados = 0;

                    // Bucle para recorrer el vector e imprimir las fichas académicas
                    for (size_t i = 0; i < listaEstudiantes.size(); i++) {
                        listaEstudiantes[i].mostrarInformacion(); 

                        // Clasificación de estados para las métricas finales
                        if (listaEstudiantes[i].determinarAprobacion()) {
                            totalAprobados++;
                        } else {
                            totalReprobados++;
                        }
                    }

                    // REQUERIMIENTO 5 Y 6: Presentación resumida de contadores estadísticos
                    cout << "\n====================================================\n";
                    cout << "               RESUMEN ESTADISTICO                  \n";
                    cout << "====================================================\n";
                    cout << " Total de estudiantes en el listado: " << listaEstudiantes.size() << "\n";
                    cout << " REQUERIMIENTO 5: Alumnos Aprobados: " << totalAprobados << "\n";
                    cout << " REQUERIMIENTO 6: Alumnos Reprobados: " << totalReprobados << "\n";
                    cout << "====================================================\n";
                }
                break;
            }
            case 3:
                cout << "-> Cerrando sesion. El sistema de calificaciones se ha cerrado correctamente.\n";
                break;
                
            default:
                cout << "-> [ERROR] Opcion fuera de rango. Por favor elija [1, 2 o 3].\n";
                break;
        }

    } while (opcion != 3);

    return 0;
}