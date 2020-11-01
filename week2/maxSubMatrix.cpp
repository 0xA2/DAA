#include <iostream>
#include <vector>

int kadane(int rowSums[], int size){
	int maxSum = INT8_MIN;
	int curSum = 0;
	for(int i = 0; i<size; i++){
		curSum = std::max(rowSums[i], curSum + rowSums[i]);
		maxSum = std::max(maxSum, curSum);
	}
	return maxSum;
}


int getMaxSubmatrixSum(std::vector<std::vector<int>> matrix){
	int maxSubmatrixSum = INT8_MIN;
	for(int L = 0; L<int(matrix[0].size()); L++){
		int rowSums[int(matrix.size())]={};
		for(int R = L; R<int(matrix[0].size()); R++){
			for(int i = 0; i<int(matrix.size());i++){
				rowSums[i] += matrix[i][R];
			}
			maxSubmatrixSum = std::max(maxSubmatrixSum, kadane(rowSums, int(matrix.size())));
		}
	}

	return maxSubmatrixSum;
}

int main(){
	int rows,cols;
	std::cin >> rows;
	std::cin >> cols;
	std::vector<std::vector<int>> matrix(rows,std::vector<int>(cols));
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			std::cin >> matrix[i][j];
		}
	}
	std::cout << getMaxSubmatrixSum(matrix) << std::endl;

	return 0;
}
