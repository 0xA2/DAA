#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <set>

using namespace std;

class Node {
	public:
  		list<pair<int, double>> adj;
  		bool visited;
  		double distance;
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

	  // Dijkstra's Algorithm
  	double dijkstra(int s, int e) {

    		for (int i=1; i<=n; i++) {
      			nodes[i].distance = INT_MAX;
      			nodes[i].visited  = false;
    		}

		nodes[s].distance = 0;
    		set<pair<double, int>> q;
    		q.insert({0, s});

		while (!q.empty()) {

	    		int u = q.begin()->second;
    			q.erase(q.begin());
      			nodes[u].visited = true;
	  			if(u == e){ return nodes[u].distance; }

	    		for (auto edge : nodes[u].adj) {
				int v = edge.first;
				double weight = edge.second;
				if (!nodes[v].visited && nodes[u].distance + weight < nodes[v].distance) {
	  				q.erase({nodes[v].distance, v});
	  				nodes[v].distance = nodes[u].distance + weight;
	  				q.insert({nodes[v].distance, v});
				}
      			}
    		}
		return -1;
  	}
};

int main() {

	int n, e;
  	double c;
  	string start, end, nodeA, nodeB;
  	cin >> n;
  	Graph *g = new Graph(n);
  	cin >> e;
  	cin >> start >> end;
  	map<string,int> m;
  	int mapIter = 1;
  	for (int i=1; i<=e; i++) {
    		cin >> nodeA >> nodeB >> c;
    		if(m.find(nodeA) == m.end()){ m.insert(pair<string,int>(nodeA,mapIter++));}
  		if(m.find(nodeB) == m.end()){ m.insert(pair<string,int>(nodeB,mapIter++));}
    		g->addLink(m.find(nodeA)->second, m.find(nodeB)->second, c);
  	}

  	cout << g->dijkstra(m.find(start)->second, m.find(end)->second) << endl;

	return 0;
}

