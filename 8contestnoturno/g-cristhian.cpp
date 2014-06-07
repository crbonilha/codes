// exercício: Último a Saber
// dificuldade: médio
// tema: busca em largura
// complexidade: O( N + M )
// solução: iniciando a busca pelas K pessoas que sabiam da notícia,
//          basta fazer uma busca em largura e revelar quais pessoas
//          ficaram sabendo da notícia e em quais dias. Ao final basta
//          imprimir o indice das pessoas que souberam por último.

#include <stdio.h>
#include <string.h>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi adj[10010];
bool visi[10010];

int main() {
	int n, k, m;
	int a, b;
	
	while(scanf("%d %d %d", &n, &k, &m) && n) {
		assert(n <= 10000 and k < n and m <= 100000);
		for(int i=1; i<=n; i++) {
			adj[i].clear();
		}
		memset(visi, false, sizeof(bool)*(n+1));
		queue<ii> q;
		
		for(int i=0; i<k; i++) {
			scanf("%d", &a);
			assert(a > 0 and a <= n);
			
			q.push(ii(a, 1));
		}
		
		for(int i=0; i<m; i++) {
			scanf("%d %d", &a, &b);
			assert(a > 0 and a <= n and b > 0 and b <= n and a != b);
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		vi ultimos; int cont = 0;
		while(!q.empty()) {
			ii u = q.front(); q.pop();
			
			if(visi[u.first]) continue;
			visi[u.first] = true;
			
			if(u.second > cont) {
				ultimos.clear();
				cont = u.second;
			}
			ultimos.push_back(u.first);
			
			int size = (int)adj[u.first].size();
			for(int i=0; i<size; i++) {
				q.push(ii(adj[u.first][i], u.second+1));
			}
		}
		
		sort(ultimos.begin(), ultimos.end());
		int size = (int)ultimos.size();
		for(int i=0; i<size; i++) {
			printf("%d%c", ultimos[i], i == size-1 ? '\n' : ' ');
		}
	}
}
