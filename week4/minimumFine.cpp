#include <iostream>
#include <algorithm>
#include <array>

int main(){
	int orders;
	std::cin >> orders;
	std::array<double,2> data[orders+1];
	double days,fine;
	for(int i=1; i<=orders; i++){
		std::cin >> days;
		std::cin >> fine;
		data[i][0] = days/fine;
		data[i][1] = i;
	}
	std::sort(data,data+orders+1);
	for(int i = 1; i<orders; i++){
		std::cout << data[i][1] << " ";
	}
	std::cout << data[orders][1];
	std::cout << std::endl;

	return 0;
}
