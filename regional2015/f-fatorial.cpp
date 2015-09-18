#include <stdio.h>

int n;
int fat[10];

int main() {
	fat[1] = 1;
	for(int i=2; i<=8; i++) {
		fat[i] = i*fat[i-1];
	}

	scanf("%d", &n);

	int total = 0, soma = 0;
	for(int i=8; i>0; i--) {
		while(soma+fat[i] <= n) {
			soma += fat[i];
			total++;
		}
	}

	printf("%d\n", total);
}
