# 📁 Módulo de Gestión Académica en Java

Este subdirectorio contiene el código fuente de la solución migrada e implementada en **Java (JDK 8 o superior)**. La aplicación adopta el paradigma de **Programación Orientada a Objetos (POO)** estricta, distribuyendo las responsabilidades del sistema en clases especializadas e independientes para garantizar la modularidad, reusabilidad y limpieza del código.

---

## 🧬 Arquitectura de Clases del Proyecto

El sistema está compuesto por los siguientes archivos de código fuente (`.java`), donde cada clase cumple un rol único dentro de la arquitectura:

```text
├── Main.java                # Clase principal: contiene el punto de entrada, el menú interactivo y las métricas globales.
├── Estudiante.java          # Modelo de entidad: encapsula datos del alumno, calcula el promedio y el estado de aprobación.
├── ValidadorEstudiante.java # Capa de seguridad: valida textos alfabéticos y procesa el Algoritmo Módulo 10 del Registro Civil.
└── LectorDatos.java         # Interceptador de consola: blinda la lectura de datos numéricos (enteros/floats) contra excepciones.
```

### 🧠 Conceptos y Buenas Prácticas de Java Implementados

1. **Estructura Try-With-Resources:** La persistencia de datos en el archivo `registro_notas.csv` utiliza flujos `FileWriter` y `PrintWriter` envueltos en un bloque `try (...)`. Esto garantiza que la Máquina Virtual de Java (JVM) cierre el archivo automáticamente al terminar de escribir, previniendo fugas de memoria (*resource leaks*).
2. **Encapsulamiento Estricto:** Todos los atributos de la entidad `Estudiante` y los flujos internos de lectura son privados (`private`), permitiendo el acceso controlado únicamente mediante métodos públicos (*getters* y constructores).
3. **Colecciones Dinámicas Avanzadas (`ArrayList`):** Reemplaza a los arreglos estáticos del lenguaje. Se utiliza el método `.ensureCapacity()` para preasignar memoria contigua en inserciones masivas de alumnos, reduciendo el impacto de procesamiento.
4. **Bucle For-Each de Alto Rendimiento:** La generación de reportes y conteo de aprobados recorre la colección de estudiantes de forma secuencial optimizada mediante la sintaxis mejorada `for (Estudiante est : listaEstudiantes)`.

---

## 🛠️ Instrucciones de Compilación y Ejecución

Para correr el programa, debes compilar el conjunto de clases interconectadas utilizando la terminal integrada de tu IDE (ej. Visual Studio Code) con los siguientes pasos:

### 📌 Paso 1: Ubicación en la terminal
Asegúrate de que tu terminal esté apuntando a la carpeta que contiene los archivos `.java`. Puedes verificarlo listando los elementos:
* **En Windows:** Ejecuta el comando `dir`
* **En macOS/Linux:** Ejecuta el comando `ls`

### 📌 Paso 2: Compilación de Clases
Compila todos los archivos fuente del directorio de forma simultánea ejecutando:

```bash
javac *.java
```
* **Explicación:** El comodín `*` le indica al compilador de Java (`javac`) que procese y verifique la sintaxis de todas las clases al mismo tiempo, generando los archivos binarios ejecutables correspondientes (`.class`).

### 📌 Paso 3: Ejecución del Programa
Una vez compilado sin errores, inicia la aplicación llamando a la clase orquestadora principal (sin la extensión `.class`):

```bash
java Main
```

---

## 🧹 Limpieza del Proyecto (Opcional)
Si necesitas limpiar la carpeta para realizar una entrega pura del código fuente sin archivos binarios compilados por la máquina virtual, ejecuta:

* **En Windows:** `del *.class`
* **En macOS/Linux:** `rm *.class`

---

## 📝 Especificación del Reporte CSV Generado
Al registrar estudiantes, el programa interactúa de forma directa con el disco duro y escribe una línea en formato de texto plano anexada al archivo `registro_notas.csv`:

```text
Cédula,Apellidos Nombres,Nota1,Nota2,Nota3,Promedio,Estado
```

---
⚠️ **Nota de Compatibilidad:** Código fuente desarrollado bajo estándares de la API nativa de Java (`java.util` y `java.io`), garantizando portabilidad absoluta multiplataforma en entornos Windows, Linux y macOS.