#include <iostream>
#include <climits>

int main(){
	int height, missing;
	std::cin >> height;
	std::cin >> missing;
	int pyramid[height+1][height+1] = {};
	int missingInRow, missingInCol;
	for(int i = 0; i<missing; i++){
		std::cin >> missingInRow;
		std::cin >> missingInCol;
		pyramid[((height-missingInRow)%height)+1][missingInCol] = -1;
	}
	int paths = 0;
	if(pyramid[1][1] == -1) { 
		std::cout << 0 << std::endl;
		return 0;
	}
	pyramid[1][1] = 1;
	for(int i = 1; i<=height; i++){
		for(int j = 1; j<=i; j++){
			if(pyramid[i][j] == -1){ continue;}
			if(pyramid[i-1][j-1] != -1){
				pyramid[i][j] += pyramid[i-1][j-1];
			}
			if(pyramid[i-1][j] != -1){
				pyramid[i][j] += pyramid[i-1][j];
			}
			if(i == height){ paths += pyramid[i][j];}
		}
	}
	std::cout << paths << std::endl;
	return 0;
}
