#include "main.h"

/*
 * 
 */
int menuTrab5() {

    int opc;
    do {
        system(LIMPA);
        printf("\t ---Teoria dos grafos---\n");
        printf("Deseja executar qual questao?\n "
                "\t[1] T5) Trabalho 5 - Dijkstra \n "
                "\t[2] T5) Trabalho 5 - Bellman-Ford\n "
                "\t[0] Para Sair..."
                "\nOpcao: ");
        scanf("%d", &opc);
        switch (opc) {
            case 0://nao precisa fazer nada, sai no while
                break;
            case 1:
                menuDijkstra();
                break;
            case 2:
                menuBellmanFord();
                break;
            default:
            {
                printf("Escolhe uma das opcoes no menu!\n");
            }
        }
    } while (opc != 0);
}


