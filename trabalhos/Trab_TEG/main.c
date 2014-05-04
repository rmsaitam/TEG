/* 
 * File:   main.c
 * Author: Wesklei, Gabriel
 *
 * Created on May 3, 2014, 1:33 PM
 */

#include "main.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int opc;
    do {
        system(LIMPA);
        printf("\t ---Teoria dos grafos---\n");
        printf("Deseja executar qual questao?\n "
                "\t[1] T4) Trabalho 4 - Arvore e percursos\n "
                "\t[0] Para Sair..."
                "\nOpcao: ");
        scanf("%d", &opc);
        switch (opc) {
            case 0://nao precisa fazer nada, sai no while
                break;
            case 1:
                menuQuestao4();                
                break;
            default:
            {
                printf("Escolhe uma das opcoes no menu!\n");
            }
        }
    } while (opc != 0);

    return (EXIT_SUCCESS);
}

