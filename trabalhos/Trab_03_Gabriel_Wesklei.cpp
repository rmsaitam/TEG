#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>

void removerAresta(int u, int v);
void adicionarAresta(int u, int v);

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef struct NO{
	int x;
	int y;
} NO;

VVI grafo;
int V,E;
enum { INF = 1 << 30 };

void imprime(VVI& dist){
	const int V = dist.size();
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j){
			if(dist[i][j]==INF) cout<<"- ";
			else cout<<dist[i][j]<< " ";
		}
		cout<<endl;
	}
}


/**
 * conta o numero de vizinhos de um grafo nao direcionado
 */
int contaVizinhosDeV(int v)
{

	int contador = 0;

	for(int i=0;i<V;++i)
	{
		if(grafo[v][i] != INF)
		{ 
			contador++;//v com adjacencia para outro no
		}
	}
	return contador;
}


//encontra inicio do percurso no grafo
//o primeiro no com grau impar que achar
//se nao achar com grau impar, comeca em zero (0)
int achaInicio()
{
	int inicio=0;
	for(int i=0;i<V;++i)
	{
		if(contaVizinhosDeV(i) % 2 != 0)
		{
			inicio = i;
			break;
		}
	}

	return inicio;
}

// deep fisrt search para contar os vertices alcancados apartir de v
int dfsContador(int v, bool visitado[])
{
	visitado[v] = true;
	int contador = 0;

	for(int j=0;j<V;++j){
		if (grafo[v][j] != INF && !visitado[j])
			contador += dfsContador(j, visitado);
	}

	return contador;
}

//verifica se u-v nao eh um caminho valido: v eh unico possivel caminho ou nao eh ponte
// The function to check if edge u-v can be considered as next edge in
// Euler Tout
bool ehAdjacenciaValida(int u, int v)
{
	//se v eh o unico caminho possivel
	int cont=0;
	for(int j=0;j<V;++j){
		if (grafo[u][j] != INF)
			cont++;
	}

	if (cont == 1)
		return true;


	//Se nao era unico, entao testa se nao eh ponte

	// Conta quantos vertices alcanca via dfs apartir de u
	bool visitados[V];
	memset(visitados, false, V);
	int cont1 = dfsContador(u, visitados);

	// remove a aresta u-v e conta o alcance sem ele
	removerAresta(u, v);
	memset(visitados, false, V);
	int cont2 = dfsContador(u, visitados);

	//adiciona novamente para poder continuar
	adicionarAresta(u, v);

	// testa se eh ponte: se con1 for maior u-v eh ponte
	return (cont1 > cont2)? false: true;
}

void removerAresta(int u, int v)
{
	grafo[u][v]=grafo[v][u]=INF;
}

void adicionarAresta(int u, int v)
{
	grafo[u][v]=grafo[v][u]=1;
}

//imprime o caminho euleriano apartir de u
void fleury(int u)
{
	for(int j=0;j<V;++j)
	{
		//se u-v nao foi removido e nao eh ponte
		if (grafo[u][j] != INF && ehAdjacenciaValida(u,j))
		{
			cout << u << "-" << j << "  ";
			removerAresta(u, j);
			fleury(j);
		}
	}
}


int main(){
	while(true){
		/* cout << "Digite a quantidade de Vertices(V) e Arestas(E)" << endl; */
		cin >> V;
		if(V==0) break;
		
		/* cin >> E; */
		grafo = VVI(V,VI(V,INF));
		for(int i=0;i<V;++i){
			for(int j=0;j<V;++j){
				int c;
				/* cout << "Digite o numero de adjacencia de grafo[" << i << "][" << j << "] (0 para nenhuma)" << endl; */
				cin >> c;
				if(c==0){
					c = INF; //marcacao
				}

				grafo[i][j] = c;
			}
		}

		/* imprime(grafo); */

		int inicio = achaInicio();

		/* cout << "inicio eh " << inicio << endl; */
		fleury(inicio);
	}

	return 0;
}
