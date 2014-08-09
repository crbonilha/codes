#include <cstdio>
#include <cstring>

using namespace std;

int n, m, p;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {

    scanf("%d %d",&n,&m);
    scanf("%d",&p);
    int xa = 1, ya = 1;
    int xb = n, yb = m;
    for (int i=1;i<=p;i++) {
        int a, b;
        scanf("%d %d",&a,&b); a--; b--;
        xa += dx[a];
        ya += dy[a];
        xb += dx[b];
        yb += dy[b];
        if (xa==0 or xa == n+1 or ya==0 or ya==m+1) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n",xa,ya,i);
            return 0;
        }
        if (xb==0 or xb == n+1 or yb==0 or yb==m+1) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n",xb,yb,i);
            return 0;
        }
        if (xa==xb and ya==yb) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n",xa,ya,i);
            return 0;
        }
    }
    printf("Nao se encontraram\n");

    return 0;
}
