#include <stdio.h>
#include <map>
#include <vector>
typedef unsigned long long int lli;
using namespace std;

map<lli, pair<lli, lli> > list;

int main() {
	lli pt1, pt2, ptaux;
	pair<lli, lli> aux;
	
	scanf("%llx %llx %llx", &pt1, &aux.first, &aux.second);
	list[pt1] = aux;
	scanf("%llx %llx %llx", &pt2, &aux.first, &aux.second);
	list[pt2] = aux;
	
	while(scanf("%llx %llx %llx", &ptaux, &aux.first, &aux.second) != EOF) {
		list[ptaux] = aux;
	}
	
	list[ list[pt1].first ].second = list[pt2].second;
	list[ list[pt2].second ].first = list[pt1].first;
	
	ptaux = pt1;
	while(list.find( list[ptaux].first ) != list.end() and list[ptaux].first != 0) {
		ptaux = list[ptaux].first;
	}
	printf("%llx %llx %llx\n", ptaux, list[ptaux].first, list[ptaux].second);
	while(list.find( list[ptaux].second ) != list.end() and list[ptaux].second != 0) {
		ptaux = list[ptaux].second;
		printf("%llx %llx %llx\n", ptaux, list[ptaux].first, list[ptaux].second);
	}
	printf("\n");
	
	while(pt1 != pt2) {
		printf("%llx\n", pt1);
		pt1 = list[pt1].second;
	}
	printf("%llx\n", pt1);
}
