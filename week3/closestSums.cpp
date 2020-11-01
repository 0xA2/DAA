#include <iostream>
#include <algorithm>
#include <cmath>

int binSearchAndPrint(int q, int sums[], int start, int end){
	int mid = 0;
	if(q >= sums[end]){ std::cout << sums[end] << std::endl; return 0;}
	if(q <= sums[start]){ std::cout << sums[start] << std::endl; return 0;}
	while(start<end){
		int mid = start + (end-start)/2;
		if(q == sums[mid]) {
			std::cout << sums[mid] << std::endl;
			return 0;
		}
		if(q <= sums[mid]){
			if(mid>0 && q>sums[mid-1]){
				if(abs(q-sums[mid]) < abs(q-sums[mid-1])){
					std::cout << sums[mid] << std::endl;
					return 0;
				}
				else if(abs(q-sums[mid]) > abs(q-sums[mid-1])){
					std::cout << sums[mid-1] << std::endl;
					return 0;
				}
				else{
					std::cout << sums[mid-1] << " " << sums[mid] << std::endl;
					return 0;
				}
			}
			end = mid;
		}
		else if(q >= sums[mid]){
			if(q<sums[mid+1]){
				if(abs(q-sums[mid]) < abs(q-sums[mid+1])){
					std::cout << sums[mid] << std::endl;
					return 0;
				}
				else if(abs(q-sums[mid]) > abs(q-sums[mid+1])){
					std::cout << sums[mid+1] << std::endl;
					return 0;
				}
				else{
					std::cout << sums[mid] << " " << sums[mid+1] << std::endl;
					return 0;
				}
			}
			start = mid+1;
		}
	}
	std::cout << sums[mid] << std::endl;
	return 0;
}



int main(){
	int setSize;
	std::cin >> setSize;
	int set[setSize];
	for(int i = 0; i<setSize; i++){
		std::cin >> set[i];
	}

	int numberOfQuestions;
	std::cin >> numberOfQuestions;
	int questions[numberOfQuestions];
	for(int i = 0; i<numberOfQuestions; i++){
		std::cin >> questions[i];
	}
	int sumSize = (setSize*(setSize-1))/2;
	int sums[sumSize];
	int k = 0;
	for(int i = 0; i<(setSize-1); i++){
		for(int j = i+1; j<setSize; j++){
			sums[k] = set[i]+set[j];
			k++;
		}
	}
	std::sort(sums, sums+sumSize);

	for(int i = 0; i<numberOfQuestions; i++){
		binSearchAndPrint(questions[i],sums,0,sumSize-1);
	}



	return 0;
}
