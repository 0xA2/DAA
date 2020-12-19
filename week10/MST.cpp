#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <set>

using namespace std;

class Node {
	public:
  		list<pair<int, int>> adj;
  		bool visited;
  		int distance;
};

class Graph {
	public:
  		int n;
  		Node *nodes;

  	Graph(int n) {
    	this->n = n;
    	nodes = new Node[n+1];
  	}

  	void addLink(int a, int b, int c) {
    	nodes[a].adj.push_back({b,c});
    	nodes[b].adj.push_back({a,c});
  	}

	void prim(int s){

		for (int i=1; i<=n; i++) {
			nodes[i].distance = INT_MAX;
			nodes[i].visited  = false;
		}

		nodes[s].distance = 0;
		set<pair<int, int>> q;
		q.insert({0, s});

		int sum = 0;
		list<int> newEdges;

		while (!q.empty()) {
			int u = q.begin()->second;
			q.erase(q.begin());
			nodes[u].visited = true;
			if(nodes[u].distance){
				sum += nodes[u].distance;
				newEdges.push_back(nodes[u].distance);
			}

			for (auto edge : nodes[u].adj) {
				int v = edge.first;
				int weight = edge.second;
					if (!nodes[v].visited && weight < nodes[v].distance) {
						q.erase({nodes[v].distance, v});
						nodes[v].distance = weight;
  	  					q.insert({nodes[v].distance, v});
					}
			}
		}
		cout << sum << endl;
		newEdges.sort();
		for(int w: newEdges){
			cout << w << " ";
		}
		cout << endl;
  	}
};

int main(){
	int existingNodes, toAdd, newArcs, a, b, c;
	cin >> existingNodes >> toAdd >> newArcs;
	Graph *g = new Graph(existingNodes+toAdd);
	for(int i = 1; i<existingNodes; i++){
		g -> addLink(i,i+1,0);
	}
	for(int i = 1; i<=newArcs; i++){
		cin >> a >> b >> c;
		g->addLink(a,b,c);
	}
	g -> prim(1);
	return 0;
}
