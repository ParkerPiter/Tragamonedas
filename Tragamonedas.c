//Universidad Santa Maria
//Elaborado por Gabrie Leal
// Proyecto de laboratorio de programación
// Maquina tragamonedas
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int validar_numero(char numero[]);//Validación
int N = 20, win = 0, fail = 0;
float apuesta;
char *symbols [5] = { "(" , "!", "#", "$", "%" }; //Simbolos

main(){
	char numero[5], opc[5]; //variable que captura como char o string
	int n, numerovalido; //variables de tipo entero
	int i, j, k; // iteradores
	int num, randNumber, diaspartidas=0; //Roll
	char *linea[3];//espacios en el roll
	float dineroT = 0, dineroEn = 0, dineroD = 0, aux = 0; //Dinero
	
	//Archivo
	FILE *archivomoney;
	archivomoney=fopen("archivomoney.txt","a+"); //Se abre el archivo
	fprintf(archivomoney, "%s\n"); 
	
	//Inicializacion de numeros aleatorios
	randNumber = random_int();//el numero de vueltas
	num= random_char();//el numero del simbolo en el array
	do{		
		menu:
		linea[0] = "";//espacios
		linea[1] = "";//espacios
		linea[2] = "";//espacios
		printf("===========================================\n");
		printf("\t Maquina tragamonedas!\n");
		printf("===========================================\n");	
		printf("\t	 Bienvenido \n");
		printf("    Al tragamonedas del casino de la USM \n");
		printf("===========================================\n");
			
		//menu de inicio
		printf("\t\t Menu \n");
		printf("\t1. Iniciar juego \n");
		printf("\t2. Ver como se juega\n");
		printf("\t3. Ver registro de la maquina\n");
		printf("\t4. Ver saldo disponible en la maquina\n");
		printf("\t5. Salir \n");
		printf("===========================================\n");
		printf("Ingrese una opcion del menu: ");
		scanf("%s", numero);	
		n=validar_numero(numero);//valida el numero
		system("cls");
			
		numerovalido=atoi(numero);//Llamada al metodo para la validación
				
		if(numerovalido > 5){
			system("cls");
			printf("Opcion fuera de rango, ingrese una opcion valida \n");
			system("pause");
			system("cls");
		}
		
		//Menu del juego
		switch(numerovalido){
			case 1:	intentoA:
					printf("===========================================\n");
					printf("\t\tSU APUESTA \n");
					printf("===========================================\n");
					printf("\tMinimo: 5$, Maximo: 100$ \n");
					printf("===========================================\n");
					printf("Ingrese la cantidad para apostar: ");
					scanf("%f", &dineroD);
					aux = dineroD; //auxiliar 
					if(dineroD < 5 || dineroD > 100){
						system("cls");
						printf("====================================================================\n");
						printf("El monto ingresado para apostar no es valido, vuelvalo a intentar\n");
						printf("====================================================================\n");
						system("pause");
						system("cls");
						goto intentoA;
					}
					printf("$");
					system("cls");
					printf("===========================================\n");
					printf("\t    SU APUESTA ES DE \n");
					printf("\t        %.2f$ \n",dineroD);
					printf("===========================================\n");
					apuesta = dineroD;//Intercambio
					system("pause");
					system("cls");
					diaspartidas ++;
					printf("===========================================\n");
					printf("   PRESIONE ENTER PARA JALAR LA PALANCA\n");
					printf("===========================================\n");
					system("pause");
					system("cls");
					
					//Roll
					for (i = 0; i < 3; i++) //Hace las columnas filas
					{
						for (j = 0; j < randNumber; j++) //numero de giros que hará 
						{
							printf("===========================================\n");
							printf("\tINICIANDO EL GIRO...\n");
							printf("===========================================\n");
							printf("\t%s\t%s\t%s",symbols[random_char()],symbols[random_char()],symbols[random_char()]);//Roll de los simbolos
							Sleep(55); //Tiempo para cada roll
							system("cls");
						}
						linea[i] = symbols[num];
						num= random_char(); //llamada al metodo el numero segun la posición del simbolo
						randNumber = random_int(); //llamada al metodo el numero de vueltas 
					}
					printf("===========================================\n");
					printf("\tResultado del giro \n");
					printf("\t%s\t%s\t%s\n", linea[0], linea[1], linea[2]); //Impresión de los simbolos según el espacio del vector
					printf("===========================================\n");
					matchwin(linea);//llamada al metodo de validación de si coincidieron los simbolos
					system("pause");
					system("cls");
					break;
			
			case 2: //Mensaje de como funciona o en que consiste el juego
					printf("=================================================================================================\n");
					printf("\t\t\t\t\t EN QUE CONSISTE EL JUEGO\n");
					printf("=================================================================================================\n");
					printf("\t El juego consiste en que el jugador acciona la palanca para comenzar el juego, \n");
					printf("\t se veran 3 ruedas a traves del vidrio en las cuales habran distintas figuras \n");
					printf("\t estas ruedas giraran una cantidad de tiempo y luego se detendran en una de las figuras \n");
					printf("\t si se aciertan 3, ganas mas de lo apostado :) , de lo contrario pierdes tu apuesta :(  \n");
					printf("=================================================================================================\n");
					system("pause");
					system("cls");
					break;
					
			case 3: //ARCHIVO
					dineroD = aux + aux;//suma de los auxiliares para devolver a la variable de dinero
					printf("===========================================\n");
					printf("\t REGISTRO DE LA MAQUINA\n");
					printf("===========================================\n");
					printf("\tPartidas jugadas: %d\n \tDinero del dia:%.1f\n \tDinero en la semana:%.1f\n \tDinero Total:%.1f\n \tPartidas Ganadas:%d\n \tPartidas Perdidas:%d\n", diaspartidas, dineroD, dineroEn, dineroT, win, fail);
					printf("===========================================\n");
					fprintf (archivomoney,"El registro de partidas diarias de hoy es de: %d partidas\n", diaspartidas);
					fprintf(archivomoney,"El dinero ingresado hoy es de: %.1f$\n", dineroT);
					fprintf(archivomoney,"El dinero de hoy ingresado por apuesta es de: %.1f$\n", dineroD);
					fprintf(archivomoney,"El dinero entregado a ganadores hoy es de: %.1f$\n", dineroEn);
					fprintf(archivomoney,"Partidas Ganadas:%d\n", win);
					fprintf(archivomoney,"Partidas Perdidas:%d\n", fail);
					fclose(archivomoney); //Se cierra el archivo
					system("pause");
					system("cls");
					break;
					
			case 4: printf("===========================================\n");
					printf("\tSU SALDO ES DE \n");
					printf("\t     %.2f$ \n",apuesta);
					printf("===========================================\n");
					system("pause");
					system("cls");
					break;
							
			case 5: //SALIDA
					salida:
					printf("===========================================\n");
					printf("\tVuelva pronto, saliendo...\n");
					printf("===========================================\n");
					system("pause");
					goto end;
			
			default: break;
		}
		
	}while(opc == 1);
	//Vuelta al menu si el usuario lo desea
	menu2:
	printf("===========================================\n");
	printf("\tQuiere volver a menu? \n");
	printf("\t1. Si \n");
	printf("\t2. No \n");
	printf("===========================================\n");
	printf("\tIngrese una de las opciones: ");
	scanf("%s", opc);
	n=validar_numero(opc);
	system("cls");
	numerovalido=atoi(opc);//Llamada al metodo para la validación
	if(numerovalido > 2 || numerovalido < 1){
		printf("======================================================================================\n");
		printf("Opcion invalida, ingrese una opcion de las mostradas en pantalla, vuelvalo a intentar\n");
		printf("======================================================================================\n");
		system("pause");
		system("cls");
		goto menu2;
	}
	if(numerovalido == 1){
		numerovalido = 0;
		goto menu;
	}
	if(numerovalido == 2){
		goto salida;
	}
	
	end: 
	return 0;	
	
}

//validacion de numeros ingresados
int validar_numero(char numero[]){ 

	int i; //variable local para ciclo for
	for(i=0; i<strlen(numero); i++){
		if(!(isdigit(numero[i]))){ //condicional de si la variable ingresada es diferente de un numero entero como i, enviar mensaje de error
			system("cls");
			printf("===========================================\n");
			printf("\tIngresa un solo numeros \n");
			printf("===========================================\n");
			system("pause");
			system("cls");
			return 0;
		}
	}
	return 1;
}

//Metodo un minimo y un maximo para la cantidad de vueltas
int random_int()
{
	int value = 0;
	int r = 0;
	while(1 == 1){
		srand(time(NULL)); //uso de la libreria Time
		r = rand() % N;
		if( r > 0 && r < N  ){
			value = r;
			break; 
		}
	}
	return value;
}

//Metodo random char en el array
int random_char()
{
	int value = 0;
	int r = 0;
	while(1 == 1){
		srand(time(NULL)); //uso de la libreria Time
		r = rand() % 5 ;
		if( r < 5 ){
			value = r;
			break; 
		}
	}
	return value;
}

//Metodo de busqueda de los simbolos
int busqueda(char **linea){
	int n = 5, match, i, j;
	for(i = 0; i < n;i++){ //hace un conteo con un iterador
		int count = 0;
		char *character = symbols[i]; //puntero
		for(j=0; j < 3;j++){
			if (strcmp(character,linea[j])==0){ //comparación
				count++;
			}			
		}
		if (count > match){
				match = count;	
			}
	}
	return match;
}

//Metodo void para los resultados del match
void matchwin(char **resultado) {
	int matches = busqueda(resultado);

		if (matches == 1 || matches == 2)
		{
			printf("\tIntente de nuevo \n");
			printf("===========================================\n");
			apuesta -= apuesta; //Resta toda la apuesta si pierde
			fail ++;
		}
		
		if (matches == 3)
		{
			printf("\tLo lograste ganaste!! \n");
			printf("===========================================\n");
			apuesta += apuesta; //Suma el doble si ganas
			win ++;
		}
}
