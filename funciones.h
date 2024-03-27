/*
 * funciones.h
 *
 *  Created on: Dec 26, 2023
 *      Author: FJNR1
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char * repartir_cartas_jugador(char *Pmazo,int cuantas_repartir,int reiniciar);
char * repartir_cartas_cupier(char *Pmazo,int cuantas_repartir,int reiniciar);
int calcular_valor(char *cartas);
void menu(char* CARTAS_JUGADOR,char*CARTAS_CUPPIER,int apuesta);
#endif /* FUNCIONES_H_ */
