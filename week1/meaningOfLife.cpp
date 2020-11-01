#include <iostream>
using namespace std;

int main(){
	int len;
	int count;
	cin >> len;
	for(int i = 0; i<len; i++){
		int curNumber;
		cin >> curNumber;
		if(curNumber == 42){
			count++;
		}
	}

	cout << count << endl;
	return 0;
}
