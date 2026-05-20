import java.util.Scanner;

public class ValidadorEstudiante {
    // Atributo privado único para el manejo de la consola (Evita fugas de memoria)
    private final Scanner sc;

    // Constructor que inicializa el lector de forma segura
    public ValidadorEstudiante() {
        this.sc = new Scanner(System.in);
    }

    // Algoritmo de validación del Registro Civil (Módulo 10)
    private boolean esCedulaRealEcuatoriana(String cedula) {
        // 1. Código de provincia (01 a 24, o 30 para ecuatorianos en el exterior)
        int provincia = Integer.parseInt(cedula.substring(0, 2));
        if ((provincia < 1 || provincia > 24) && provincia != 30) {
            return false;
        }

        // 2. Tercer dígito menor a 6 (Cédulas de personas naturales)
        int tercerDigito = Character.getNumericValue(cedula.charAt(2));
        if (tercerDigito >= 6) {
            return false;
        }

        // 3. Algoritmo de coeficientes módulo 10
        int[] coeficientes = {2, 1, 2, 1, 2, 1, 2, 1, 2};
        int suma = 0;

        for (int i = 0; i < 9; i++) {
            int valor = Character.getNumericValue(cedula.charAt(i)) * coeficientes[i];
            if (valor > 9) {
                valor -= 9;
            }
            suma += valor;
        }

        int digitoVerificadorCalculado = (suma % 10 == 0) ? 0 : 10 - (suma % 10);
        int digitoVerificadorReal = Character.getNumericValue(cedula.charAt(9));

        return digitoVerificadorCalculado == digitoVerificadorReal;
    }

    // CORRECCIÓN: Se removió el parámetro LectorDatos innecesario y se usa el 'sc' global
    public String validarCedula(String mensaje) {
        while (true) {
            System.out.print(mensaje);
            String cedula = sc.nextLine().trim();

            if (cedula.length() != 10) {
                System.out.println("-> [ERROR] La cedula debe tener exactamente 10 digitos.");
            } else if (!cedula.matches("[0-9]+")) {
                System.out.println("-> [ERROR] La cedula solo debe contener caracteres numericos.");
            } else if (!esCedulaRealEcuatoriana(cedula)) {
                System.out.println("-> [ERROR] El numero de cedula no existe o es invalido en Ecuador.");
            } else {
                return cedula;
            }
        }
    }

    public String validarTexto(String mensaje) {
        while (true) {
            System.out.print(mensaje);
            String texto = sc.nextLine();

            if (texto.trim().isEmpty()) {
                System.out.println("-> [ERROR] El campo no puede quedar vacio. Intente de nuevo.");
                continue;
            }

            boolean caracteresValidos = true;
            for (int i = 0; i < texto.length(); i++) {
                char c = texto.charAt(i);
                
                // Reconoce de manera nativa tildes, diéresis y la Ñ
                if (Character.isLetter(c) || Character.isWhitespace(c)) {
                    continue;
                }
                caracteresValidos = false;
                break;
            }

            if (!caracteresValidos) {
                System.out.println("-> [ERROR] El campo solo debe contener letras y espacios (sin numeros ni simbolos).");
            } else {
                return texto.trim(); // Retorna el texto limpio de espacios innecesarios a los lados
            }
        }
    }
}