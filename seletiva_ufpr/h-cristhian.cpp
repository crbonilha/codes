#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
const int SIZE = 17576+1; // 26^3
const int N = 1010;

int emp[SIZE];
bool visi[N];
int m[N];
vi adj[N];

bool emparelha(int u);

int main() {
	int n, size;
	char nome[8];
	
	while(scanf("%d", &n) != EOF and n) {
		for(int i=1; i<=n; i++) {
			scanf("%d %s", &m[i], nome);
			size = strlen(nome);
			
			adj[i].clear();
			for(int a=0; a<size-2; a++) {
				for(int b=a+1; b<size-1; b++) {
					for(int c=b+1; c<size; c++) {
						adj[i].push_back((nome[a]-'a')*(int)pow(26, 2)+(nome[b]-'a')*26+(nome[c]-'a'));
						//~ printf("adj %d %d\n", i, adj[i][ (int)adj[i].size()-1 ]);
					}
				}
			}
		}
		
		memset(emp, 0, sizeof(emp));
		bool ok = true;
		for(int i=1; i<=n; i++) {
			while(m[i]--) {
				memset(visi, false, sizeof(visi));
				if(!emparelha(i)) {
					ok = false;
					break;
				}
			}
			if(!ok) break;
		}
		
		printf("%s\n", ok ? "Possivel" : "Impossivel");
	}
}

bool emparelha(int u) {
	if(visi[u]) return false;
	visi[u] = true;
	
	int size = (int)adj[u].size();
	for(int i=0; i<size; i++) {
		if(!emp[ adj[u][i] ] or emparelha(emp[ adj[u][i] ])) {
			emp[ adj[u][i] ] = u;
			return true;
		}
	}
	
	return false;
}
