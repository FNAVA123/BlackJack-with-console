
#include "funciones.h"

char * repartir_cartas_jugador(char* Pmazo,int cuantas_repartir,int reiniciar){
static char cartas_de_jugador[]="\0\0\0\0\0\0\0\0\0";
static int posicion=0;
int cont = 0,mov=0;
srand (time(NULL));
if(reiniciar){
for(int j=0;j<9;j++){
	cartas_de_jugador[j]='\0';

}
posicion=0;
}
while(cont<cuantas_repartir){
	mov = rand()%13;
	Pmazo=Pmazo+mov;
if(*Pmazo!='\0'){

	cartas_de_jugador[posicion]=*Pmazo;
	posicion++;
	cont++;
    *Pmazo='\0';

}
Pmazo=Pmazo-mov;
}

return &cartas_de_jugador[0];
}
char * repartir_cartas_cupier(char* Pmazo,int cuantas_repartir,int reiniciar){
static char cartas_de_cuppier[]="\0\0\0\0\0\0\0\0\0";
int cont = 0,mov=0;
static int posicion_cuppier=0;
srand (time(NULL));
if(reiniciar){
for(int j=0;j<9;j++){
	cartas_de_cuppier[j]='\0';

}
posicion_cuppier=0;
}
while(cont<cuantas_repartir){
	mov = rand()%13;
	Pmazo=Pmazo+mov;
if(*Pmazo!='\0'){

	cartas_de_cuppier[posicion_cuppier]=*Pmazo;
	posicion_cuppier++;
	cont++;
    *Pmazo='\0';

}
Pmazo=Pmazo-mov;

}


return &cartas_de_cuppier[0];
}
int calcular_valor(char *cartas){
int valores[300];
int n=1;
int sumatoria=0;
char mazo[]="A234567890JQK\0";
for(int i=0;mazo[i]!='\0';i++){
valores[(int)mazo[i]]= n;
if(n!=10){
n++;
}else{}
}
for(int j=0;*cartas!='\0';j++){
sumatoria=sumatoria+valores[(int)*cartas];
cartas++;



}
return sumatoria;


}
void menu(char*CARTAS_JUGADOR,char*CARTAS_CUPPIER,int apuesta){
	 printf(" _____________________________________\n");
		printf("|                                     |\n");
		printf("|           MESA DE BLACKJACK         |\n");
		printf("|_____________________________________|\n");
		printf("|                                     |\n");
		printf("|  Crupier:                           |\n");
		printf("|  Cartas: %c %c %c %c                     \n",*CARTAS_CUPPIER,*(CARTAS_CUPPIER+1),*(CARTAS_CUPPIER+2),*(CARTAS_CUPPIER+3));
		printf("|                                     |\n");
		printf("|  Jugador 1:                         |\n");
		printf("|  Cartas: %c %c %c %c   apuesta:%d        \n",*CARTAS_JUGADOR,*(CARTAS_JUGADOR+1),*(CARTAS_JUGADOR+2),*(CARTAS_JUGADOR+3),apuesta);
		printf("|_____________________________________|\n");

}
