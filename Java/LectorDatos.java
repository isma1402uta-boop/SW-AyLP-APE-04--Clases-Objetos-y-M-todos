import java.util.Scanner;

public class LectorDatos {
    private Scanner teclado;

    public LectorDatos() {
        this.teclado = new Scanner(System.in);
    }

    public int validarEntero(String mensaje) {
        int valor;
        while (true) {
            System.out.print(mensaje);
            try {
                valor = Integer.parseInt(teclado.nextLine().trim());
                return valor;
            } catch (NumberFormatException e) {
                System.out.println("-> [ERROR] Ingreso invalido. Debe ser un numero entero.");
            }
        }
    }

    public float validarNota(String mensaje) {
        float nota;
        while (true) {
            System.out.print(mensaje);
            try {
                nota = Float.parseFloat(teclado.nextLine().trim());
                if (nota >= 0.0f && nota <= 10.0f) {
                    return nota;
                }
                System.out.println("-> [ERROR] La nota debe estar estrictamente en el rango de 0.00 a 10.00.");
            } catch (NumberFormatException e) {
                System.out.println("-> [ERROR] Ingreso invalido. Debe ser un numero decimal o entero.");
            }
        }
    }
}