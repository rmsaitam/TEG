#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#define MAX 100

typedef struct listadj{
	int no;
	struct listadj *prox;
	
}LISTA;

LISTA lista[MAX+1];

void insereAdj(int no, int novo, LISTA *advnovo){
	
	advnovo->prox = NULL;
	advnovo->no = novo;
	
	LISTA **iterador;
	iterador = (LISTA**) malloc (sizeof(LISTA*));
	iterador = &lista[no].prox;
	
	while((*iterador) != NULL){
		iterador = &(*iterador)->prox;
	}
	
	(*iterador) = (LISTA*) malloc (sizeof(LISTA));
	memcpy((*iterador),advnovo,sizeof(LISTA));
	
}

void imprimieList(int nvertices){
	int i;
	LISTA *iterador; 
	
	for(i=1;i<=nvertices;i++){		
		
		printf("\n%d",lista[i].no);
		
		iterador = lista[i].prox;
		while(iterador !=NULL){
			
			printf(" %d",iterador->no);
			
			iterador = iterador->prox;
		}	
	}
}
	
int main(int argc, char **argv)
{
	int nvertices;
	int novo,i;
	LISTA *advnovo;
    printf("Quantos vertices tera o Grafo?\n");
    scanf("%d",&nvertices);
    printf("%d vertices",nvertices);
    
    for(i = 1;i <= nvertices; ++i){	
		lista[i].no = i;
		lista[i].prox = NULL;
	}
 			
	for(i = 1;i <= nvertices; ++i){			
		printf("\n\n (Zero para parar) Digite a adjacencia de %d:\n",i);	
		while(1){	
			scanf("%d",&novo);
			
			if(novo != 0){
				advnovo = (LISTA*) malloc (sizeof(LISTA));
				insereAdj(i,novo,advnovo);				
			}else{
				break;
			}
		}
	}
		
	imprimieList(nvertices);
	
	return 0;
	
}


