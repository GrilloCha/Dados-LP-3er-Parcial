Algoritmo DADOS
	portada()
	Repetir
		menu()
		Leer op
		Segun op  Hacer
			1:
				adivinanza()
			2:	
				combinaciones()
			3: 
			De Otro Modo:
				Escribir 'Opcion no valida'				
				Escribir 'Presiona una tecla para continuar'
				Esperar Tecla
		FinSegun
	Hasta Que op=3	
FinAlgoritmo


Funcion portada()
	Escribir "Instituto Politecnico Nacional"
	Escribir "Unidad Profesional Interdisciplinaria de Ingeniería y Ciencias Sociales y Administrativas IPN"
	Escribir "Logica de Programacion"
	Escribir "Profesor: Oviedo Galdeano Mario"
	Escribir "Equipo: 2", " Grupo: 1CM12"
	Escribir "Autores: "
	Escribir "Carbajal Mendoza Eduardo  "
	Escribir "Leon Jardines Alexis "
	Escribir "Reyes Farias Pamela Denise "
	Escribir "Torres Tellez Carlos Arturo "
	Escribir 'Presiona una tecla para continuar'
	Esperar Tecla
Fin Funcion


Funcion menu()
	Borrar Pantalla
	Escribir 'Juego de dados'
	Escribir 'Captura de dados'
	Escribir '1. Adivinanza'
	Escribir '2. Combinaciones'
	Escribir '3. Terminar'
Fin Funcion


Funcion adivinanza()
	Borrar Pantalla
	Escribir "ADIVINANZA"
	i <- 1
	aciertos <- 0
	errores <- 0
	Escribir 'Numero de apuestas (presione 0 para finalizar) ", i,':'
	Leer repeticiones
	mientras repeticiones > 0 hacer
		Borrar Pantalla
		Escribir 'Numero de apuestas (presione 0 para finalizar) ", i,':'
		Escribir 'Tu apuesta:' 
		Leer numeroUsuario
		si numeroUsuario = 0 Entonces
			repeticiones <- 0
		sino 
			i <- i + 1
			numeroMaquina <- aleatorio(2, 12)
			escribir 'Respuesta: ', numeroMaquina
			si numeroUsuario = numeroMaquina entonces
				aciertos <- aciertos + 1
			sino
				errores <- errores + 1
			finsi
			escribir "Aciertos: ", aciertos , " Errores: ", errores
			repeticiones <- repeticiones - 1
			Escribir 'Presione una tecla para continuar"
			Esperar Tecla
		FinSi
	finmientras
FinFuncion


Funcion combinaciones() 
	ganados <- 0
	perdidos <- 0
	apuestas <- 0
	i <- 0
	prueba <- 0
	aciertos <- 0
	fallos <- 0 
	limpiar pantalla
	escribir "COMBINACIONES"
	escribir "Numero de apuestas:"
	leer apuestas
	para i desde 0 hasta apuestas-1 hacer
		numeroMaquina <- aleatorio(2, 12)
		escribir "Resultado ", i+1, ":", numeroMaquina
		si (numeroMaquina = 2 o numeroMaquina = 3 o numeroMaquina = 7 o numeroMaquina = 11 o numeroMaquina = 12) entonces
			escribir "Combinacion ganadora <3"
			ganados <- ganados + 1
			aciertos <- aciertos + 1
		sino
			escribir "No le atinaste >=("
			perdidos <- perdidos + 1
			fallos <- fallos + 1
		finsi
		escribir "Ganados:", ganados, "Perdidos:", perdidos
		escribir "Ganados:", aciertos, "Perdidos:", fallos
		escribir "0: Regresar, 1: Continuar"
		leer cero
	finpara
FinFuncion