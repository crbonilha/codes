#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
const int MAXN = 50010;

int n;
int carta[MAXN];
vector<int> pos[MAXN/2];

vector<int> adj[MAXN];

int pai[MAXN];
int nivel[MAXN];
int super_pai[MAXN];

int maior_altura;
void monta_arvore(int u, int p, int l);

int segmento;
void monta_super_pai(int u, int p);

int lca_2(int a, int b);

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &carta[i]);
		
		pos[ carta[i] ].push_back(i);
	}
	for(int i=1; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	maior_altura = 0;
	monta_arvore(1, 1, 0);
	segmento = sqrt(maior_altura);
	
	monta_super_pai(1, 1);
	
	int res = 0;
	for(int i=1; i<=n/2; i++) {
		int a = pos[i][0];
		int b = pos[i][1];
		
		int c = lca_2(a, b);
		
		res += (nivel[a]-nivel[c]) + (nivel[b]-nivel[c]);
	}
	
	printf("%d\n", res);
}

void monta_arvore(int u, int p, int l) {
	pai[u] = p;
	nivel[u] = l;
	
	if(l > maior_altura) {
		maior_altura = l;
	}
	
	for(int i=0; i<(int)adj[u].size(); i++) {
		int v = adj[u][i];
		
		if(!pai[v]) {
			monta_arvore(v, u, l+1);
		}
	}
}

void monta_super_pai(int u, int p) {
	super_pai[u] = p;
	
	if(nivel[u]%segmento == 0) {
		p = u;
	}
	
	for(int i=0; i<(int)adj[u].size(); i++) {
		int v = adj[u][i];
		
		if(!super_pai[v]) {
			monta_super_pai(v, p);
		}
	}
}

int lca_2(int a, int b) {
	while(super_pai[a] != super_pai[b]) {
		if(nivel[a] > nivel[b]) {
			a = super_pai[a];
		} else {
			b = super_pai[b];
		}
	}
	while(a != b) {
		if(nivel[a] > nivel[b]) {
			a = pai[a];
		} else {
			b = pai[b];
		}
	}
	return a;
}
