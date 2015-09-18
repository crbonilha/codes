#include <stdio.h>
#include <string.h>
const int maxn = 101, maxalpha = 30;

int n, m;
int matriz[maxn][maxn];
int soma_lin[maxn], soma_col[maxn];
int aux_lin[maxn], aux_col[maxn];
int valor[maxalpha*maxalpha];
bool valido[maxalpha*maxalpha];

int desc_lin(int lin);
int desc_col(int col);
int cont_lin(int lin, int aux);
int cont_col(int col, int aux);
void revela(int aux);

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char s[4];
			scanf("%s", s);

			matriz[i][j] = ((s[0]-'a')*maxalpha) + (s[1]-'a');
		}
		scanf("%d", &soma_lin[i]);
	}
	for(int i=0; i<m; i++) {
		scanf("%d", &soma_col[i]);
	}
	memset(valor, -1, sizeof(valor));

	// trecho principal do algoritmo
	bool continua = true;
	while(continua) {
		continua = false;

		// passo 1 (linha)
		for(int i=0; i<n; i++) {
			int aux = desc_lin(i);
			if(aux != -1) {
				// passo 2
				valor[ aux ] = (soma_lin[i]-aux_lin[i])/cont_lin(i, aux);
				valido[ aux ] = true;

				// passo 3
				revela(aux);
				continua = true;
			}
		}

		// passo 1 (coluna)
		for(int j=0; j<m; j++) {
			int aux = desc_col(j);
			if(aux != -1) {
				// passo 2
				valor[ aux ] = (soma_col[j]-aux_col[j])/cont_col(j, aux);
				valido[ aux ] = true;

				// passo 3
				revela(aux);
				continua = true;
			}
		}
	}

	for(int i=0; i<maxalpha*maxalpha; i++) {
		if(valido[i]) {
			printf("%c%c %d\n", (i/maxalpha)+'a', (i%maxalpha)+'a', valor[i]);
		}
	}
}

int desc_lin(int lin) {
	int ans = -1;
	for(int j=0; j<m; j++) {
		if(!valido[ matriz[lin][j] ]) {
			if(ans == -1) {
				ans = matriz[lin][j];
			} else if(ans != matriz[lin][j]) {
				return -1;
			}
		}
	}
	return ans;
}
int desc_col(int col) {
	int ans = -1;
	for(int i=0; i<n; i++) {
		if(!valido[ matriz[i][col] ]) {
			if(ans == -1) {
				ans = matriz[i][col];
			} else if(ans != matriz[i][col]) {
				return -1;
			}
		}
	}
	return ans;
}

int cont_lin(int lin, int aux) {
	int ans = 0;
	for(int j=0; j<m; j++) {
		if(matriz[lin][j] == aux) {
			ans++;
		}
	}
	return ans;
}
int cont_col(int col, int aux) {
	int ans = 0;
	for(int i=0; i<n; i++) {
		if(matriz[i][col] == aux) {
			ans++;
		}
	}
	return ans;
}

void revela(int aux) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matriz[i][j] == aux) {
				aux_lin[i] += valor[aux];
				aux_col[j] += valor[aux];
			}
		}
	}
}
