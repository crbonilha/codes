#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

// direções e correspondentes setas e setas invertidas
const int dx[4]      = { 0 ,  0 ,  1 , -1 };
const int dy[4]      = { 1 , -1 ,  0 ,  0 };
const char dir_ok[4] = {'<', '>', '^', 'v'};
const char dir_op[4] = {'>', '<', 'v', '^'};

// variáveis de entrada
int n, m;
char matriz[110][110];

// variável para evitar visitar o mesmo vértice milhões de vezes
bool visi[110][110][110];

bool dfs(ii u, int k) {
	if(visi[u.first][u.second][k])
		return false;
	visi[u.first][u.second][k] = true;
	
	// partindo do centro, se eu chegar a borda, a resposta é "Sim"
	if(borda(u))
		return true;
	
	// seguindo o fluxo das setas
	ii v;
	for(int i=0; i<4; i++) {
		v.first = u.first+dx[i];
		v.second = u.second+dy[i];
		
		if(limite(v) && matriz[v.first][v.second] == dir_ok[i]) {
			if(dfs(v, k))
				return true;
		}
	}
	
	// seguindo o fluxo contrário ao das setas
	if(k) for(int i=0; i<4; i++) {
		v.first = u.first+dx[i];
		v.second = u.second+dy[i];
		
		if(limite(v) && matriz[v.first][v.second] == dir_op[i]) {
			if(dfs(v, k-1))
				return true;
		}
	}
	
	// oops, não foi dessa vez =/
	return false;
}

// verifica se a posição atual compõe a borda do mapa
bool borda(ii u) {
	if(u.first == 0 || u.first == n-1 || u.second == 0 || u.second == m-1)
		return true;
	else
		return false;
}

// verifica se a posição atual está fora do mapa
bool limite(ii u) {
	if(u.first < 0 || u.second < 0 || u.first >= n || u.second >= m)
		return false;
	else
		return true;
}
