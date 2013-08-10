#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	
	FILE * out = fopen("pareseimpares.in", "w");
	
	scanf("%d", &n);
	fprintf(out, "%d\n", n);
	
	while(n--) {
		fprintf(out, "%d\n", rand()%100000);
	}
}
