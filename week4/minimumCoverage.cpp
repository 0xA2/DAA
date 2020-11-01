#include <iostream>
#include <algorithm>
#include <array>


int earliestStart(std::array<int,2>data[], int maxBound, int size){
	int count = 0;
	int curBound = 0;
	int iter = 0;
	int max = 0;
	while(curBound < maxBound){
		while(data[iter][0] <= curBound){
			if(data[iter][1] > max){ max = data[iter][1];}
			iter++;
		}
		count++;
		curBound = max;
	}
	return count;
}


int main(){
	int maxBound;
	std::cin >> maxBound;
	int cases;
	std::cin >> cases;
	std::array<int,2> data[cases];
	for(int i = 0; i<cases; i++){
		std::cin >> data[i][0];
		std::cin >> data[i][1];
	}
	std::sort(data,data+cases);
	std::cout << earliestStart(data,maxBound,cases) << std::endl;
	return 0;
}
