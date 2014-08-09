#include <stdio.h>
#include <string.h>
#include <ctype.h>
const int MAXN = 1000;

int main() {
	int n, m, a, k, size;
	char s[MAXN+24];

	while(scanf("%d %d %d %d", &n, &m, &a, &k) != EOF and n) {
		scanf("%s", s);
		size = (int)strlen(s);

		for(int i=0; i<size; i++) {
			if(s[i] >= '0' and s[i] <= '9') k--;
			else if(s[i] == tolower(s[i])) m--;
			else if(s[i] == toupper(s[i])) a--;
		}
		
		//~ printf("%d %d %d\n", m, a, k);
		printf("%s\n", (size >= n and m <= 0 and a <= 0 and k <= 0) ?
			"Ok =/" : "Ufa :)");
	}
}
