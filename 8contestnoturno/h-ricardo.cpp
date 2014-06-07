// Uma reta cruza um retangulo se seus 4 vertices nao estao todos do mesmo lado
// da reta. Um retangulo esta atras de Link se nao existe uma projecao da
// posicao de link a dois vertices do retangulo tal que o vetor diretor esta
// dentro dela.

#include <cstdio>
#include <cstring>

using namespace std;

struct pvec {
    int x, y;
    pvec(int x=0, int y=0): x(x), y(y) {}
    pvec operator-(pvec p) { return pvec(x-p.x, y-p.y); }
    int dot(pvec p) { return x*p.x + y*p.y; }
    int cross(pvec p) { return x*p.y - y*p.x; } // < 0 se p ta a direita de this
};

int x1, y1, x2, y2, xd, yd, xl, yl, n;
char nome[21];

// considerando retangulo (x1,y1,x2,y2)
bool zelda() {
    pvec dir = pvec(xd,yd);
    pvec pl = pvec(xl, yl);
    pvec p[4];
    p[0] = pvec(x1,y1);
    p[1] = pvec(x1,y2);
    p[2] = pvec(x2,y1);
    p[3] = pvec(x2,y2);

    // ve os lados
    int lado = 0;
    for (int i=0;i<4;i++) {
        int tt = dir.cross(p[i] - pl);
        if (tt == 0) { lado=2; break; } // este ponto esta na reta
        if (lado == 0) {
            lado = (tt < 0 ? -1 : 1);
            continue;
        }
        if (lado * tt < 0) {    // sinal diferente
            lado = 2;
            break;
        }
    }
    if (lado != 2) return false;

    // ve as projecoes
    for (int i=0;i<4;i++)
        for (int j=i+1;j<4;j++) {
            pvec pr1 = p[i] - pl;
            pvec pr2 = p[j] - pl;
            // relativo a pr1
            int tt1 = pr1.cross(dir);
            int tt2 = pr1.cross(pr2);
            if ((tt1<0 and tt2>0) or (tt1>0 and tt2<0)) continue; // ta fora
            // relativo a pr2
            tt1 = pr2.cross(dir);
            tt2 = pr2.cross(pr1);
            if ((tt1<0 and tt2>0) or (tt1>0 and tt2<0)) continue; // ta fora

            if (tt1 == 0 or tt2 == 0) {
                if (pr1.cross(pr2) == 0) // pr1 e pr2 colineares?
                    if (pr1.cross(dir) != 0) continue; // ta fora
                // sao colineares. ta fora se o angulo eh 180, ie, cos < 0, ie,
                // dot < 0.
                // nao vai acontecer de pr1.dot < 0 e pr2.dot > 0.
                if (pr1.dot(dir) < 0) continue;
            }
            // ta dentro
            return true;
        }
    return false;
}

int main() {

    while(scanf("%d",&n) and n) {
        scanf("%d %d",&xl, &yl);
        scanf("%d %d",&xd, &yd);
        bool pr=true;
        for (int i=0;i<n;i++) {
            scanf("%s %d %d %d %d",nome, &x1,&y1,&x2,&y2);
            if (zelda()) {
                if (!pr) printf(" "); pr=false;
                printf("%s",nome);
            }
        }
        printf("\n");
    }

    return 0;
}
