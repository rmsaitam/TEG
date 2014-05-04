#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>


void removerAresta(int u, int v);
void adicionarAresta(int u, int v);

using namespace std;


#define all(c)    (c).begin(),  (c).end()
#define rall(c)  (c).rbegin(), (c).rend()
#define _auto(var, x)   typeof(x) var = (x)
#define _afor(it, b, e) for(_auto(it, b), _itend = e; it != _itend; ++it)
#define foreach(it, r...)       _afor(it, r)


typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

typedef struct NO{
	int x;
	int y;
} NO;

enum { INF = 1 << 30 };

void imprime(string name,VVI& dist){
	const int tam = dist.size();
	for(int i=0;i<tam;++i){
		cout << name;
		for(int j=0;j<dist[i].size();++j){
			/* if(dist[i][j]==INF) cout<<"0 "; */
			/* else  */
			cout<<dist[i][j]<< " ";

		}
		cout<<endl;
	}
}



/*---------------------------------------------------------------------
==> DIJKSTRA <==
    Finds the shortest path from S to T(or to all, if T == -1),
    although cannot handle negative-distance paths.
*/

struct Dijkstra { /// and (Prim) ==> O((E + V) log V) <==
    // For Prim, make the exchange indicated in the code

    typedef PII DNode;
    VI distTo;  // output (dist from S to each node)
    VI parent;  // output (parent of each node, coming from S)

    // adjs/dists = adj-list (graph/distances), S = Start,  D = Destiny
    Dijkstra(VVI& adjs, VVI& dists, int S, int D = -1)
                : distTo(adjs.size(), INF), parent(adjs.size(),  S) {

        set<DNode> PL; // Priority-List (dist, node)
        PL.insert( DNode(0, S) );
        distTo[S] = 0;

	cout << "veio ate aki tmb " << endl;
        while(!PL.empty()) {
            int v = PL.begin()->second;
            PL.erase(PL.begin());
            if(v == D) return;

	    int j=0;
            foreach(j, 0, adjs[v].size()) {
                int w = adjs[v][j];
                int d = distTo[v] + dists[v][j]; // going v->w
/// For Prim use: "int d = dists[v][j];" instead line above ///
                if(d < distTo[w]) {
                    if(distTo[w] != INF)
                        PL.erase( DNode(distTo[w], w) );
                    PL.insert( DNode(d, w) );
                    distTo[w] = d;
                    parent[w] = v;
                }
            }
        }
    }
};

int main(){

	VVI grafoList;
	int V;
	VVI dists;
	VI elemList,distList;

	while(true){
		/* cout << "Digite a quantidade de Vertices(V)" << endl; */
		cin >> V;
		if(V==0) break;
		
		/* cin >> E; */
		//=========PROCESSA ENTRADA====//
		//Converte matriz de adj para lista de adj
		grafoList = VVI(V,VI(V,INF));
		dists = VVI(V,VI(V,INF));
		for(int i=0;i<V;++i){
			elemList = VI(0,INF);
			distList = VI(0,INF);
			for(int j=0;j<V;++j){
				int c;
				/* cout << "Digite a matriz de adj do grafo[" << i << "][" << j << "]" << endl; */
				cin >> c;
				if(c!=0){
					elemList.push_back(j); //insere na lista

					if(j==i)
					{
						distList.push_back(0);
					}
					else
					{
						distList.push_back(1);
					}
				}
			}
			dists[i] = distList;
			grafoList[i] = elemList;
		}//FIM PROCESSA ENTRADA



		imprime("grafoList ",grafoList);
		imprime("dists ",dists);
		cout << endl;
		int S = 5;
		int D = 4;
		cout << "ate anki ok" << endl;
		Dijkstra distDijk = Dijkstra(grafoList,dists,S,D);

		cout << "dist is " << distDijk.distTo[D] << endl;
	}

	return 0;
}

/*
links uteis:
http://www.inf.ufes.br/~claudine/courses/paa09/seminarios/textos/seminario2.pdf
http://www.dharwadker.org/tevet/isomorphism/preprint.pdf
http://www.dharwadker.org/tevet/isomorphism/
http://www.mat.ufc.br/~esdras/matdisc/aula_grafos.pdf
http://stackoverflow.com/questions/8136282/graph-isomorphism-algorithm
*/
