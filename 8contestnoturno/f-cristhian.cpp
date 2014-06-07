#include <stdio.h>
#include <string.h>

int n;
char matriz[1010][1010];
bool visi[1010];

bool checa(int a, int b);

int main() {
	while(1) {
		scanf("%d", &n); if(!n) break;
		
		for(int i=0; i<n; i++) {
			scanf("%s", matriz[i]);
		}
		
		int cont = 0;
		memset(visi, false, sizeof(visi));
		for(int i=0; i<n; i++) if(!visi[i]) {
			cont++;
			for(int j=0; j<n; j++) if(matriz[i][j] == '1') {
				if(!checa(j, i)) {
					cont = -1;
				}
				visi[j] = true;
			}
			visi[i] = true;
			if(cont == -1) break;
		}
		
		if(cont == -1) {
			printf("impossivel\n");
		} else {
			printf("%d\n", cont);
		}
	}
}

bool checa(int a, int b) {
	for(int i=0; i<n; i++) if(i != a && i != b) {
		if(matriz[a][i] != matriz[b][i])
			return false;
	}
	
	return true;
}
