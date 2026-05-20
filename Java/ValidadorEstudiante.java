public class ValidadorEstudiante {

    public ValidadorEstudiante() {}

    private boolean esCedulaRealEcuatoriana(String cedula) {
        // 1. Código de provincia
        int provincia = Integer.parseInt(cedula.substring(0, 2));
        if ((provincia < 1 || provincia > 24) && provincia != 30) {
            return false;
        }

        // 2. Tercer dígito menor a 6
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

    public String validarCedula(String mensaje, LectorDatos lector) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
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
        java.util.Scanner sc = new java.util.Scanner(System.in);
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
                
                // En Java, Character.isLetter reconoce automáticamente tildes y la 'ñ' / 'Ñ'
                if (Character.isLetter(c) || Character.isWhitespace(c)) {
                    continue;
                }
                caracteresValidos = false;
                break;
            }

            if (!caracteresValidos) {
                System.out.println("-> [ERROR] El campo solo debe contener letras y espacios (sin numeros ni simbolos).");
            } else {
                return texto;
            }
        }
    }
}