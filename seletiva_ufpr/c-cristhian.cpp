#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int lli;
const lli LIM = 1000000000000;

int n, m, c;
pair<pair<int, int>, pair<int, int> > cam[5010];
bool cmp(pair<pair<int, int>, pair<int, int> > a, pair<pair<int, int>, pair<int, int> > b) {
	if(a.first.first == b.first.first) {
		return a.first.second < b.first.second;
	} else {
		return a.first.first < b.first.first;
	}
}

lli dp[5010];
lli funcao(int a);

lli sum[1000010];
lli custo(int a);

int main() {
	int aux;
	
	while( scanf("%d %d %d", &n, &m, &c) != EOF ) {
		sum[0] = 0;
		for(int i=0; i<m; i++) {
			scanf("%d", &aux);
			sum[i+1] = sum[i]+(lli)aux;
		}
		for(int i=0; i<c; i++) {
			scanf("%d %d %d %d", &cam[i].first.first, &cam[i].first.second, &cam[i].second.first, &cam[i].second.second);
		}
		sort(cam, cam+c, cmp);
		
		lli ans = LIM;
		for(int i=0; i<c; i++) {
			if(cam[i].first.first == 1) {
				ans = min(ans, funcao(i));
			} else break;
		}
		
		if(ans == LIM) printf("impossivel\n");
		else printf("%lld\n", ans);
	}
}

lli funcao(int a) {
	if(dp[a]) return dp[a];
	else if(cam[a].first.second == n) return dp[a] = custo(a);
	
	lli ans = LIM;
	for(int i=a+1; i<c; i++) if(cam[i].first.first <= cam[a].first.second+1
	and cam[i].first.second >= cam[a].first.second+1) {
		ans = min(ans, funcao(i));
	}
	
	return dp[a] = ans + custo(a);
}

lli custo(int a) {
	return sum[ cam[a].second.second ]-sum[ cam[a].second.first-1 ];
}
