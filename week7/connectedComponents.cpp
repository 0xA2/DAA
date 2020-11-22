#include <iostream>
#define MAX 101

int n;
bool adj[MAX][MAX];
bool visited[MAX];

void dfs(int v) {
	visited[v] = true;
	for (int i=1; i<=n; i++)
		if (adj[v][i] && !visited[i])
		dfs(i);
}

int main() {
	int edges, a, b;
	std::cin >> n;
	std::cin >> edges;
	for (int i=0; i<edges; i++) {
		std::cin >> a >> b;
		adj[a][b] = adj[b][a] = true;
	}
	int count = 0;
	for(int i = 1; i<=n; i++){
		if(!visited[i]){
			dfs(i);
			count++;
		}
	}
	std::cout << count << std::endl;
  return 0;
}
