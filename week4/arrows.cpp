#include <iostream>

int solver(int heights[], int arrows[], int balloons){
	int arrowTotal = 0;
	for(int i = 1; i<=balloons; i++){
		if(arrows[heights[i]]){
			arrows[heights[i]] -= 1;
			arrows[heights[i]-1] += 1;
		}
		else{
			arrows[heights[i]-1] += 1;
			arrowTotal++;
		}
	}
	return arrowTotal;
}

int main(){
	int balloons;
	std::cin >> balloons;
	int heights[balloons+1];
	int maxHeight = 0;
	for(int i = 1; i<=balloons; i++){
		std::cin >> heights[i];
		if(heights[i] > maxHeight){ maxHeight = heights[i];}
	}
	int arrows[maxHeight+1]={0};
	std::cout << solver(heights,arrows,balloons) << std::endl;
	return 0;
}
