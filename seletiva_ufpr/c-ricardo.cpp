#include <cstdio>
#include <cstring>

#define ll long long int

using namespace std;

ll n, m, C, F[1000010], a[5024], b[5024], PD[1024], c[5024], d[5024];

ll calc(ll u) {
    if (u==n) return 0;
    if (PD[u] != -1)
        return PD[u];

    ll r = 0x3f3f3f3f3f3f3f3fll;
    for (ll i=0;i<C;i++) if (a[i] <= u and u <= b[i]) {
        ll w = F[d[i]] - (c[i]?F[c[i]-1]:0);
        ll opc = w + calc(b[i]+1);
        if (opc < r)
            r = opc;
    }

    return PD[u] = r;
}

int main() {

    scanf("%lld %lld %lld",&n,&m, &C);
    for (ll i=0;i<m;i++) {
        ll t;
        scanf("%lld",&t);
        F[i] = (i?F[i-1]:0) + t;
    }
    for (ll i=0;i<C;i++) {
        scanf("%lld %lld %lld %lld",a+i,b+i, c+i, d+i);
        a[i]--; b[i]--;
        c[i]--; d[i]--;
    }
    memset(PD,0xff,sizeof(PD));
    ll resp = calc(0);
    if (resp == 0x3f3f3f3f3f3f3f3fll)
        printf("impossivel\n");
    else
        printf("%lld\n",resp);

    return 0;
}
