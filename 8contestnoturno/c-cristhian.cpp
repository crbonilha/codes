#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int v[140010];

bool bb(int a);

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+n);
	
	int a;
	while( scanf("%d", &a) != EOF ) {
		printf("%s\n", bb(a) ? "sim" : "nao");
	}
}

bool bb(int a) {
	int ini = 0, mid, fim = n;
	
	while(ini != fim) {
		mid = (ini+fim)/2;
		
		if(v[mid] == a) return true;
		else if(v[mid] < a) ini = mid+1;
		else fim = mid;
	}
	
	return false;
}
