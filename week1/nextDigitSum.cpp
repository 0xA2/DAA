#include <iostream>
#include <math.h>
using namespace std;

long int sumDigits(long int value){
	long int sum = 0;
	while(value > 0){
		long int digit = value%10;
		sum += digit;
		value /= 10;
	}
	return sum;
}


int digitLen(long int n){
	int ret = 0;
	while(n > 0){
		n /= 10;
		ret++;
	}
	return ret;
}


long int firstDigitSum(long int n){
	return (n%9 + 1)*long(pow(10,(n/9)))-1;
}

long int getNextWhenLess(long int toAdd, long int start){
	long int tmp = start;
	for(int i = 0; toAdd > 0; i++){
		long int curDigit = tmp%10;
		if((toAdd + curDigit)<9){
			start += toAdd*pow(10,i);
			toAdd = 0;
		}
		else{
			start += (9 - curDigit)*long(pow(10,i));
			toAdd -= 9 - curDigit;
		}

		tmp /= 10;
	}
	return start;
}


long int getNextWhenMore(long int toSub, long int start){
	long int tmp = start;
	int i;
	for(i = 0; toSub > 0; i++){
		long int curDigit = tmp%10;
		if( toSub  < curDigit){
			start -= curDigit*long(pow(10,i));
			toSub = 0;
		}
		else{
			start -= curDigit*long(pow(10,i));
			toSub -= curDigit;
		}
		tmp /= 10;
	}
	return start+long(pow(10,i));
}


int main(){
	int pairs;
	cin >> pairs;
	for(int i = 0; i<pairs; i++){
		long int start, n;
		cin >> start;
		cin >> n;
		long int first = firstDigitSum(n);
		if(first > start){
			cout << first << endl;
		}
		else{
			long int startDigitSum = sumDigits(start);
			if(startDigitSum < n){
				long int toAdd = n - startDigitSum;
				cout << getNextWhenLess(toAdd, start) << endl;
			}

			else if(startDigitSum >= n){
				long int toSub = startDigitSum - n + 1;
				long int next = getNextWhenMore(toSub, start);
				if(digitLen(next) == digitLen(start)){
					cout << getNextWhenLess(n-sumDigits(next),next) << endl;
				}
				else{
					if(n != 1){
						cout << getNextWhenLess(n-1,long(pow(10,digitLen(start)))) << endl; 
					}
					else{
						cout << long(pow(10,digitLen(start))) << endl;
					}
				}
			}
		}
	}
	return 0;
}
