#include <iostream>

int digitLen( int n ){
	int digitNum = 0;
	while(n != 0){
		digitNum++;
		n /= 10;
	}
	return digitNum;
}

void intToArray( int num,  int a[],  int len){
	for(int i = 0; i<len; i++){
		a[i] = num%10;
		num /= 10;
	}
}

int solveRecursive(int start, int end, int num[]){
	if(start >= end){ return 0; }

	if(num[start] == num[end]){
		return solveRecursive(start+1,end-1,num);
	}
	else{
		return std::min(solveRecursive(start+1,end,num),solveRecursive(start,end-1,num)) + 1; 
	}
}

int solveDP( int num[],  int len){
	 int table[len][len] = {};
	for( int diagonals = 1; diagonals<=len-1; diagonals++){
		 int row = diagonals;
		for( int col = 0; row<len; col++){
			if(num[row] == num[col]){
				table[row][col] = table[row-1][col+1];
			}
			else{
				table[row][col] = std::min(table[row-1][col],table[row][col+1]) + 1;
			}
			row++;
		}
	}
	return table[len-1][0];
}

int main(){
	int n, curNum;
	std::cin >> n;
	for( int i = 0; i<n; i++){
		std::cin >> curNum;
		int len = digitLen(curNum);
		int curCase[digitLen(curNum)] = {};
		intToArray(curNum,curCase,len);
		//std::cout << solveRecursive(0,len-1,curCase) << std::endl;
		std::cout << solveDP(curCase,len) << std::endl;
	}
	return 0;
}
