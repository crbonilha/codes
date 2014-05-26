#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int moeda[32];

int get_lowerbound(int valor, int atual);
int get_upperbound(int valor, int atual);
int funcao(int valor, int upper, int lower, int atual);

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) {
			scanf("%d", &moeda[i]);
		}
		sort(moeda, moeda+n);
		
		printf("%d\n", funcao(m, m, m, 0));
	}
}

int funcao(int valor, int upper, int lower, int atual) {
	if(atual == n) return (valor ? 1000000 : 0);
	int this_upper = get_upperbound(valor, atual);
	int this_lower = get_lowerbound(valor, atual);
	if(this_upper == this_lower) return this_upper;
	else if(this_lower > lower) return lower;
	else if(this_upper > upper) return upper;
	printf("%d, %d, %d-%d\n", valor, atual, this_lower, this_upper);
	
	int ans = this_lower;
	for(int i=0; i<=valor/moeda[atual]; i++) if(valor-i*moeda[atual] >= 0) {
		ans = min(ans, funcao(valor-i*moeda[atual], this_upper, this_lower, atual+1)+i);
	}
	
	return ans;
}

int get_lowerbound(int valor, int atual) {
	int cont = 0, aux;
	for(int i=n-1; i>=atual; i--) {
		aux = valor/moeda[i];
		cont += aux;
		valor -= aux*moeda[i];
	}
	return cont+(valor ? 1 : 0);
}
int get_upperbound(int valor, int atual) {
	int cont = 0, aux;
	for(int i=atual; i<n; i++) {
		aux = valor/moeda[i];
		cont += aux;
		valor -= aux*moeda[i];
	}
	return cont+(valor ? 1 : 0);
}
