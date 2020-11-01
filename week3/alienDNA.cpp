#include <iostream>
#include <algorithm>
#include <string>

struct LetterFreq{
	char letter;
	int number;
	int firstAppearance;
	bool flag = false;
};

bool compareLetterFrequency(LetterFreq  a, LetterFreq b){
	if( a.number > b.number){ return true;}
	if( a.number < b.number){ return false;}
	if( a.firstAppearance < b.firstAppearance){ return true;}
	else{ return false;}
}

int main(){
	std::string dna;
	std::cin >> dna;
	LetterFreq a[26];

	for(int i = 0; i<int(dna.length());i++){
		if(a[int(dna[i])-65].flag){
			a[int(dna[i])-65].number += 1;
		}

		else{
			a[int(dna[i])-65].letter = dna[i];
			a[int(dna[i])-65].number = 1;
			a[int(dna[i])-65].firstAppearance = i;
			a[int(dna[i])-65].flag = true;
		}
	}
	std::sort(a, a+26, compareLetterFrequency);
	for(int i = 0; i<26; i++){
		if(a[i].flag){
			std::cout << a[i].letter << " " << a[i].number << std::endl;
		}
	}
	return 0;
}
