// exercício: Maçãs
// tempo para programar: 10 minutos
// dificuldade: médio
// tema: bfs e dp
// complexidade: O( N*M*2K )
// solução: para a posição inicial do Rafael [x, y], basta utilizar
//          a seguinte fórmula recursiva para se determinar o número
//          máximo de maçãs a ser coletadas:
//          funcao(x, y, t) = max(funcao(new_x, new_y, tempo+1) para todo
//          new_x e new_y correspondendo às posições adjacentes).
//          Adiciona-se um bonus caso na posição atual e no tempo atual
//          caso haja uma maçã.
//          Usa-se dp para reaproveitar cálculos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> ii;
const int VAZIO = 0x3f3f3f3f;
const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, k;
int dp[25][25][2010];
set<pair<ii, int> > macas;
int ultimo_tempo;

int funcao(ii u, int tempo);
bool limite(ii a);

int main() {
	int a, b, c;
	
	while(1) {
		// lendo
		scanf("%d %d %d", &n, &m, &k);
		if(!n) break;
		
		// lendo
		macas.clear();
		ultimo_tempo = 0;
		for(int i=0; i<k; i++) {
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			
			macas.insert( make_pair(ii(a, b), c) );
			ultimo_tempo = max(ultimo_tempo, c+1);
		}
		
		// lendo
		ii u;
		scanf("%d %d", &u.first, &u.second);
		u.first--; u.second--;
		
		// limpando
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				memset(dp[i][j], 0x3f, sizeof(dp[i][j]));
			}
		}
		
		// resolvendo
		printf("%d\n", funcao(u, 0));
	}
}

int funcao(ii u, int tempo) {
	if(tempo == ultimo_tempo)
		return 0;
	if(dp[u.first][u.second][tempo] != VAZIO)
		return dp[u.first][u.second][tempo];
	
	int bonus = macas.count(make_pair(u, tempo));
	
	int maximo = funcao(u, tempo+1);
	ii v;
	for(int i=0; i<8; i++) {
		v.first = u.first+dx[i];
		v.second = u.second+dy[i];
		
		if(limite(v)) {
			maximo = max(maximo, funcao(v, tempo+1));
		}
	}
	
	return dp[u.first][u.second][tempo] = maximo+bonus;
}

bool limite(ii a) {
	if(a.first < 0 || a.first >= n || a.second < 0 || a.second >= m)
		return false;
	else
		return true;
}
