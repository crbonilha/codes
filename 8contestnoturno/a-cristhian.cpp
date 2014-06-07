#include <stdio.h>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int n, v[100010];
	
	while(scanf("%d", &n) && n) {
		for(int i=0; i<n; i++) {
			scanf("%d", &v[i]);
		}
		sort(v, v+n, comp);
		
		int t = 0, disp = 1, i = 0, last = -1, new_last;
		while(i < n) {
			if(!disp) {
				t = -1; break;
			}
			
			i += disp;
			disp = 0;
			
			new_last = min(i-1, n-1);
			for(int j=min(i-1, n-1); j>last; j--) {
				if(v[j]-- > 0) {
					disp++;
					new_last = j-1;
				}
			}
			t++;
			last = new_last;
		}
		
		printf("%d\n", t);
	}
}
