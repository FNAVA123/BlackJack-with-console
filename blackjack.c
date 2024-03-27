/*
 ============================================================================
 Name        : blackjack.c
 Author      : FN
 Version     :
 Copyright   : FUCK YOU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define ERROR 1

int main(void) {
char* CARTAS_JUGADOR=NULL,*CARTAS_CUPPIER=NULL;
int seleccion=0,apuesta=0,op=0,PointsCupp=0,PointsPlayer=0;
int dinero_disponible=1000;

printf(" ______   _____          _        ______  ___  ____      _____     _        ______  ___  ____\n");
 printf("|_   _ \\ |_   _|        / \\     .' ___  ||_  ||_  _|    |_   _|   / \\     .' ___  ||_  ||_  _|\n");
 printf("  | |_) |  | |         / _ \\   / .'   \\_|  | |_/ /        | |    / _ \\   / .'   \\_|  | |_/ /\n");
 printf("  |  __'.  | |   _    / ___ \\  | |         |  __'.    _   | |   / ___ \\  | |         |  __'.\n");
 printf(" _| |__) |_| |__/ | _/ /   \\ \\_\\ `.___.'\\ _| |  \\ \\_ | |__' | _/ /   \\ \\_\\ `.___.'\\ _| |  \\ \\_\n");
 printf("|_______/|________||____| |____|`.____ .'|____||____|`.____.'|____| |____|`.____ .'|____||____|\n");
 printf("\n\r");
printf("1-INICIAR 2-SALIR\n\r");
if(scanf("%d", &seleccion)!=1){
printf("ERROR--SOLO SE ADMITEN NUMEROS\n\r");
system("PAUSE");
return ERROR;
}

if(seleccion==2){
	return 0;
}else{
	while(1){
	if(dinero_disponible<=0){
		break;
	}
    char mazo[]="A234567890JQKA234567890JQKA234567890JQKA234567890JQK";
	printf("CUANTO QUIERES APOSTAR? -DINERO DISPONIBLE:%d\n\r",	dinero_disponible);
	if(scanf("%d", &apuesta)!=1){
	printf("ERROR--SOLO SE ADMITEN NUMEROS\n\r");
	system("PAUSE");
	return ERROR;
	}
	dinero_disponible-=apuesta;
	CARTAS_JUGADOR=repartir_cartas_jugador(&mazo[0],2,1);
	CARTAS_CUPPIER= repartir_cartas_cupier(&mazo[0],1,1);

while(1){

menu(CARTAS_JUGADOR,CARTAS_CUPPIER,apuesta);
PointsCupp=calcular_valor(CARTAS_CUPPIER);
PointsPlayer=calcular_valor(CARTAS_JUGADOR);

printf("tienes:%d\n\r",PointsPlayer);

if(PointsPlayer>21 ){
	printf("PERDISTE:-%d\n\r",apuesta);
		break;
	}

printf("tiene:%d\n\r",PointsCupp);
printf("1.Pedir 2.plantarse\n\r");
if(scanf("%d", &op)!=1){
printf("ERROR--SOLO SE ADMITEN NUMEROS\n\r");
system("PAUSE");
return ERROR;
}
if(op==2){
while(PointsCupp<=PointsPlayer ){
	CARTAS_CUPPIER= repartir_cartas_cupier(&mazo[0],1,0);
	menu(CARTAS_JUGADOR,CARTAS_CUPPIER,apuesta);
	PointsCupp=calcular_valor(CARTAS_CUPPIER);

	}
if(PointsPlayer==21 || PointsCupp>21){
	printf("GANASTE:+%d\n\r",abs((apuesta*3)-apuesta));
	dinero_disponible+=apuesta*3;
	break;
	}
	if(PointsCupp>PointsPlayer ){
			printf("PERDISTE:-%d\n\r",apuesta);
			break;
		}


		printf("EMPATE\n\r");

}

else{
	CARTAS_JUGADOR=repartir_cartas_jugador(&mazo[0],1,0);
}
printf("\n\r");


}

	}
system("PAUSE");
return 0;





}



}
