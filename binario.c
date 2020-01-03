#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


//CONSTANTES DE COLORES EN PRINTF
#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

//ACENTOS
//á: 160 é: 130 í: 161 ó: 162 ú: 163 Á: 181 É: 144 Í: 214 Ó: 224 Ú: 23 ñ: 164 Ñ: 165

int main(){

	//FUNCIÓN QUE PERMITE TODO TIPO DE CARACTERES EN CONSOLA
	setlocale(LC_ALL, "");
	//DECLARACIÓN DE VARIABLES
	int aux = 0;
	int i = 0;
	int num_bits = 0;
	int num_bits_aux;

	printf("Ingresa el numero de bits que tiene el numero a convertir: ");
	scanf("%d",&num_bits);
	int array[num_bits];
	//LEER BIT'S DEL NÚMERO BINARIO A CONVERTIR
	for(i=0; i < num_bits; i++){
		do{
			printf("Ingresa el bit num %d de izq a der: ", i+1);
			scanf("%d",&array[i]);
			if(array[i]>1 || array[i]<0){
				printf("El numero que ingresaste es incorrecto, s%clo acepta 1´s y 0´s\n",162);
			}
		}while(array[i]>1 || array[i]<0);		
	}
	//VARIABLE AUXILIAR PARA CONTAR DECREMAT EL NUM DE BITS
	num_bits_aux = num_bits;
	
	//IMPRESIÓN DEL NUMERO EN BINARIO
	printf("El numero ingresado en binario es: ");

	for(i=0; i<num_bits; i++){

		printf("%d",array[i]);

	}
	//CONVERSIÓN DEL NÚMERO BINARIO LEIDO

	for(i = 0; i < num_bits; i++){
		if(array[i]==1){
			aux = aux + pow(2,num_bits_aux-1);
			num_bits_aux--;
		}else{
         	aux = aux + 0;
			num_bits_aux--;
 		}
	}

	printf("\n\n");
	printf("El numero que ingresaste en binario a decimal es: %d\n\n", aux);
	return EXIT_SUCCESS;
	getchar();/*
	///////////////////////////////////////
	//CONVERSION DE DECIMAL A BINARIO
	char numero_binario_correcto[]="";
	char numero_final[]="";
	double num_usuario = 0;
	double num_part_entera = 0;
	double num_part_decimal = 0;
	int i = 0;

	//LEEMOS EL NUMERO POR EL USUARIO
	printf("Ingresa el numero que deseas convertir a binario: ");
	scanf("%lf", &num_usuario);
	printf("El numero ingresado fue: %lf\n", num_usuario);
	
	//GUARDAMOS LA PARTE ENTERA Y DECIMAL DEL NUMERO OBTENIDO
	
	num_part_decimal = modf(num_usuario, &num_part_entera);
	printf("PARTE ENTERA %lf PARTE DECIMAL %lf\n", num_part_entera, num_part_decimal);

	do{

		num_usuario = num_usuario / 2;
		num_part_decimal = modf(num_usuario, &num_part_entera);

		if(num_part_decimal > 0){
			//printf("1");
			char caracter_uno = '1';
			strcat(numero_binario_correcto, "1");
			num_usuario = num_part_entera;
		}else{
			//printf("0");
			char caracter_cero = '0';
			num_usuario = num_part_entera;
			strcat(numero_binario_correcto , "0");
		}
	}while(num_part_entera != 0);


	printf("%s\n", numero_binario_correcto);
	/*
	int x = strlen(numero_binario_correcto);

	for(int y = 0; y<x;y++){
		numero_final[y] = numero_binario_correcto [x-i];
		//strcat(numero_final,numero_binario_correcto[y]);
		printf(" %c ", numero_binario_correcto[y]);
	}*/



	printf("%s\n", numero_final );
	//strrev(numero_binario_correcto);
	//printf("%s\n",numero_binario_correcto );

	return 0;
}
