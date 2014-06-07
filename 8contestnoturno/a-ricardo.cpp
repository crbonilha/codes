#include <cstdio>
#include <cstring>
#include <algorithm>

#define SIZE 1000010

using namespace std;

int n, virgens[SIZE], afazer[SIZE];
int prox[SIZE], ant[SIZE], lista;

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    while(scanf("%d",&n) and n) {
        for (int i=0;i<n;i++)
            scanf("%d",virgens+i);
        sort(virgens,virgens+n,cmp);
        int pQ=0;
        int tem = 0;
        // poe o primeiro
        prox[pQ] = ant[pQ] = -1;
        afazer[pQ] = virgens[0];
        lista = pQ;
        pQ++;
        tem++;
        int tempo;
        for (tempo=1;tempo<=n;tempo++) {
            for (int i=lista;i!=-1;i=prox[i]) {
                // faz
                if (afazer[i] > 0) {
                    afazer[i]--;
                    prox[pQ] = lista;
                    ant[pQ] = -1;
                    ant[lista] = pQ;
                    afazer[pQ] = virgens[tem];
                    lista = pQ;
                    pQ++;
                    tem++;
                } else {
                    // apaga i da lista
                    if (ant[i] != -1) prox[ ant[i] ] = prox[i];
                    if (prox[i] != -1) ant[ prox[i] ] = ant[i];
                    if (i == lista) lista = prox[i];
                }
                if (tem==n or lista==-1) goto final;
            }
//            printf("tempo %d feito\n",tempo);
        }
        final:;
        printf("%d\n",tem==n?tempo+1:-1);
    }

    return 0;
}
