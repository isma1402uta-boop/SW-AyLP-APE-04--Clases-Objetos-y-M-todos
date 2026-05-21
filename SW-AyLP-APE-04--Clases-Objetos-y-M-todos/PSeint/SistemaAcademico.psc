Proceso SistemaAcademico
	// Definición de variables primitivas
	Definir opcion, cantidad, i, total_estudiantes, aprobados, reprobados, MIN_ESTUDIANTES Como Entero;
	Definir nota1, nota2, nota3 Como Real;
	// Inicialización de reglas de negocio
	MIN_ESTUDIANTES <- 5;
	total_estudiantes <- 0;
	// Definición de Arreglos Paralelos para simular la memoria dinámica
	Dimensionar cedulas(100);
	Dimensionar nombres(100);
	Dimensionar promedios(100);
	Dimensionar estados(100);
	Definir cedulas, nombres, estados Como Cadena;
	Definir promedios Como Real;
	// Bucle Principal del Sistema
	Repetir
		Escribir '========== MENÚ PRINCIPAL ==========';
		Escribir '1. Registrar Estudiantes';
		Escribir '2. Mostrar Reporte y Estadísticas';
		Escribir '3. Salir';
		Escribir 'Seleccione una opción:';
		Leer opcion;
		Segun opcion Hacer
			1:
				Escribir '¿Cuántos estudiantes desea registrar en esta tanda?';
				Leer cantidad;
				Para i<-1 Hasta cantidad Con Paso 1 Hacer
					Escribir '--- Datos del Estudiante ---';
					Escribir 'Ingrese Cédula:';
					Leer cedulas[total_estudiantes+1];
					Escribir 'Ingrese Nombres y Apellidos:';
					Leer nombres[total_estudiantes+1];
					Escribir 'Ingrese Nota Parcial 1:';
					Leer nota1;
					Escribir 'Ingrese Nota Parcial 2:';
					Leer nota2;
					Escribir 'Ingrese Nota Parcial 3:';
					Leer nota3;
					// Cálculo Lógico
					promedios[total_estudiantes+1]<-(nota1+nota2+nota3)/3;
					// Evaluación de Estado
					Si promedios[total_estudiantes+1]>=7.0 Entonces
						estados[total_estudiantes+1]<-'APROBADO';
					SiNo
						estados[total_estudiantes+1]<-'REPROBADO';
					FinSi
					total_estudiantes <- total_estudiantes+1;
					Escribir '=> Estudiante registrado y guardado exitosamente.';
					Escribir '';
				FinPara
			2:
				// Validación de Regla de Negocio
				Si total_estudiantes<MIN_ESTUDIANTES Entonces
					Escribir 'ERROR: Faltan estudiantes. Mínimo requerido: ', MIN_ESTUDIANTES;
					Escribir 'Actualmente registrados: ', total_estudiantes;
					Escribir '';
				SiNo
					aprobados <- 0;
					reprobados <- 0;
					Escribir '========== REPORTE ACADÉMICO ==========';
					Para i<-1 Hasta total_estudiantes Con Paso 1 Hacer
						Escribir 'ID: ', cedulas[i], ' | Nombre: ', nombres[i], ' | Promedio: ', promedios[i], ' | Estado: ', estados[i];
						// Sumatoria Estadística
						Si estados[i]='APROBADO' Entonces
							aprobados <- aprobados+1;
						SiNo
							reprobados <- reprobados+1;
						FinSi
					FinPara
					Escribir '========== ESTADÍSTICAS ==========';
					Escribir 'Total Registrados: ', total_estudiantes;
					Escribir 'Total Aprobados: ', aprobados;
					Escribir 'Total Reprobados: ', reprobados;
					Escribir '';
				FinSi
			3:
				Escribir 'Guardando datos... Saliendo del sistema. ¡Hasta pronto!';
			De Otro Modo:
				Escribir 'ERROR: Opción inválida. Ingrese un número del 1 al 3.';
				Escribir '';
		FinSegun
	Hasta Que opcion=3
FinProceso
