#include <cstdio>
#include <cstring>
#include <vector>

#define min(a, b) (a < b ? a : b)

using namespace std;

typedef pair<int, int> ii;

int n, m, k, nadj[1000], gratis;
ii adj[1000][1000];
int vertmoeda[12]; // vertmoeda[i] = vertice da moeda i
int PDpramoeda[1000][12];
int PDpra0[1000];
int PD[15][3][(1<<12)];

// distancia do vertice u ao vertice que tem a moeda, sem ->0
// pode retornar 0x3f
int distpramoeda(int u, int moeda) {
    if (u == vertmoeda[ moeda ] ) return 0;
    int &pd = PDpramoeda[u][moeda];
    if (pd != -1) return pd;
    int best = 0x3f3f3f3f;
    for (int i=0;i<nadj[u];i++) if (adj[u][i].first != 0) {
        int t = adj[u][i].second + distpramoeda(adj[u][i].first, moeda);
        best = min(best, t);
    }
    return pd = best;
}

// distancia do vertice u ao vertice 0, com -> 0
int distpra0(int u) {
    if (u==0) return 0;
    int &pd = PDpra0[u];
    if (pd != -1) return pd;
    int best = 0x3f3f3f3f;
    for (int i=0;i<nadj[u];i++) {
        int t = adj[u][i].second + distpra0(adj[u][i].first);
        best = min(best, t);
    }
    return pd = best;
}

// to no vertice que tem a moeda dada. se moeda=k, to em 0.
int calc(int moeda, int volta, int bm) {
    if (volta==3) {
        // 3 voltas
        if (bm == ((1<<k)-1)) return 0;
        return 0x3f3f3f3f;
    }
    int &pd = PD[moeda][volta][bm];
    if (pd != -1) return pd;
    int best = 0x3f3f3f3f;
    // opc1. se to em 0, da uma volta 'gratis'
    if (moeda==k) {
        int opc = gratis + calc(k, volta+1, bm);
        best = min(best, opc);
    }
    // opc2, se nao to em 0, completa a volta e vai pra 0
    if (moeda!=k) {
        int opc = distpra0(vertmoeda[moeda]) + calc(k, volta+1, bm);
        best = min(best, opc);
    }

    // opc3. pega alguma moeda faltando
    for (int i=0;i<k;i++) if (!(bm&(1<<i))) {
        int u = (moeda==k? 0 : vertmoeda[moeda]);
        int opc  = distpramoeda(u, i) + calc(i, volta, bm^(1<<i));
        best = min(best, opc);
    }

    return pd = best;
}

int main() {

    while(scanf("%d %d %d",&n,&m,&k) != EOF) {
        memset(nadj,0,n*sizeof(int));
        for (int i=0;i<m;i++) {
            int a, b, w;
            scanf("%d %d %d",&a,&b, &w); a--; b--;
            adj[a][nadj[a]++] = ii(b,w);
        }
        for (int i=0;i<k;i++) {
            scanf("%d",vertmoeda+i);
            vertmoeda[i]--;
        }
        // zera PDs por demanda
        memset(PDpramoeda,0xff,sizeof(PDpramoeda));
        memset(PDpra0,0xff,sizeof(PDpra0));

        // calcula o valor da volta graits
        gratis = 0x3f3f3f3f;
        for (int i=0;i<nadj[0];i++) {
            int t = adj[0][i].second + distpra0(adj[0][i].first);
            gratis = min(gratis, t);
        }


        // PD "de verdade"
        memset(PD,0xff,sizeof(PD));
        int resp = calc(k, 0, 0);
        if (resp == 0x3f3f3f3f)
            printf("impossivel\n");
        else
            printf("%d\n",resp);
    }


    return 0;
}
