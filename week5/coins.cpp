#include <iostream>
#include <climits>

void solve(int max, int ncoins, int coinSet[], int coins[], int use[]){
	coins[0] = 0;
	for(int i = 1; i<=max;i++){
		coins[i] = INT8_MAX;
		for(int j = 1; j<=ncoins; j++){
			if(coinSet[j] <= i && 1 + coins[i-coinSet[j]] < coins[i]){
				coins[i] = 1 + coins[i-coinSet[j]];
				use[i] = coinSet[j];
			}
		}
	}
}

int main(){
	int ncoins;
	std::cin >> ncoins;
	int coinSet[ncoins+1];
	for(int i = 1; i<=ncoins; i++){
		std::cin >> coinSet[i];
	}
	int nvalues;
	std::cin >> nvalues;
	int values[nvalues];
	int max = 0;
	for(int i = 0; i<nvalues; i++){
		std::cin >> values[i];
		if(values[i] > max){ max = values[i];}
	}
	int coins[max+1] = {};
	int use[max+1] = {};
	solve(max,ncoins,coinSet,coins,use);
	for(int i = 0; i<nvalues;i++){
		std::cout  << values[i] << ": ["  << coins[values[i]] << "]";
		int v = values[i];
		while(v != 0){
			std::cout << " " << use[v];
			v -= use[v];
		}
		std::cout << std::endl;
	}
	return 0;
}
