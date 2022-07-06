//Universidad Santa Maria
//Gabrie Leal
//V-29.797.492
// Proyecto de laboratorio de programación
// Maquina tragamonedas
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define a 03 
#define b 04 
#define c 05 

//Validación
int validar_numero(char numero[]);

main(){
	char numero[5]; //variable que captura como char o string
	int n, numerovalido; //variables de tipo entero
	int i, j, k; // iteradores
	int  apuestaopc, intentos = 0; //variables del juego
	int opc, num, N = 20, numero_maximo = 10, randNumber, index, diaspartidas; //Roll
	char symbols [5] = { '(' , '!', '#', '$', '%' }; //Simbolos
	char linea = ' ';//espacios en el roll
	//Dinero
	float dineroT, dineroEn, dineroD; //time_t tiempoahora
	//Archivo
	FILE *archivomoney;
	archivomoney=fopen("archivoprin.txt","a+"); //Se abre el archivo
	fprintf(archivomoney, "%s\n"); //,ctime(&tiempoahora) 
	
	do{
			printf("===========================================\n");
			printf("\t Maquina tragamonedas!\n");
			printf("===========================================\n");	
			printf("\t	 Bienvenido \n");
			printf("Al tragamonedas del casino de la USM \n");
			printf("===========================================\n");
			
			//menu de inicio
			menu:
			printf("\t Menu \n");
			printf("1. Iniciar juego \n");
			printf("2. Ver como se juega\n");
			printf("3. Ver registro de la maquina\n");
			printf("4. Salir \n");
			printf("Ingrese una opcion del menu: ");
			scanf("%s", numero);	
			n=validar_numero(numero);
			system("cls");
			
			numerovalido=atoi(numero);
				
			if(numerovalido > 4){
				system("cls");
				printf("Opcion fuera de rango, ingrese una opcion valida \n");
				system("pause");
				system("cls");
			}
		
		//Menu del juego
		switch(numerovalido){
			case 1:	printf("SU APUESTA \n");
					printf("Ingrese la cantidad para apostar: \n");
					scanf("%f", &dineroD);
					system("cls");
					/*printf("SU APUESTA \n");
					/*printf("Su saldo es de: %.2f \n\n", dineroD);
					printf("INICIANDO EL GIRO...\n");*/
					
					//Roll
					for (i = 0; i < 3; i++)
					{
						printf("%d", randNumber);
						k = 0; //index = 0;
						for (j = 0; j < randNumber; j++) //numero de giros que hará 
						{
							
							//if (k > 5 );
							//index = 0;
							linea += symbols[k]; //index
							printf(" %c \t  %c \t %c", linea, symbols[k]); //linea
							Sleep(75); //Tiempo para cada roll
							system("cls");
							k++;
						}
		
						linea += symbols[num - 1];
		
						num=rand() % numero_maximo; //el numero segun la posición del simbolo
						randNumber = rand() % N; //el numero de vueltas
					}
					printf("===========================================\n");
					printf("\t	Resultado del giro \n");
					printf(" \t %c	 %c	 %c \n", linea, linea); //linea, lineas
					printf("===========================================\n");
					system("pause");
					system("cls");
					break;
			
			case 2: //Mensaje de como funciona o en que consiste el juego
					printf("\t El juego consiste en que el jugador acciona la palanca para comenzar el juego, \n");
					printf("\t se veran 3 ruedas a traves del vidrio en las cuales habran distintas figuras \n");
					printf("\t estas rudas giraran una cantidad de tiempo y luego se detendran en una de las figuras \n");
					printf("\t si se aciertan 3, ganas mas de lo apostado :) , de lo contrario pierdes tu apuesta :(  \n");
					system("pause");
					system("cls");
					break;
					
			case 3: //ARCHIVO
					fprintf (archivomoney, "El registro de partidas diarias de hoy es de: %d partidas\n", diaspartidas);
					fprintf(archivomoney,"El dinero ingresado hoy es de: %.1f$\n", dineroT);
					fprintf(archivomoney,"El dinero de hoy ingresado por apuesta es de: %.1f$\n", dineroD);
					fprintf(archivomoney,"El dinero entregado a ganadores hoy es de: %.1f$\n", dineroEn);
					fclose(archivomoney); //Se cierra el archivo
					system("pause");
					system("cls");
					break;
					
			case 4: //SALIDA
					printf("Saliendo...");
					system("pause");
					goto end;
			
			default: break;
		}
		
	}while(opc == 1);
	printf("Quiere volver a menu? \n");
	printf("1. Si \n");
	printf("2. No \n");
	scanf("%d", opc);
	if(opc == 1){
		goto menu;
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
			printf("Ingresa un solo numero \n");
			system("pause");
			system("cls");
			return 0;
		}
	}
	return 1;
}
