#include <algorithm>
#include <iostream>
#include <list>



std::list<int> centralNodes;
std::list<int> peripheryNodes;


// Classe que representa um no
class Node {
public:
  std::list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
	public:
		int n;          // Numero de nos do grafo
		Node *nodes;    // Array para conter os nos

	Graph(int n) {
		this->n = n;
		nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
	}

	void addLink(int a, int b) {
		nodes[a].adj.push_back(b);
		nodes[b].adj.push_back(a);
	}

	int getMaxDistance(int v) {
		int ret;
		std::list<int> q;
		for (int i=1; i<=n; i++) nodes[i].visited = false;

		q.push_back(v);
		nodes[v].visited = true;
		nodes[v].distance = 0;

		while (q.size() > 0) {
			int u = q.front(); q.pop_front();
			for (auto w : nodes[u].adj)
				if (!nodes[w].visited) {
	  				q.push_back(w);
					nodes[w].visited  = true;
					nodes[w].distance = nodes[u].distance + 1;
					ret = nodes[w].distance;
				}
		}
		return ret;
  	}

};

int main(){
	int n, e, a, b;
	std::cin >> n;
	Graph *g = new Graph(n);
	std::cin >> e;
	for (int i=0; i<e; i++) {
		std::cin >> a >> b;
		g->addLink(a, b);
	}

	int diameter = 0;
	int radius = n;
	int cur;
	for(int i = 1; i<=n; i++){
		cur = g->getMaxDistance(i);
		if(cur > diameter){ diameter = cur;}
		if(cur < radius){ radius = cur;}
	}

	for(int i = 1; i<=n; i++){
		cur = g -> getMaxDistance(i);
		if(cur == radius){ centralNodes.push_back(i);}
		if(cur == diameter){ peripheryNodes.push_back(i);}
	}
	std::cout << diameter << std::endl;
	std::cout << radius << std::endl;

	for(auto i : centralNodes){
		if(i != centralNodes.back()){
			std::cout << i << " ";
		}
		else{
			std::cout << i;
		}
	}
	std::cout << std::endl;

	for(auto i : peripheryNodes){
		if(i != peripheryNodes.back()){
			std::cout << i << " ";
		}
		else{
			std::cout << i;
		}
	}
	std::cout << std::endl;

	return 0;
}
