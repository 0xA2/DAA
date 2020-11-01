#include <iostream>
using namespace std;

void getPrefixSums(int a[], int len){
	int sum = a[1];
	for(int i = 2; i<= len; i++){
		sum += a[i];
		a[i] = sum;
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);

	int bakugans;
	cin >> bakugans;
	int G[bakugans + 1];
	for(int i = 1; i<=bakugans; i++){
		cin >> G[i];
	}
	getPrefixSums(G,bakugans);
	int fotos;
	cin >> fotos;
	int start,end;
	for(int i = 0; i<fotos; i++){
		cin >> start;
		cin >> end;
		if(start == 1){
			cout << G[end] << endl;
		}
		else{
			cout << G[end] - G[start - 1] << endl;
		}
	}
	return 0;
}
