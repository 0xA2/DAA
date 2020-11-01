#include <iostream>
using namespace std;

int main(){
	int pairs;
	cin >> pairs;
	int map[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, -1, 21, -1, 22};
	for(int i = 0; i<pairs; i++){
		string s1, s2;
		cin >> s1;
		cin >> s2;
		string delimiter = "-";
		string sA[] = {s1.substr(0, s1.find(delimiter)),s1.substr(3, s1.find(delimiter)),s1.substr(6, s1.find(delimiter))};
		string sB[] = {s2.substr(0, s2.find(delimiter)),s2.substr(3, s2.find(delimiter)),s2.substr(6, s2.find(delimiter))};
		int n1,n2;
		
		// first plate - 4th generation
		if(int(sA[0][0]) >= 65 && int(sA[2][0]) >= 65){
			n1 = (map[int(sA[0][0])]*23*23*23+map[int(sA[0][1])]*23*23+map[int(sA[2][0])]*23+map[int(sA[2][1])])*100+stoi(sA[1])+15870000;
		}
		// first plate - 1st generation
		else if(int(sA[0][0]) >= 65){
			n1 = (map[int(sA[0][0])]*23+map[int(sA[0][1])])*10000+stoi(sA[1])*100+stoi(sA[2]);
		}
		// first plate - 2nd generation
		else if(int(sA[1][0]) >= 65){
			n1 = (map[int(sA[1][0])]*23+map[int(sA[1][1])])*10000+stoi(sA[0])*100+stoi(sA[2])+10580000;
		}
		// first plate - 3rd generation
		else if(int(sA[2][0]) >= 65){
			n1 = (map[int(sA[2][0])]*23+map[int(sA[2][1])])*10000+stoi(sA[0])*100+stoi(sA[1])+5290000;
		}


		// second plate - 4th generation
		if(int(sB[0][0]) >= 65 && int(sB[2][0]) >= 65){
			n2 = (map[int(sB[0][0])]*23*23*23+map[int(sB[0][1])]*23*23+map[int(sB[2][0])]*23+map[int(sB[2][1])])*100+stoi(sB[1])+15870000;
		}
		// second plate - 1st generation
		else if(int(sB[0][0]) >= 65){
			n2 = (map[int(sB[0][0])]*23+map[int(sB[0][1])])*10000+stoi(sB[1])*100+stoi(sB[2]);
		}
		// second plate - 2nd generation
		else if(int(sB[1][0]) >= 65){
			n2 = (map[int(sB[1][0])]*23+map[int(sB[1][1])])*10000+stoi(sB[0])*100+stoi(sB[2])+10580000;
		}
		// second plate - 3rd generation
		else if(int(sB[2][0]) >= 65){
			n2 = (map[int(sB[2][0])]*23+map[int(sB[2][1])])*10000+stoi(sB[0])*100+stoi(sB[1])+5290000;
		}

		cout << max(n1,n2) - min(n1,n2) << endl;
	}
	return 0;
}
