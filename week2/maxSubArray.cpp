#include <iostream>

// Kadane's Algorithm
int getMaxSubArrayValue(int a[], int size){
	int maxSum = -2147483648;
	int curSum = 0;
	for(int i = 0; i<size; i++){
		curSum = std::max(a[i], curSum + a[i]);
		maxSum = std::max(maxSum, curSum);
	}
	return maxSum;
}

int main(){
	int arraySize;
	std::cin >> arraySize;
	int a[arraySize];
	for(int i = 0; i<arraySize; i++){
		std::cin >> a[i];
	}
	std::cout << getMaxSubArrayValue(a,arraySize) << std::endl;
	return 0;
}
