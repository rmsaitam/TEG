#include <cstdio>
#include <vector>
#include <iostream>

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

int main(){
	while(true){
		cout << "Digite a quantidade de Vertices(V) e Arestas(E)" << endl;
		cin >> V >> E;
		if(V==0 && V==0) break;
		grafo = VVI(V,VI(V,INF));
		for(int i=0;i<V;++i){
			for(int j=0;j<V;++j){
				int c;
				cout << "Digite (1) ou (0) para a adjacencia de grafo[" << i << "][" << j << "]" << endl;
				cin >> c;
				grafo[i][j] = c;
			}
		}
		//imprime(grafo);
	}

	return 0;
}

//CV	->	v
//E'	->	arestasVisitadas
//EC	->	verticesVisitados
//R(v)	->	

VI vizinhosDeV(NO v)
{
	VI vertices = VI(V,V);
	

	 for(int i=0;i<V;++i){
		 for(int j=0;j<V;++j){
			 if(grafos[v.x][v.y] != INF){
			 }
			 else vertices.add(dist[i][j]);
		}
		
	return vertices;
}

void fleury()
{
	
	
}

