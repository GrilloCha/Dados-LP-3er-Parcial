#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

// Variables globales
int i,j, rango, apuesta;
int prueba;
int dado1, dado2;
int cero;
int suma;
int aciertos = 0;
int fallos = 0;


// Funciï¿½n
void portada();
void menu();
void adivinanza();
void combinaciones();
int generador();
void gotoxy(int, int);
void centrar(const char *texto, int y);
void centrar1(const char *texto, int y);
void verificarapuesta();
void imprimirresultados();

int main(int argc, char *argv[]) {
	char op;
	portada(); // Modulo portada
	do {
		menu(); // Mï¿½dulo Menï¿½
		op = getche();
		switch (op) { 
			case '1':
				adivinanza(); // Mï¿½dulo adivinanza
			break;	
			case '2':
				combinaciones(); // Mï¿½dulo combinaciones
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
	aciertos = 0;
	fallos = 0;
	centrar("ADIVINANZA\n\n", 1);
	centrar1("(cero para terminar)", 6);
	centrar1("Su apuesta: ", 5);
	centrar1("Respuesta", 8); centrar("Acierta/Falla", 8);
	printf("\n\nAciertos:                 Fallas: ");
	centrar1("Numero de apuestas: ", 3); scanf("%d", &rango);	
	for(i = 1 ; i < rango + 1; i++){
		system("cls\n");
		centrar("ADIVINANZA\n\n", 1);
		centrar1("Numero de apuestas: ", 3); printf("%d", rango);
		centrar1("(cero para terminar)", 6);
		centrar1("Su apuesta", 5); printf(" %d: ", i); scanf("%d", &apuesta);
		if(apuesta == 0){printf("\n\n"); return 0;}
		prueba = generador();
		printf("\n");
		centrar1("Respuesta:", 9); printf(" %3d", prueba);
		if(prueba == apuesta){
			centrar("---- Acierta ----", 9);
			aciertos = aciertos + 1;
		}else
		{
			centrar("---- Falla ----", 9);
			fallos = fallos + 1;
		}
		printf("\n\nAciertos: %4d          Fallas: %4d\n\n", aciertos, fallos);
		system("Pause");
		system("cls");		
	}
}

void combinaciones(){
	aciertos = 0;
	fallos = 0;
	system("cls");
	centrar("COMBINACIONES\n\n", 1);
	printf("Numero de apuestas: ", 4); scanf("%d", &rango);
	for(i = 0; i < rango; i++){
		system("cls");
		centrar("COMBINACIONES\n\n", 1);
		printf("Numero de apuestas: %d\n", rango);
		prueba = generador();
		printf("\nResultado %d: %d", i + 1, prueba);
		if(prueba == 2 || prueba == 3 || prueba == 7 || prueba == 11 || prueba == 12){
			printf("\nCombinación ganadora <3");
			aciertos = aciertos + 1;
		}else{
			printf("\nNo le atinaste >=(");
			fallos = fallos + 1;
		}
		printf("\nGanados: %3d Perdidos: %3d \n\n", aciertos, fallos); 
		printf("\n\n\n");
		centrar1("0: Regresar, 1: Continuar\n",9);
		scanf("%d", &cero);
		if(cero == 0) return 0;
	}
}

int generador(){
	int suma, dado1, dado2;
	
	srand(time(NULL));
	
	dado1 = rand() % 6 + 1;
	
	dado2 = rand() % 6 + 1;
	
	suma = dado1 + dado2;
	
	return suma;
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
	gotoxy(10-(size_texto/2), y);  
	printf("%s",texto); 
}

