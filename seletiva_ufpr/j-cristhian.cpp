#include <stdio.h>
#include <set>
using namespace std;
typedef long long int lli;
const lli MOD = 1000000007;

multiset<int> s;

int main() {
	int n, aux;
	multiset<int>::iterator it;
	int esq, dir;
	lli ans = 0;
	
	while( scanf("%d", &n) != EOF ) {
		scanf("%d", &aux);
		s.insert(aux);
		it = s.find(aux);
		esq = dir = 0;
		ans = (lli)aux;
		
		for(int i=1; i<n; i++) {
			scanf("%d", &aux);
			
			s.insert(aux);
			if(aux >= *it) {
				if(++dir - esq >= 2) {
					it++; dir--; esq++;
				}
			} else {
				if(i%2 == 0) {
					if(++esq - dir >= 2) {
						it--; dir++; esq--;
					}
				} else {
					if(++esq - dir >= 1) {
						it--; dir++; esq--;
					}
				}
			}
			
			//printf("dir=%d, esq=%d, +%d\n", dir, esq, *it);
			ans = (ans+(lli)*it)%MOD;
		}
		
		printf("%lld\n", ans);
	}
}
