#include <iostream>
#include <string>

#define MAX 101

#define RED 0
#define BLACK 1

int n;
bool adj[MAX][MAX];
bool visited[MAX];
int colors[MAX];

void reset(int n){
	for(int i = 1; i<=n;i++){
		visited[i] = false;
		colors[i] = 0;
		for(int j = 1; j<=n; j++){
			adj[i][j] = false;
		}
	}
}

bool dfs(int v, int color) {
	visited[v] = true;
	for(int i=1; i<=n; i++){
		if(adj[v][i] && !visited[i]){
			colors[i] = color;
			if(!dfs(i,(color+1)%2)){ return false; }
		}
		if(adj[v][i] && visited[i] && colors[v] == colors[i]){
			return false;
		}
	}
	return true;
}

int main() {
	int ngraphs;
	int edges, a, b;
	std::cin >> ngraphs;
	for(int g = 0; g<ngraphs; g++){
		std::cin >> n;
		std::cin >> edges;
		for (int i=0; i<edges; i++) {
			std::cin >> a >> b;
			adj[a][b] = adj[b][a] = true;
		}
		bool isBipartite = true;
		for(int i = 1; i<=n; i++){
			if(!visited[i]){
				colors[1] = RED;
				isBipartite = isBipartite && dfs(1,BLACK);
			}
		}
		if(isBipartite){
			std::cout << "sim" << std::endl;
		}
		else{
			std::cout << "nao" << std::endl;

		}
		reset(n);
	}
  	return 0;
}
