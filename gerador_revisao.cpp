#include <stdlib.h>
#include <stdio.h>

// numero de casos de teste gerados
const int CASOS = 30;

int main() {
	int d, size;
	char n[110];
	
	FILE * out = fopen("revisao.in", "w");
	
	for(int k=0; k<CASOS; k++) {
		d = (rand()%9)+1;
		fprintf(out, "%d ", d);
		
		size = (rand()%90)+10;
		for(int i=0; i<size; i++) {
			if(!(rand()%4))
				n[i] = d + '0';
			else
				n[i] = (rand()%9) + '0';
		}
		n[size] = '\0';
		
		fprintf(out, "%s\n", n);
	}
}
