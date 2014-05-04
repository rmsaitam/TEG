/* 
 * File:   main.c
 * Author: Wesklei, Gabriel
 *
 * Created on May 3, 2014, 1:48 PM
 */

#include "trabalho_4.h"
#include "../main.h"

int criaArvore(ppTREE pp, int data) {
    if ((*pp) != NULL)
        return FRACASSO;

    *pp = malloc(sizeof (TREE));

    if ((*pp) == NULL)
        return FRACASSO;

    (*pp)->ppFilhos = NULL;
    (*pp)->data = data;

    return SUCESSO;
}

ppTREE insereArvoreQualquer(ppTREE ppTree, int dadoPai, int dadoFilho) {

    int i;

    if (ppTree != NULL) {

        if ((*ppTree)->data == dadoPai) {

            int qtFilhos = (*ppTree)->qtFilhos;
            if (qtFilhos > 0) {//nao eh o primeiro

                //realoca o espaco no pai
                (*ppTree)->ppFilhos = realloc((*ppTree)->ppFilhos, sizeof (pTREE)*(qtFilhos + 1));
                (*ppTree)->qtFilhos += 1;

                //so qtFilhos como indice, nao precisa por +1, pq comeca em zero
                (*ppTree)->ppFilhos[qtFilhos] = malloc((sizeof (TREE)));
                (*ppTree)->ppFilhos[qtFilhos]->data = dadoFilho;
                (*ppTree)->ppFilhos[qtFilhos]->ppFilhos = NULL;
                (*ppTree)->ppFilhos[qtFilhos]->qtFilhos = 0;

                return ppTree;

            } else {//eh o primeiro
                (*ppTree)->ppFilhos = malloc(sizeof (pTREE));

                //insere o novo filho
                (*ppTree)->ppFilhos[0] = malloc(sizeof (TREE));
                (*ppTree)->ppFilhos[0]->data = dadoFilho;
                (*ppTree)->ppFilhos[0]->ppFilhos = NULL;
                (*ppTree)->ppFilhos[0]->qtFilhos = 0;

                (*ppTree)->qtFilhos = 1;

                return ppTree;
            }
        } else {
            //se nao achou no pai procura nos filhos
            //se nao tem filhos, qtFilhos eh zero
            for (i = 0; i < (*ppTree)->qtFilhos; i++) {
                ppTREE ppTemp = malloc(sizeof (pTREE));

                //se ppTemp nao for NULL, eh pq achou e inseriu
                ppTemp = insereArvoreQualquer(&(*ppTree)->ppFilhos[i], dadoPai, dadoFilho);
                if (ppTemp != NULL) {
                    return ppTemp;
                }//se nao continua procurando
            }
        }
    }

    return NULL; //se nao achou retorna null
}

void exibeData(pTREE pTree) {
    if (pTree != NULL) {
        printf(" %d ", pTree->data);
    }
}

int preOrdemAvore(pTREE pTree) {

    int i;

    if (pTree == NULL)
        return FRACASSO;
    else {
        exibeData(pTree);

        for (i = 0; i < pTree->qtFilhos; i++) {
            preOrdemAvore(pTree->ppFilhos[i]);
        }
    }

    return SUCESSO;
}

int emOrdemAvore(pTREE pTree) {

    int i;

    if (pTree == NULL)
        return FRACASSO;
    else {

        if (pTree->qtFilhos > 0) {
            for (i = 0; i < pTree->qtFilhos; i++) {
                emOrdemAvore(pTree->ppFilhos[i]);
                if(i==0)
                    exibeData(pTree);//mostra o pai so 1 vez
            }
        } else {
            exibeData(pTree);
       }
    }

    return SUCESSO;
}

int posOrdemAvore(pTREE pTree) {

    int i;

    if (pTree == NULL)
        return FRACASSO;
    else {

        for (i = 0; i < pTree->qtFilhos; i++) {
            posOrdemAvore(pTree->ppFilhos[i]);
        }

        exibeData(pTree);
    }

    return SUCESSO;
}

void menuQuestao4() {

    int opc, data, data_pai, data_filho, i, j, n_entradas, n_filhos;
    ppTREE ppArvore = malloc(sizeof (pTREE));
    pTREE pArvore;

    do {
        system(LIMPA);
        printf("\n\tT4) Trabalho 4 - Arvore e percursos\n\n");
        printf(" \t[1] Criar nova arvore\n"
                "\t[2] Inserir na arvore\n"
                "\t[3] Percurso em Pre-Ordem\n "
                "\t[4] Percurso Em-Ordem \n "
                "\t[5] Percurso Pos-Ordem \n "
                "\t[0] Voltar programa principal\n"
                "Opcao: ");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                if ((*ppArvore) == NULL) {
                    printf("\n Qual a raiz:");
                    printf("\n");

                    scanf("%d", &data);

                    if (criaArvore(ppArvore, data))
                        printf("Arvore criada com sucesso!\n");
                    else
                        printf("Problema ao criar arvore!\n");

                } else {
                    printf("Arvore ja foi criada!\n\n");
                }

                break;

            case 2:

                if ((*ppArvore) != NULL) {
                    printf("Inserir novos elementos na arvore:\n\n");

                    printf("\n Quantas entradas:\n");
                    scanf("%d", &n_entradas);

                    for (i = 0; i < n_entradas; i++) {
                        printf("Digite o [elemto pai] [quantidade filhos] [cada filho ate [quantidade filhos]]\n");

                        scanf("%d", &data_pai);
                        scanf("%d", &n_filhos);

                        for (j = 0; j < n_filhos; j++) {

                            scanf("%d", &data_filho);

                            if (insereArvoreQualquer(ppArvore, data_pai, data_filho) != NULL) {
                                printf("\nInseriu elemento %d com sucesso!\n", data_filho);
                            } else {
                                printf("\n\nProblema ao inserir na arvore com o filho %d\n", data_filho);
                            }
                        }

                    }
                } else {
                    printf("Para executar essa operacao voce deve primeiro criar uma Arvore ...");
                }

                break;

            case 3:
                if ((*ppArvore) != NULL) {
                    printf("Exibindo arvore em percurso Pre-Ordem:\n\n");
                    if (preOrdemAvore(*ppArvore)) {
                        printf("\n\nPercurso em Pre-Ordem terminado!\n");
                    } else {
                        printf("\n\nProblema ao percurer a arvore usando Pre-ordem\n");
                    }
                } else {
                    printf("Para executar essa operacao voce deve primeiro criar uma Arvore ...");
                }
                break;

            case 4:
                if ((*ppArvore) != NULL) {
                    printf("Exibindo arvore em percurso Em-Ordem:\n\n");
                    if (emOrdemAvore(*ppArvore)) {
                        printf("\n\nPercurso em Em-Ordem terminado!\n");
                    } else {
                        printf("\n\nProblema ao percurer a arvore usando Em-ordem\n");
                    }
                } else {
                    printf("Para executar essa operacao voce deve primeiro criar uma Arvore ...");
                }

                break;

            case 5:
                if ((*ppArvore) != NULL) {
                    printf("Exibindo arvore em percurso Pos-Ordem:\n\n");
                    if (posOrdemAvore(*ppArvore)) {
                        printf("\n\nPercurso em Pos-Ordem terminado!\n");
                    } else {
                        printf("\n\nProblema ao percurer a arvore usando Pos-ordem\n");
                    }
                } else {
                    printf("Para executar essa operacao voce deve primeiro criar uma Arvore ...");
                }

                break;

            default:

                break;
        }

        printf("[ENTER] para continuar...\n");
        fflush(stdin);
        __fpurge(stdin);
        getchar();
    } while (opc != 0);
}


