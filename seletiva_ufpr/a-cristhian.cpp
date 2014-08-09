#include <stdio.h>
#include <vector>
using namespace std;

const int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, p;
pair<int, int> pa, pb;

int main() {
	int dira, dirb;
	
	scanf("%d %d %d", &n, &m, &p);
	pa.first = pa.second = 1;
	pb.first = n; pb.second = m;
	
	bool ok = false;
	for(int i=0; i<p; i++) {
		scanf("%d %d", &dira, &dirb);
		
		pa.first += dir[dira][0]; pa.second += dir[dira][1];
		pb.first += dir[dirb][0]; pb.second += dir[dirb][1];
		
		if(pa.first == pb.first and pa.second == pb.second) {
			printf("Encontraram-se na posicao (%d,%d) no passo %d\n", pa.first, pa.second, i+1);
			ok = true;
			break;
		} else if(pa.first < 1 or pa.first > n or pa.second < 1 or pa.second > m) {
			printf("PA saiu na posicao (%d,%d) no passo %d\n", pa.first, pa.second, i+1);
			ok = true;
			break;
		} else if(pb.first < 1 or pb.first > n or pb.second < 1 or pb.second > m) {
			printf("PB saiu na posicao (%d,%d) no passo %d\n", pb.first, pb.second, i+1);
			ok = true;
			break;
		}
	}
	
	if(!ok) printf("Nao se encontraram\n");
}
