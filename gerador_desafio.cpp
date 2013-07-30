#include <stdio.h>
#include <stdlib.h>

int tab[10][10];

char letra(int a);
void esvazia();

int main() {
  int n;
	int a, b;
	
	FILE * out = fopen("desafio.in", "w");
	
	// número de casos de teste
	int cont = 30;
	
	while(cont--) {
		n = (rand()%5)+6;
		
		fprintf(out, "%d\n", n);
		esvazia();
		
		for(int i=0; i<n; i++) {
			fprintf(out, "%c", letra( rand()%5 ));
			
			do {
				a = (rand()%8);
				b = (rand()%8);
			} while(tab[a][b] == 1);
			tab[a][b] = 1;
			a += 'a';
			b += 1;
			
			fprintf(out, "%c%d\n", a, b);
		}
		
		do {
			a = (rand()%8);
			b = (rand()%8);
		} while(tab[a][b] == 1);
		tab[a][b] = 1;
		a += 'a';
		b += 1;
		
		fprintf(out, "W%c%d\n", a, b);
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
