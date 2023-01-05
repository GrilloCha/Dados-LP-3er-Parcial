Algoritmo Casino
	Definir dado1, dado2, total, apuestas, i Como Entero
	Escribir "Dame el numero de pauestas que quieres hacer"
	Leer apuestas
	Para x = 1 Hasta apuestas Con Paso  1 Hacer 
		dado1 <- aleatorio(1, 6)
		dado2 <- aleatorio(1, 6)
		total <- dado1 + dado2
		Si total = 2 o total = 3 o total = 12 Entonces
			Escribir "¡Ganaste! Obtuviste ", total, " en los dados."
		Sino
			Si total = 11 Entonces
				Escribir "¡Ganaste! Obtuviste ", total, " en los dados."
			Sino
				Si total = 7 Entonces
					Escribir "¡Ganaste! Obtuviste ", total, " en los dados."
				Sino
					Escribir "Perdiste. Obtuviste ", total, " en los dados."
				FinSi
			FinSi
		FinSi
		Esperar Tecla
	FinPara

FinAlgoritmo


