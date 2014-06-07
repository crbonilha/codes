// ordenado da maior a menor forca, PD[atual][escolhidos]
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int n, F[1024], M[1024];
ii v[1024];
int PD[1024][1024];

// ordena por forca, maior primeiro
bool cmp(ii a, ii b) {
    return a > b;
}

int calc(int u, int escolhidos) {
    if (u==n) return 0;
    int &pd = PD[u][escolhidos];
    if (pd != 0x3f3f3f3f) return pd;
    // nao escolhe
    int opc1 = calc(u+1, escolhidos);
    // escolhe
    int opc2 = v[u].first + escolhidos*v[u].second + calc(u+1, escolhidos+1);

    return pd = max(opc1,opc2);

}

int main() {

    while(scanf("%d",&n) and n) {
        for (int i=0;i<n;i++) scanf("%d",F+i);
        for (int i=0;i<n;i++) scanf("%d",M+i);

        for (int i=0;i<n;i++) v[i] = ii(F[i], M[i]);
        sort(v,v+n,cmp);
        // PD
        memset(PD,0x3f,sizeof(PD));
        printf("%d\n",calc(0,0));
    }

    return 0;
}
