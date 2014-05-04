/* 
 * File:   trabalho_4.h
 * Author: Wesklei Migliorini, Gabriel
 *
 * Created on May 3, 2014, 1:45 PM
 */

#ifndef TRABALHO_4_H
#define	TRABALHO_4_H

typedef struct TREE *pTREE,**ppTREE;

typedef struct TREE{
	int data;
        int qtFilhos;
	ppTREE ppFilhos;
}TREE;


#endif	/* TRABALHO_4_H */