/* 
 * File:   main.h
 * Author: Wesklei Migliorini, Gabriel
 *
 * Created on May 3, 2014, 1:34 PM
 */

#ifndef _MAIN_H_
#define _MAIN_H_

/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*DEFINES*/
#define SUCESSO         1
#define FRACASSO        0
#define TRUE            1
#define FALSE           0
#define MAIOR           1
#define IGUAL           0
#define MENOR           -1
#define DIREITA         1
#define ESQUERDA        0
#define AMBOS           2

#define LIMPA "clear || cls"

#define arq6 "bellmanford.in"


#define arq5 "dijkstra.in"


#define TAMANHOMAX 50
#define INFINITO 999999
#define VISITOU 1
#define NAOVISITOU -1

typedef struct Aresta { //Para o Dijkstra
    int adj;
    int peso;
} Aresta;

typedef struct Grafo { //Para o Dijkstra
    struct Aresta matriz[TAMANHOMAX][TAMANHOMAX]; //matriz de adj
} Grafo;

#endif