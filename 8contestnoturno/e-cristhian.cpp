#include <stdio.h>
#include <string.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	
	char a[110], b[110];
	while(n--) {
		scanf("%s %s", a, b);
		
		int soma = (a[ strlen(a)-1 ]-'0') + (b[ strlen(b)-1 ]-'0');
		
		printf("%s\n", soma % 2 == 0 ? "Par" : "Impar");
	}
}
