#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include <time.h>


typedef struct TREE *pTREE,**ppTREE;

typedef struct TREE{
	int data;
	ppTREE ppFilhos;
}TREE;

void printDataAsChar(pTREE pTree);
pTREE searchTree(pTREE pRoot, int k);
void insertTree(pTREE pRoot, pTREE pNew);
void printTree(pTREE pRoot);
void preOrderTree(pTREE pRoot);
void inOrderTree(pTREE pRoot);
void posOrderTree(pTREE pRoot);
void executionTime(clock_t time_start, clock_t time_end);
void menu();

/*
int main(int argc, char **argv)
{
	TREE rootTree;

	rootTree.data = '4';
	rootTree.pLeft = NULL;
	rootTree.pRight = NULL;

	pTREE pNewTree;

	pNewTree = malloc(sizeof(TREE));
	pNewTree->pLeft = NULL;
	pNewTree->pRight = NULL;
	pNewTree->data ='2';    
	insertTree(&rootTree,pNewTree);

	pNewTree = malloc(sizeof(TREE));
	pNewTree->pLeft = NULL;
	pNewTree->pRight = NULL;
	pNewTree->data ='3';
	insertTree(&rootTree,pNewTree);

	pNewTree = malloc(sizeof(TREE));
	pNewTree->pLeft = NULL;
	pNewTree->pRight = NULL;
	pNewTree->data ='5';
	insertTree(&rootTree,pNewTree);

	pNewTree = malloc(sizeof(TREE));
	pNewTree->pLeft = NULL;
	pNewTree->pRight = NULL;
	pNewTree->data ='1';
	insertTree(&rootTree,pNewTree);

	printf("\npreOrderTree()\n");
	preOrderTree(&rootTree);
	printf("\ninOrderTree()\n");
	inOrderTree(&rootTree);
	printf("\nposOrderTree()\n");
	posOrderTree(&rootTree);


	return 0;
}*/

// main menu
int main() {
	printf("\nWelcome!");
	printf("\nWhat you want to do?");
	
	menu();
	
	return 0;
}

void menu() {
	//to use random values
	srand(time(NULL));
	clock_t time_start, time_end;

	int menu, status = 0, position;
	int noValue, n_elem,i,j;
	int pai, qt_filhos,filho;
	pTREE pRoot;

	

	pTREE pNewTree;

/*
2.) A equipe deverá montar uma interface simples de entrada de dados ( nós e arestas da árvore; tipo de percurso) bem como um relatório com as saídas dos resultados. A árvore deverá ser qualquer
*/

	do {

		printf("\n[0] Criar nova arvore");
		printf("\n[1] Percurso em Pre-Ordem");
		printf("\n[2] Percurso Em-Ordem ");
		printf("\n[3] Percurso em Pos-Ordem");
		printf("\n");
		scanf("%d", &menu);

		switch (menu) {
			case 0:

				printf("\n Quantas entradas:");
				printf("\n");
				scanf("%d",&n_elem);
				
				pRoot = malloc(sizeof(TREE));
				pRoot->ppFilhos = malloc(sizeof(pTREE));
				*(pRoot)->ppFilhos = malloc(sizeof(pTREE) * n_elem);

				printf("\n Qual a raiz:");
				printf("\n");

				scanf("%d",&noValue);

				pRoot->data = noValue;
				
				for(i=0;i<n_elem;i++)
				{
					printf("Digite o [elemto pai] [quantidade filhos] [cada filho ate [quantidade filhos]]  [-1 ou elem inexistente] Para parar\n");

					scanf("%d",&pai);
					
					//achar pai na arvore, se nao exit
					//dfs
					ppTREE ppPai;
					ppPai = malloc(sizeof(pTREE));
					//apontar para o pai que achou
					
					scanf("%d",&qt_filhos);
					
					*ppPai = malloc(sizeof(TREE) * qt_filhos);
					pTREE pFilho;
					for(j=0;j<qt_filhos;j++)
					{
						pFilho = malloc(sizeof(TREE));
						scanf("%d",&filho);
						pFilho->data = filho;
						
						memcpy(ppPai[j],pFilho,sizeof(TREE));
					}
						
				}
				status = 1;
			break;

			case 1:
				printf("What is the block size?\n");
				//scanf("%d",&blockSize);
				
				time_start = time(NULL);	
				//readRandomEntriesBlock(blockSize);
				time_end = time(NULL);

				executionTime(time_start,time_end);
			break;

			case 2:
				time_start = time(NULL);	
				//generateOneEntry(size,blockSize);
				time_end = time(NULL);

				executionTime(time_start,time_end);
			break;

			case 3:
				printf("What position?\n");
				scanf("%d",&position);
				
				time_start = time(NULL);	
				//readEntryPosition(position);
				time_end = time(NULL);

				executionTime(time_start,time_end);
			break;


			
			case 4:
				/* status = 0; */
				/* position = getInsertPosition(); */
				/* quantity = getInsertQuantity(); */
				/* printEntries(getMultipleEntries(position, quantity), quantity); */
			break;

			default: 
				status = 1;
				printf("\nPlease, select a valid option!!!");
			break;
		}

	} while (status == 1);
}




pTREE searchTree(pTREE pRoot, int k)
{
	if(pRoot != NULL || pRoot->data == k)
	{
		return pRoot;
	}

	if(pRoot->data > k)
	{
		return searchTree(pRoot->pLeft,k);
	}
	else
	{
		return searchTree(pRoot->pRight,k);
	}
}

void printDataAsChar(pTREE pTree)
{
	printf(" %c ",pTree->data);
}

void executionTime(clock_t time_start, clock_t time_end)
{
	double duration;
	// calc time elapsed
	duration = (double) (time_end - time_start) ;/// CLOCKS_PER_SEC;

	// print elapsed time
	printf("\n=> This function was running for %.2lf seconds\n", duration);
}


void insertTree(pTREE pRoot, pTREE pNew)
{
	pTREE pCurr, pPrev;

	if(!pRoot)
	{
		pRoot = pNew;
	}
	else
	{
		pCurr = pRoot;        
		while(pCurr)
		{
			pPrev = pCurr;

			if(pCurr->data > pNew->data)
			{
				pCurr = pCurr->pLeft;
			}
			else
			{
				pCurr = pCurr->pRight;
			}
		}
		if(pPrev->data > pNew->data)
		{
			pPrev->pLeft = pNew;
		}
		else
		{
			pPrev->pRight = pNew;
		}
	}    
}


void printTree(pTREE pRoot){
	pTREE pCurr;

	printf("Mostrando a BTree\n");
	if(pRoot != NULL)
	{
		printf(" %c ",pRoot->data);

		pCurr = pRoot->pLeft;        
		while(pCurr)
		{
			printf(" %c ",pCurr->data);
			pCurr = pCurr->pLeft;            
		}

		pCurr = pRoot->pRight;
		while(pCurr)
		{
			printf(" %c ",pCurr->data);
			pCurr = pCurr->pRight;            
		}
	}
}

void preOrderTree(pTREE pRoot)
{
	if(pRoot)
	{
		printDataAsChar(pRoot);
		preOrderTree(pRoot->pLeft);
		preOrderTree(pRoot->pRight);
	}
}

void inOrderTree(pTREE pRoot)
{
	if(pRoot)
	{
		inOrderTree(pRoot->pLeft);
		printDataAsChar(pRoot);        
		inOrderTree(pRoot->pRight);
	}
}

void posOrderTree(pTREE pRoot)
{
	if(pRoot)
	{
		posOrderTree(pRoot->pLeft);                
		posOrderTree(pRoot->pRight);
		printDataAsChar(pRoot);
	}
}
