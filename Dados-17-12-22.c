#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

// Variables globales
int i,j, rango, apuesta;
int dado1, dado2;
int cero;
int suma;
int aciertos = 0;
int fallos = 0;


// Función
void portada();
void menu();
void adivinanza();
void combinaciones();
void generador();
void gotoxy(int, int);
void centrar(const char *texto, int y);
void centrar1(const char *texto, int y);
void verificarapuesta();
void imprimirresultados();

int main(int argc, char *argv[]) {
	char op;
	portada(); // Modulo portada
	do {
		menu(); // Módulo Menú
		op = getche();
		switch (op) { 
			case '1':
				adivinanza(); // Módulo adivinanza
			break;	
			case '2':
				combinaciones(); // Módulo combinaciones
			break;
			case '3':
				exit(-1); // Salida del programa
			break;
		default:
			centrar("Opcion no valida\n", 14);
		}
		system("Pause\n");
		system("cls\n");
	} while (op!=3);
}

// Portada
void portada(){
	system("color F0");
	centrar("INSTITUTO POLITECNICO NACIONAL\n", 0);
	centrar("Unidad Profesional Interdisciplinaria de Ingenierias y Ciencias Sociales y Administrativas\n",2);
	centrar("1CM12    Equipo: 2 \n",4);
	centrar("LOGICA DE PROGRAMACION\n",6);
	centrar("AUTORES:\n",8);
	centrar("Carbajal Mendoza Eduardo\n",10);
	centrar("Leon Jardines Alexis\n\n",12);
	centrar("Reyes Farias Pamela Denise\n",14);
	centrar("Torres Tellez Carlos Arturo\n",16);
	system("Pause");
}
// Menu
void menu(){
	system("cls");
	centrar("JUEGO DE DADOS", 1);
	centrar("CAPTURA DE DATOS", 3);
	centrar("1) Adivinanza", 6);
	centrar("2) Combinaciones", 8);
	centrar("3) Terminar", 10);
	centrar("Elija su opcion: ", 12);
}


void adivinanza(){
	system("cls");
	int apuesta = 0;
	centrar("ADIVINANZA\n\n", 1);
	printf("Numero de apuestas: ", 4); scanf("%d", &rango);
	printf("\n");	
	for(i = 1 ; i < rango + 1; i++){
		system("cls\n");
		centrar("ADIVINANZA\n\n", 1);
		printf("Numero de apuestas: ", 4); printf("%d", rango);
		printf("\n");
		printf("\nSu apuesta (cero para terminar) %d: ",i); scanf("%d", &apuesta);
		if(apuesta == 0) exit(-1);
		printf("\n");
		generador();
		printf("\n");
		verificarapuesta(apuesta, suma);
		printf("\n");
		system("Pause\n");
		system("cls");		
	}
}

void combinaciones(){
	system("cls");
	centrar("COMBINACIONES\n\n", 1);
	printf("Numero de apuestas: \n\n", 4); scanf("%d", &rango);
	printf("Resultado i++: \n\n", 7);
	printf("Combinaciones:		Ganadora 2,3,7,11,12 -- Perdedora 4,5,6,8,9,10\n\n", 10);
	printf("Ganados:  			Perdidos:		\n\n", 13); 
	printf("\n\n\n");
	centrar1("0: Regresar, 1: Continuar\n",15);
	scanf("%d", &cero);
	printf("\n");
}

void generador(){
	int suma, dado1, dado2;
	
	srand(time(NULL));
	
	dado1 = rand() % 6 + 1;
	
	dado2 = rand() % 6 + 1;
	
	suma = dado1 + dado2;
	
	printf("Respuesta: %d\n", suma);
}

void verificarapuesta(int apuesta, int suma){
	if(apuesta == suma){
		aciertos++;
	} printf("Aciertos: %d\n",aciertos);
	if(apuesta != suma){
		fallos++;
		printf("Fallos: %d",fallos);
	}
	//printf("Aciertos: %d		Fallos: %d", aciertos, fallos);
}

// UTILERIA

void gotoxy(int x,int y){ 
      HANDLE hcon; ; 
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos); ;
}

//Funcion para centrar el texto
void centrar(const char *texto, int y){
	int size_texto;
	size_texto = strlen(texto); 
	gotoxy(60-(size_texto/2), y);  
	printf("%s",texto); 
}

void centrar1(const char *texto, int y){
	int size_texto;
	size_texto = strlen(texto); 
	gotoxy(30-(size_texto/2), y);  
	printf("%s",texto); 
}

