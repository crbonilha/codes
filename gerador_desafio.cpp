#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int vazio = 0, preto = 1, branco = 2;
int tab[10][10];

char letra(int a);
void esvazia();
bool adjacentes(int a, int b);

int main() {
	int n;
	int a, b; // coordenadas das peças inimigas
	int rei_a, rei_b; // coordenadas do rei branco
	char inimigo; // caractere da peça inimiga
	
	FILE * out = fopen("desafio.in", "w");
	
	// número de casos de teste
	int cont = 30;
	
	while(cont--) {
		n = (rand()%5)+6;
		
		fprintf(out, "%d\n", n);
		memset(tab, vazio, sizeof(tab));
		
		rei_a = (rand()%8);
		rei_b = (rand()%8);
		tab[rei_a][rei_b] = branco;
		
		for(int i=0; i<n; i++) {
			inimigo = letra( rand()%5 );
			
			if(inimigo == 'W') { // rei preto
			
				do {
					a = (rand()%8);
					b = (rand()%8);
				} while(tab[a][b] && adjacentes(a, b));
				tab[a][b] = preto;
				a += 'a';
				b += 1;
			} else { // outras peças
			
				do {
					a = (rand()%8);
					b = (rand()%8);
				} while(tab[a][b]);
				tab[a][b] = preto;
				a += 'a';
				b += 1;
			}
			
			fprintf(out, "%c%c%d\n", inimigo, a, b);
		}
		
		rei_a += 'a';
		rei_b += 1;
		
		fprintf(out, "W%c%d\n", rei_a, rei_b);
	}
}

char letra(int a) {
	switch(a) {
	case 0:
		return 'P';
	case 1:
		return 'T';
	case 2:
		return 'B';
	case 3:
		return 'R';
	case 4:
		return 'W';
	}
	
	return 'P';
}

void esvazia() {
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			tab[i][j] = 0;
}

bool adjacentes(int a, int b) {
	for(int i=a-1; i<a+2; i++) {
		for(int j=b-1; j<b+2; j++) {
			if(tab[i][j] == branco) {
				return false;
			}
		}
	}
	
	return true;
}
