# 📁 Módulo de Gestión Académica en C++ (Archivo Único)

Este subdirectorio contiene el código fuente de la solución implementada en **C++ (Estándar 11 o superior)**. Para facilitar el despliegue rápido y la portabilidad del entregable, toda la arquitectura orientada a objetos se encuentra consolidada en un único archivo estructurado.

---

## 🧬 Organización del Código Unificado

El archivo `sistema_completo.cpp` se encuentra dividido internamente en capas bien definidas para respetar el diseño de software:

1. **Clase `Estudiantes`:** Modelo encapsulado que maneja los atributos del alumno, el cálculo automático de promedios y las reglas de aprobación.
2. **Clase `validarNotas`:** Capa de seguridad que utiliza `std::stringstream` para limpiar el búfer de entrada de la consola y blindar el sistema contra ingresos de texto accidentales.
3. **Clase `validadorEstudiante`:** Aloja el algoritmo del Registro Civil de Ecuador (Módulo 10) y los filtros de expresiones y bucles alfabéticos.
4. **Función `main()`:** Orquestador del menú interactivo de la aplicación y cálculo de totales estadísticos.

---

## 🛠️ Instrucciones de Compilación y Ejecución

Al estar toda la solución integrada dentro de un único componente, el proceso en la terminal es directo y no requiere enlaces complejos de librerías de cabecera.

### 📌 Paso 1: Ubicación en la terminal
Abre la terminal de tu IDE (ej. Visual Studio Code) y asegúrate de estar dentro de la carpeta que contiene el archivo `sistema_completo.cpp`. Puedes verificarlo listando los archivos con `dir` (en Windows) o `ls` (en macOS/Linux).

### 📌 Paso 2: Compilación
Ejecuta el siguiente comando en la terminal para compilar el código fuente:

```bash
g++ sistema_completo.cpp -o sistema.exe
```

*El parámetro `-o sistema.exe` define el nombre del archivo binario ejecutable final.*

### 📌 Paso 3: Ejecución
Una vez que el compilador termine sin lanzar errores, ejecuta el programa con el comando correspondiente a tu entorno:

* **En Windows (CMD / PowerShell):**
  ```bash
  .\sistema.exe
  ```
* **En macOS o Linux:**
  ```bash
  ./sistema.exe
  ```

---

## 📝 Especificación de la Salida Física (CSV)
Cada estudiante registrado se guarda instantáneamente al final del documento de texto plano `registro_notas.csv` en el siguiente orden secuencial:

```text
Cédula,Apellidos Nombres,Nota1,Nota2,Nota3,Promedio,Estado
```

---
⚠️ **Nota de Compatibilidad:** Este código fuente utiliza funciones estándar de la librería nativa de C++, asegurando un rendimiento multiplataforma óptimo en GCC, Clang y MSVC.