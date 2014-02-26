#include <vector>
using namespace std;

int n, t;

const int INF = 0x3f3f3f3f;
bool visi[11];
vector<pair<int, int> > adj[11];

int funcao(int u, int tanque) {
	if(u == n)
		return 0;
	
	if(visi[u])
		return INF;
	visi[u] = true;
	
	int size = (int)adj[u].size(), minimo = INF-1;
	for(int k=0; k<=t-tanque; k++) {
		for(int i=0; i<size; i++) if(tanque+k >= adj[u][i].second) {
			minimo = min(minimo, funcao(adj[u][i].first, tanque+k-adj[u][i].second)+k*custo[u]);
		}
	}
	
	visi[u] = false;
	return minimo;
}
