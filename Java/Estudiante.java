public class Estudiante {
    // Atributos privados
    private String cedula;
    private String nombre;
    private String apellido;
    private float nota1;
    private float nota2;
    private float nota3;
    private float promedio;

    // Constructor por defecto
    public Estudiante() {
        this.cedula = "";
        this.nombre = "";
        this.apellido = "";
        this.nota1 = 0.0f;
        this.nota2 = 0.0f;
        this.nota3 = 0.0f;
        this.promedio = 0.0f;
    }

    // Constructor parametrizado
    public Estudiante(String cedula, String nombre, String apellido, float n1, float n2, float n3) {
        this.cedula = cedula;
        this.nombre = nombre;
        this.apellido = apellido;
        this.nota1 = n1;
        this.nota2 = n2;
        this.nota3 = n3;
        calcularPromedio();
    }

    // Métodos lógicos matemáticos
    private void calcularPromedio() {
        this.promedio = (this.nota1 + this.nota2 + this.nota3) / 3.0f;
    }

    public boolean determinarAprobacion() {
        return this.promedio >= 7.0f;
    }

    // Impresión formateada (Reemplaza a <iomanip>)
    public void mostrarInformacion() {
        System.out.println("---------------------------------------------");
        System.out.println("Cedula:   " + cedula);
        System.out.println("Alumno:   " + apellido + " " + nombre);
        System.out.printf("Nota 1:   %.2f  |  Nota 2: %.2f  |  Nota 3: %.2f\n", nota1, nota2, nota3);
        System.out.printf("Promedio: %.2f\n", promedio);
        System.out.println("Estado:   " + (determinarAprobacion() ? "[APROBADO]" : "[REPROBADO]"));
        System.out.println("---------------------------------------------");
    }

    // Getters y Setters
    public String getCedula() { return cedula; }
    public void setCedula(String cedula) { this.cedula = cedula; }

    public String getNombre() { return nombre; }
    public void setNombre(String nombre) { this.nombre = nombre; }

    public String getApellido() { return apellido; }
    public void setApellido(String apellido) { this.apellido = apellido; }

    public float getNota1() { return nota1; }
    public void setNota1(float nota1) { this.nota1 = nota1; calcularPromedio(); }

    public float getNota2() { return nota2; }
    public void setNota2(float nota2) { this.nota2 = nota2; calcularPromedio(); }

    public float getNota3() { return nota3; }
    public void setNota3(float nota3) { this.nota3 = nota3; calcularPromedio(); }

    public float getPromedio() { return promedio; }
}