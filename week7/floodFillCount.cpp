#include <iostream>
#include <string>

#define dirs 8
#define MAX 101

int n;
int rows, cols;
char matrix[MAX][MAX] = {};
bool visited[MAX][MAX] = {};

int dirX[dirs] = { 0, 0,+1,-1,+1,+1,-1,-1};
int dirY[dirs] = {+1,-1, 0, 0,-1,+1,+1,-1};



int dfs(int x, int y) {
	if(!(x>=0 && x<rows && y>=0 && y<cols)){ return 0; }
	if(matrix[x][y] != '#'){ return 0; }
	matrix[x][y] = '.';
	int count = 1;
	for(int i = 0; i<dirs; i++){
		 count += dfs(x+dirX[i],y+dirY[i]);
	}
	return count;
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i<n; i++){
		std::cin >> rows;
		std::cin >> cols;
		for (int i=0; i<rows; i++) {
			std::cin >> matrix[i];
		}

		int max = 0;
		int cur = 0;
		for(int i = 0; i<rows;i++){
			for(int j = 0; j<cols; j++){
				if(matrix[i][j] == '#'){
					cur = dfs(i,j);
					if(cur > max){max = cur;}
				}
			}
		}
		std::cout << max << std::endl;
	}
	return 0;
}
