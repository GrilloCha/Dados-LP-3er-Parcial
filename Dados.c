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
int v = 0;
int vector[100];
int mediana;
int moda;
int menor;
int mayor;
int diferencia;
float varianza;
float desviacion;
float media;

// Funcion
int generador();
void estadistica();
void burbuja();
void portada();
void menu();
void adivinanza();
void combinaciones();
void gotoxy(int, int);
void centrar(const char *texto, int y);
void centrar1(const char *texto, int y);
void alinear_d(const char *texto, int y);
void verificarapuesta();
void imprimirresultados();
void me();
void medin();
void dif();
void var();
void de();

int main(int argc, char *argv[]) {
	char op;
	portada(); // Modulo portada
	do {
		menu(); // Modulo Menu
		op = getche();
		switch (op) { 
			case '1':
				adivinanza(); // Modulo adivinanza
			break;	
			case '2':
				combinaciones(); // Modulo combinaciones
			break;
			case '3':
				estadistica(); // Modulo estadistica
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
	centrar("UPIICSA\n",2);
	centrar("1CM12    Equipo: 2 \n",4);
	centrar("LOGICA DE PROGRAMACION\n",6);
	centrar("AUTORES:\n",8);
	centrar("Carbajal Mendoza Eduardo\n",10);
	centrar("Leon Jardines Alexis\n\n",12);
	centrar("Reyes Farias Pamela Denise\n",14);
	centrar("Torres Tellez Carlos Arturo\n",16);
	gotoxy(43, 18);	system("Pause");
}

// Menu
void menu(){
	system("cls");
	centrar("JUEGO DE DADOS", 1);
	centrar("CAPTURA DE DATOS", 3);
	gotoxy(52,5);printf("1) Adivinanza");
	gotoxy(52,7);printf("2) Combinaciones");
	gotoxy(52,9);printf("3) Estadistica");
	centrar("Elija su opcion: ", 12);
}

//Modulo adivinanza
void adivinanza(){
	system("cls");
	int apuesta = 0;
	aciertos = 0;
	fallos = 0;
	centrar("ADIVINANZA\n\n", 1);
	alinear_d("(cero para terminar)", 6);
	alinear_d("Su apuesta: ", 5);
	alinear_d("Respuesta", 8); centrar("Acierta/Falla", 8);
	printf("\n\n Aciertos:                 Fallas: ");
	alinear_d("Numero de apuestas: ", 3); scanf("%d", &rango);	
	for(i = 1 ; i < rango + 1; i++){
		system("cls\n");
		centrar("ADIVINANZA\n\n", 1);
		alinear_d("Numero de apuestas: ", 3); printf("%d", rango);
		alinear_d("(cero para terminar)", 6);
		alinear_d("Su apuesta", 5); printf(" %d: ", i);
		scanf("%d", &apuesta);
		if(apuesta == 0){printf("\n\n"); return;}
		prueba = generador();
		printf("\n");
		alinear_d("Respuesta:", 9); printf(" %3d", prueba);
		if(prueba == apuesta){
			centrar("---- Acierta ----", 9); aciertos = aciertos + 1;
		}else
		{
			centrar("---- Falla ----", 9); fallos = fallos + 1;
		}
		alinear_d("", 10); 
		printf("Aciertos: %4d Fallas: %4d\n\n", aciertos, fallos);
		system("Pause");
		system("cls");		
	}
}

void combinaciones(){
	aciertos = 0;
	fallos = 0;
	system("cls");
	centrar("COMBINACIONES", 1);
	alinear_d("", 3); printf("Numero de apuestas: "); scanf("%d", &rango);
	for(i = 0; i < rango; i++){
		system("cls");
		centrar("COMBINACIONES\n\n", 1);
		alinear_d("", 3); printf("Numero de apuestas: %d\n", rango);
		prueba = generador();
		alinear_d("Resultado", 5); printf(" %d: %d", i + 1, prueba);
		if(prueba == 2 || prueba == 3 || prueba == 7 || prueba == 11 || prueba == 12){
			centrar("Gana tiro", 5);
			aciertos = aciertos + 1;
		}else{
			centrar("Pierde tiro", 5);
			fallos = fallos + 1;
		}
		alinear_d("", 7); printf("Ganados: %3d Perdidos: %3d", aciertos, fallos); 
		alinear_d("Ingresa 0 para regresar al menu, cualquier otro numero para continuar: ", 9); scanf("%d", &cero);
		if(cero == 0){ alinear_d("", 11); return;} ;
	}
}

//Generador de dados
int generador(){
	int suma, dado1, dado2;
	srand(time(NULL));
	dado1 = rand() % 6 + 1;
	dado2 = rand() % 6 + 1;
	suma = dado1 + dado2;
	vector[v] = suma;
	v = v + 1;
	return suma;
}


//Estadistica 
void burbuja(){
	int aux = 0;
	int menor;
	int mayor;
	int cont1 = 0, cont2 = 0;
		for(i = 0 ; i < rango ; i++){
			for(j = 0 ; j < rango - 1 ; j++) {
				if(vector[j] > vector[j+1]){
			    		aux = vector[j+1];
			    		vector[j+1] = vector[j];
			    		vector [j] = aux; 
					}
			}
	}
	menor = vector[1];
	mayor = vector[v]; 
	for(i = 0 ; i < v ; i++) {
		if(i % 10 == 0 && i != 0) printf("\n");
		printf("%4d ", vector[i]);	
		me();
		medin();
		dif();
	}
	var();
	de();
	printf("\n");
	}


void estadistica(){	
	system("cls\n");
	burbuja();
	centrar("PARAMETROS ESTADISTICOS", 13);
	centrar("TABLA DE VALORES DE LA COLECCION", 14);
	alinear_d("Medidas de Tendencia Central: ", 16);
	alinear_d("Media =", 17); printf(" %.2f\n", media);
	alinear_d("Mediana =", 18); printf(" %d\n", mediana);
	alinear_d("Medidas de Dispersion: ", 20);
	alinear_d("Rango = ", 21); printf( "%d", diferencia);
	alinear_d("Varianza = ", 22); printf("%f", varianza);
	alinear_d("Desviacion Estandar = ", 23); printf("%f", desviacion);
	alinear_d("", 25); system("Pause");
	exit(-1);
}

//FUNCIONES PARA OPERACIONES
void me(){
		suma = suma + vector[i];	
		media = suma / v;
}

void medin(){
	int tamanioelemento = sizeof vector[i];
	int longitud = rango;
	int mitad = longitud / 2;
	// Después vemos si la longitud es par
	if (longitud % 2 == 0) {
	    // Debemos promediar los valores del centro
	    mediana = (vector[mitad - 1] + vector[mitad]) / 2;
	} else {
	    mediana = vector[mitad];
	}
}

void dif(){
    mayor = mayor < vector[i] ? vector[i] : mayor;
    //menor = menor > vector[i] ? vector[i] : menor;
	if (i == 0){
		menor = vector[i];
	} 
	else{
		if (vector[i] < menor) {
			menor = vector[i];
		}
	}
	diferencia = mayor - menor;
}

void var(){
	for(i=0; i< v; i++){
	varianza = varianza + pow(vector[i] - media, 2);
	}	
	varianza = varianza / rango;
}

void de(){
	desviacion = sqrt(varianza);
}

// UTILERIA
//Funciones para alinear el texto
void gotoxy(int x,int y){ 
      HANDLE hcon; ; 
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos); ;
}

void centrar(const char *texto, int y){
	int size_texto;
	size_texto = strlen(texto); 
	gotoxy(60-(size_texto/2), y);  
	printf("%s",texto); 
}

void centrar1(const char *texto, int y){
	int size_texto;
	size_texto = strlen(texto); 
	gotoxy(60, y);  
	printf("%s",texto); 
}

void alinear_d(const char *texto, int y){
	int size_texto;
	gotoxy(1, y);  
	printf("%s",texto); 
}

