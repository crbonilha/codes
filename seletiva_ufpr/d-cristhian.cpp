#include <stdio.h>
const int MAXN = 100;

char a[MAXN+10], b[MAXN+10];

int main() {
	int n, pa, pb;
	int ans;
	
	while(scanf("%d", &n) != EOF and n) {
		scanf("%s %s", a, b);
		
		pa = pb = ans = 0;
		for(int i=0; i<n; i++) {
			pa += (a[i] == 'o');
			if(pb+(n-i) < pa or pa+(n-i-1) < pb) {
				ans = i*2+1;
				break;
			}
			
			pb += (b[i] == 'o');
			if(pb+(n-i-1) < pa or pa+(n-i-1) < pb) {
				ans = i*2+2;
				break;
			}
		}
		
		if(ans) printf("%d\n", ans);
		else printf("Empate\n");
	}
}
