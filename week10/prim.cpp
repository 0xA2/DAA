#include <climits>
#include <iostream>
#include <list>
#include <math.h>
#include <set>

using namespace std;

class Node {
	public:
  		list<pair<int, double>> adj;
  		bool visited;
  		double distance;
  		int prev;
};

class Graph {
	public:
  		int n;
  		Node *nodes;
  		
  	Graph(int n) {
    	this->n = n;
    	nodes = new Node[n+1];
  	}

  	void addLink(int a, int b, double c) {
    	nodes[a].adj.push_back({b,c});
    	nodes[b].adj.push_back({a,c});
  	}

	double prim(int s){
		for (int i=0; i<n; i++) {
			nodes[i].distance = INT_MAX;
			nodes[i].visited  = false;
		}

		nodes[s].distance = 0;
		set<pair<double, int>> q;
		q.insert({0, s});

		double total = 0;

		while (!q.empty()) {
			int u = q.begin()->second;
			q.erase(q.begin());
			nodes[u].visited = true;
			total += nodes[u].distance;

			for (auto edge : nodes[u].adj) {
			int v = edge.first;
			double weight = edge.second;
				if (!nodes[v].visited && weight < nodes[v].distance) {
					q.erase({nodes[v].distance, v});
					nodes[v].distance = weight;
  	  				q.insert({nodes[v].distance, v});
				}
			}
		}
		return total;
  	}
};

double pointDistance(pair<double,double> p1, pair<double,double> p2){
	return sqrt( (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second) );
}


int main(){
	int npoints;
	cin >> npoints;
	Graph *g = new Graph(npoints);
	pair<double, double>  points[npoints];
	pair<double,double> p;
	for(int i = 0; i<npoints; i++){
		cin >> p.first >> p.second;
		points[i] = p;
	}
	for(int i = 0; i<npoints; i++){
		for(int j = i; j<npoints; j++){
			if(i == j){ continue; }
			g -> addLink(i,j,pointDistance(points[i],points[j]));
		}
	}
	cout << g->prim(0) << endl;

	return 0;
}
