#include <climits>
#include <iostream>
#include <list>

using namespace std;

class Node {
	public:
  		list<pair<int, int>> adj;
  		bool visited;
  		double distance;
};

class edge{
	int arc[3];
	public:
		// getters
		int getStart(){ return arc[0];}
		int getEnd(){ return arc[1];}
		int getWeight(){ return arc[2];}
		// setters
		void setStart(int s){ arc[0] = s;}
		void setEnd(int e){ arc[1] = e;}
		void setWeight(int w){ arc[2] = w;}
};

class Graph {
	public:
  		int n;
  		Node *nodes;
  		list<edge> edges;

  	Graph(int n) {
    	this->n = n;
    	nodes = new Node[n+1];
  	}

  	void addLink(int a, int b, int c) {
    	nodes[a].adj.push_back({b,c});
    	edge tmp; tmp.setStart(a); tmp.setEnd(b); tmp.setWeight(c);
    	edges.push_back(tmp);
  	}

	bool bellmanford(int s){
		for(int i = 0; i<n; i++){
			nodes[i].visited = false;
			nodes[i].distance = INT_MAX;
		}
		nodes[s].distance = 0;
		for(int i = 0; i<n-1; i++){
			for(auto e: edges){
				if(nodes[e.getStart()].distance + e.getWeight() < nodes[e.getEnd()].distance){
					nodes[e.getEnd()].distance = nodes[e.getStart()].distance + e.getWeight();
				}
			}
		}
		for(auto e: edges){
			if(nodes[e.getStart()].distance + e.getWeight() < nodes[e.getEnd()].distance){ return true;}
		}
		return false;
	}

};


int main(){
	int cases, n, e, nodeA, nodeB, weight;
	cin >> cases;
	for(int i = 0; i<cases;i++){
		cin >> n >> e;
		Graph *g = new Graph(n);
		for(int j = 0; j<e; j++){
			cin >> nodeA >> nodeB >> weight;
			g -> addLink(nodeA,nodeB,weight);
		}
		if(g->bellmanford(0)){ cout << "possivel" << endl; }
		else{ cout << "impossivel" << endl; }
	}
	return 0;
}
