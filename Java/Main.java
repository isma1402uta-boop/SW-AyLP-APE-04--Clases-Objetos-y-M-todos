import java.util.ArrayList;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;

public class Main {
    private static final int MIN_ESTUDIANTES = 5;

    public static void main(String[] args) {
        LectorDatos lector = new LectorDatos();
        ValidadorEstudiante validadorEst = new ValidadorEstudiante();
        
        // ArrayList reemplaza a std::vector de C++
        ArrayList<Estudiante> listaEstudiantes = new ArrayList<>();

        int opcion;
        do {
            System.out.println("\n====================================================");
            System.out.println("   SISTEMA ACADEMICO DE CALIFICACIONES (JAVA - APE) ");
            System.out.println("====================================================");
            System.out.println("1. Registrar Estudiantes (Minimo global: " + MIN_ESTUDIANTES + ")");
            System.out.println("2. Mostrar Listado Completo y Estadisticas de Notas");
            System.out.println("3. Salir del Sistema");
            System.out.println("----------------------------------------------------");
            
            opcion = lector.validarEntero("Seleccione una opcion: ");
            System.out.println();

            switch (opcion) {
                case 1:
                    System.out.println("=== REGISTRO DE NUEVOS ESTUDIANTES ===");
                    System.out.println("Estudiantes registrados actualmente: " + listaEstudiantes.size());
                    int cantidad = lector.validarEntero("Cual es la cantidad de estudiantes a registrar ahora?: ");
                    
                    // En Java, el ArrayList gestiona su memoria de forma dinámica excelente por sí solo,
                    // pero podemos usar ensureCapacity para lograr la misma alta eficiencia que 'reserve' en C++
                    listaEstudiantes.ensureCapacity(listaEstudiantes.size() + cantidad);

                    for (int i = 0; i < cantidad; i++) {
                        System.out.println("\n--- REGISTRANDO ESTUDIANTE #" + (i + 1) + " DE " + cantidad + " ---");
                        
                        String cedula = validadorEst.validarCedula("Ingrese el numero de cedula: ", lector);
                        String nombre = validadorEst.validarTexto("Ingrese los nombres: ");
                        String apellido = validadorEst.validarTexto("Ingrese los apellidos: ");
                        
                        float n1 = lector.validarNota("Ingrese la Nota del Parcial 1 (0.00 - 10.00): ");
                        float n2 = lector.validarNota("Ingrese la Nota del Parcial 2 (0.00 - 10.00): ");
                        float n3 = lector.validarNota("Ingrese la Nota del Parcial 3 (0.00 - 10.00): ");

                        Estudiante nuevoAlumno = new Estudiante(cedula, nombre, apellido, n1, n2, n3);
                        listaEstudiantes.add(nuevoAlumno); // .add() reemplaza a .push_back()
                        System.out.println("-> [EXITO] Estudiante almacenado correctamente.");
                    
                        try (FileWriter fw = new FileWriter("registro_notas.csv", true);
                             PrintWriter escritor = new PrintWriter(fw)) {
                            
                            // Escribimos los datos en formato CSV (separados por comas)
                            escritor.println(cedula + "," 
                                           + apellido + " " + nombre + "," 
                                           + n1 + "," + n2 + "," + n3 + "," 
                                           + nuevoAlumno.getPromedio() + "," 
                                           + (nuevoAlumno.determinarAprobacion() ? "APROBADO" : "REPROBADO"));
                            
                            System.out.println("-> [EXITO] Respaldo guardado fisicamente en 'registro_notas.csv'.");
                            
                        } catch (IOException e) {
                            // Si ocurre un error de hardware (disco lleno, sin permisos, etc.) Java lo captura aquí
                            System.out.println("-> [ERROR CRITICO] No se pudo acceder al disco duro: " + e.getMessage());
                        }
                    }
                    break;

                case 2:
                    // Se mantiene el mismo "escudo" flexible que diseñamos para tus parciales
                    if (listaEstudiantes.size() < MIN_ESTUDIANTES) {
                        System.out.println("-> [ERROR] No se puede mostrar el reporte. El sistema exige un minimo global de " + MIN_ESTUDIANTES + " estudiantes.");
                        System.out.println("   Actualmente solo hay " + listaEstudiantes.size() + " estudiantes registrados.");
                    } else {
                        System.out.println("====================================================");
                        System.out.println("        REQUERIMIENTO 4: LISTADO DE ESTUDIANTES     ");
                        System.out.println("====================================================");
                        
                        int totalAprobados = 0;
                        int totalReprobados = 0;

                        // Bucle optimizado para colecciones en Java (For-each)
                        for (Estudiante est : listaEstudiantes) {
                            est.mostrarInformacion();
                            if (est.determinarAprobacion()) {
                                totalAprobados++;
                            } else {
                                totalReprobados++;
                            }
                        }

                        System.out.println("\n====================================================");
                        System.out.println("               RESUMEN ESTADISTICO                  ");
                        System.out.println("====================================================");
                        System.out.println(" Total de estudiantes en el listado: " + listaEstudiantes.size());
                        System.out.println(" Alumnos Aprobados: " + totalAprobados);
                        System.out.println(" Alumnos Reprobados: " + totalReprobados);
                        System.out.println("====================================================");
                    }
                    break;

                case 3:
                    System.out.println("-> Cerrando sesion. El sistema de calificaciones se ha cerrado correctamente.");
                    break;

                default:
                    System.out.println("-> [ERROR] Opcion fuera de rango. Por favor elija [1, 2 o 3].");
                    break;
            }
        } while (opcion != 3);
    }
}