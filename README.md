# 📑 Sistema Académico de Calificaciones (APE 04)

Este sistema modular ha sido desarrollado para automatizar y asegurar el registro de estudiantes, la gestión de calificaciones por parciales y la generación de métricas analíticas de rendimiento académico.

El proyecto cuenta con dos implementaciones nativas independientes completas: una desarrollada bajo estándares modernos de **C++ (11/17)** y otra migrada con arquitectura robusta en **Java**. Ambos sistemas comparten la misma lógica rigurosa de control de datos y persistencia física.

---

## 🚀 Características Clave

- **Validación de Identidad Real (Ecuador):** Filtra y descarta identificaciones falsas mediante el algoritmo matemático de Coeficientes Módulo 10 del Registro Civil.
- **Control de Tipado y Rangos (Blindaje de Consola):** El sistema es inmune a desbordamientos o bloqueos si el usuario ingresa texto por error en campos numéricos de notas o menús. Las notas se restringen estrictamente al rango dinámico `[0.00 - 10.00]`.
- **Persistencia Física Activa (CSV):** Los registros no se pierden al cerrar la aplicación. El sistema escribe de forma contigua e inmediata cada registro en un archivo `registro_notas.csv` compatible con **Microsoft Excel**.
- **Gestión Eficiente de Memoria RAM:** Uso de reservas de memoria estricta (`reserve` en C++ y `ensureCapacity` en Java) para mitigar realocaciones costosas en inserciones masivas de datos.
- **Flexibilidad de Entrada:** Permite ingresar estudiantes en tandas personalizadas de cualquier tamaño, bloqueando el reporte analítico global hasta alcanzar la cuota mínima institucional.

---

## 📐 Estructura Modular del Proyecto

La arquitectura del software divide estrictamente la interfaz, la lógica de negocio y las capas de validación:

### 🧩 Componentes del Core

1. **Entidad Alumno (`Estudiantes` / `Estudiante`):** Modelo que define los datos del estudiante y procesa de forma encapsulada el cálculo interno del promedio y su estado de aprobación.
2. **Validador de Identidad (`validadorEstudiante` / `ValidadorEstudiante`):** Capa de seguridad encargada del procesamiento de textos alfabéticos puros y la autenticidad matemática de la cédula.
3. **Lector Estadístico (`validarNotas` / `LectorDatos`):** Capa encargada de interceptar excepciones de consola, procesar floats/ints y restringir los límites numéricos.
4. **Orquestador Central (`main.cpp` / `Main.java`):** Controla el bucle de la aplicación, despliega el menú interactivo y computa las métricas de aprobación en tiempo real.

---

## 🛠️ Instrucciones de Ejecución

### 🔹 Opción A: Ejecución en C++

Asegúrate de tener un compilador compatible como `g++` instalado en tu sistema.

1. **Compilar el paquete completo de módulos:**
   ```bash
   g++ main.cpp Estudiantes.cpp validadorEstudiante.cpp validarNotas.cpp -o sistema.exe
   ```
