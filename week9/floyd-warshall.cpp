#include <climits>
#include <cstring>
#include <iostream>
#include <list>

using namespace std;

class Node {
	public:
  		list<int> adj;
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

  	void addLink(int a, int b) {
    	nodes[a].adj.push_back(b);
  	}

	void floydwarshall(){
		bool connected[n][n];
		memset(connected, false, sizeof(connected[0][0]) * n * n);
		for(int i = 0; i<n; i++){
			connected[i][i] = true;
			for(int e: nodes[i].adj){
				connected[i][e] = true;
			}
		}

		for(int k = 0; k<n; k++){
			for(int i = 0; i<n; i++){
				for(int j = 0; j<n; j++){
					if(connected[i][k] && connected[k][j]){
						connected[i][j] = true;
					}
				}
			}
		}
		cout << " ";
		for(int i = 0; i<n; i++){ cout << " " << char(i+65);}
		cout << endl;
		for(int i = 0; i<n; i++){
			cout << char(i+65);
			for(int j = 0; j<n; j++){
				if(connected[i][j]){ cout << " 1";}
				else{ cout << " 0";}
			}
			cout << endl;
		}
	}
};

int main(){
	int cities, nAdj;
	char curCity, adj;
	cin >> cities;
	Graph *g = new Graph(cities);
	for(int i = 0; i<cities; i++){
		cin >> curCity >> nAdj;
		for(int j = 0; j<nAdj; j++){
			cin >> adj;
			g -> addLink(int(curCity)-65,int(adj)-65);
		}
	}
	g -> floydwarshall();

	return 0;
}




