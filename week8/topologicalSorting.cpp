#include <iostream>
#include <list>
#include <set>
#include <string>

bool visited[26];
bool adj[26][26];

std::list<int> order;
std::set<int> nodes;

void dfs(int v){
	visited[v] = true;
	for(int i = 0; i<26; i++){
		if(adj[v][i] && !visited[i]){
			dfs(i);
		}
	}
	order.push_front(v);
}

int main(){
	int nwords;
	std::string word1;
	std::string word2;
	std::cin >> nwords;
	std::cin >> word1;
	for(int i = 1; i<nwords;i++){
		 std::cin >> word2;
		 for(int j = 0; j<int(std::min(word1.length(),word2.length())); j++){
			if( word1[j] != word2[j]){
				adj[int(word1[j])-65][int(word2[j])-65] = true;
				nodes.insert(int(word1[j]-65));
				nodes.insert(int(word2[j]-65));
				break;
			}
		 }
		word1 = word2;
	}
	for(int i = 0; i<26; i++){
		if(!visited[i]){
			dfs(i);
		}
	}

	for( int i : order){
		if(nodes.count(i)){
			std::cout << char(i+65);
		}
	}
	std::cout << std::endl;

	return 0;
}
