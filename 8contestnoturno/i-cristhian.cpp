#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int n;
ii f[1010];
int dp[1010][1010];

bool cmp(ii a, ii b) { return a.first > b.first; }
int funcao(int guerreiro, int cont);

int main() {
	while(scanf("%d", &n) and n) {
		for(int i=0; i<n; i++) {
			scanf("%d", &f[i].first);
		}
		for(int i=0; i<n; i++) {
			scanf("%d", &f[i].second);
		}
		sort(f, f+n, cmp);
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", funcao(0, 0));
	}
}

int funcao(int guerreiro, int cont) {
	if(guerreiro == n) {
		return 0;
	} else if(dp[guerreiro][cont] != -1) {
		return dp[guerreiro][cont];
	} else {
		return dp[guerreiro][cont] = max(
			funcao(guerreiro+1, cont+1)+f[guerreiro].first+cont*f[guerreiro].second,
			funcao(guerreiro+1, cont)
		);
	}
}
