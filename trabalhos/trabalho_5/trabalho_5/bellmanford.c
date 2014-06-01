#include "../main.h"




void menuBellmanFord(void) {
    char opcao;
    Grafo grafo;
    int n_vertices = -1, i, j, k, s, t, caminho_iterator;
    int *caminho;
    int *distancia;
    int adj_valor, adj_peso;

    do {
        system(LIMPA);
        printf("\tQ5 - ALGORITMO DE BELLMAN-FORD\n\n"
                "\t[1] Carregar matriz de adjacencia do arquivo\n"
                "\t[2] Entrar com matriz de adjacencia\n"
                "\t[3] Calcular Caminho mais curto\n"
                "\t[5] Mostra a matriz de adjacencia\n"
                "\t[0] Sair\n"
                "Opcao:__[");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:

                printf("Carregando matriz de arquivo\n\n");
                if (carregaMatrizAdjArquivo(&grafo, &n_vertices)) {
                    printf("Carregou com sucesso!\n");
                } else {
                    printf("Problema ao carregar matriz do arquivo!\n");
                }
                break;
            case 2:
                printf("Deseja inserir qntos vertices?\n");
                scanf(" %d", &n_vertices);
                if (n_vertices > 0) {
                    printf("Digite a matriz de adjacencia com %d vertices e seus respectivos pesos:\n\n", n_vertices);
                    for (i = 0; i < n_vertices; i++) {
                        for (j = 0; j < n_vertices; j++) {
                            printf("\nAdj e peso para matriz[%d][%d]:_ ", i, j);
                            scanf("%d", &adj_valor);
                            scanf("%d", &adj_peso);

                            if (insereAdj(&grafo, i, j, adj_valor, adj_peso))
                                printf("\nInseriu adjacencia %d %d com sucesso!\n", i, j);
                            else printf("\nERRO! Problema de insercao no graco com a adjacencia %d %d!\n", i, j);
                        }
                    }
                }
                break;

            case 3:

                printf("Qual o vertice de inicio?\n");
                scanf(" %d", &s);
                printf("Qual o vertice final?\n");
                scanf(" %d", &t);

                //aloca os vetores caminho e distancia
                caminho = malloc(sizeof (int) * n_vertices);
                distancia = malloc(sizeof (int) * n_vertices);

                for (i = 0; i < n_vertices; i++) {
                    caminho[i] = 0;
                    distancia[i] = INFINITO;
                }

                if (dijkstra(&grafo, s, t, n_vertices, caminho, distancia)) {

                    printf("\n\n Caminho percorrido: ");
                    caminho_iterator = t;

                    printf("%d <- ", t);

                    while (caminho_iterator != s) {
                        printf("%d", caminho[caminho_iterator]);
                        caminho_iterator = caminho[caminho_iterator];

                        if (caminho_iterator != s)
                            printf(" <- ");
                    }

                    printf("\n\nCusto de %d ate %d: %d\n\n", s, t, distancia[t]);
                } else {
                    printf("\nERRO! Problema ao executar Dijkstra de %d ate %d!\n", s, t);
                }


                break;

            case 5:
                if (n_vertices > 0) {
                    //faz cabecalho da matriz
                    printf("      ");
                    for (j = 0; j < n_vertices; j++) {
                        printf("(%d)        ", j);
                    }
                    printf("\n");
                    //o i vai imprimir o numero da linha
                    for (i = 0; i < n_vertices; i++) {
                        printf("(%d)  ", i);

                        for (j = 0; j < n_vertices; j++) {
                            printf("[%d / %d]   ", grafo.matriz[i][j].adj, grafo.matriz[i][j].peso == INFINITO ? -1 : grafo.matriz[i][j].peso);
                        }
                        printf("\n");
                    }
                } else {
                    printf("\nVoce deve primeiro carregar uma matriz de adjacencia!\n");
                }

                break;

            default:
            {
            }
        }
        printf("\n[ENTER] para continuar...\n");
        fflush(stdin);
        __fpurge(stdin);
        getchar();
    } while (opcao != 0);
}
