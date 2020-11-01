#include <iostream>

bool checkPartition(int toPartition[], int partitionSize, int maxSum, int size){
	int count = 1;
	int sum = 0;
	for(int i = 0; i<size; i++){
		if(toPartition[i] > maxSum){ return false; }
		sum += toPartition[i];
		if(sum  >  maxSum){
			sum = toPartition[i];
			count++;
		}
	}
 	return count <= partitionSize;
}

int binSearch(int toPartition[], int partitionSize, int start, int end, int size){
	while(start<end){
		int mid = start + (end-start)/2;
		if(checkPartition(toPartition,partitionSize,mid,size)){
			end = mid;
		}
		else{
			start = mid + 1;
		}
	}
	if(!checkPartition(toPartition,partitionSize,start,size)){return -1;}
	return start;
}



int main(){
	int size;
	std::cin >> size;
	int distances[size];
	for(int i = 0; i<size; i++){
		std::cin >> distances[i];
	}
	int questions;
	std::cin >> questions;
	int q[questions];
	for(int i = 0; i<questions; i++){
		std::cin >> q[i];
	}
	int end = 0;
	for(int i = 0; i<size;i++){
		end += distances[i];
	}
	for(int i = 0; i<questions; i++){
		std:: cout << binSearch(distances,q[i],0,end,size) << std::endl;
	}

	return 0;
}
