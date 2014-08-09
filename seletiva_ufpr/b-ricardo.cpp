#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define EPS 1e-7

using namespace std;

inline int cmpf(double a, double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

int n;
double vs, vc, xs, ys, x[50050], y[50050];

inline double dist(double x1, double y1, double x2, double y2) {
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}

void poscidadao(double t, double &xc, double &yc) {
    for (int i=0;i+1<n;i++) {
        // termina no meio dessa aresta?
        double eu = dist(x[i],y[i],x[i+1],y[i+1])/vc;
        if ( cmpf( t, eu ) <= 0) {
            double porcento = t/eu;
            double quero = dist(x[i],y[i],x[i+1],y[i+1])*porcento;
            // versor
            double xx = x[i+1] - x[i];
            double yy = y[i+1] - y[i];
            double modulo = dist(0,0,xx,yy);
            xx = xx/modulo;
            yy = yy/modulo;
            // redimensiona
            xx = xx*quero;
            yy = yy*quero;

            //retorna
            xc = x[i] + xx;
            yc = y[i] + yy;
            return;
        } else
            t -= eu;
    }
    assert(1==2);
}

int main() {

    while(scanf("%d",&n) != EOF) {
        scanf("%lf %lf",&xs,&ys);
        for (int i=0;i<n;i++)
            scanf("%lf %lf",x+i,y+i);
        scanf("%lf %lf",&vs,&vc);

        // maxcidadao = tempo q o cidadao leva pra percorrer toda a fila
        double maxcidadao = 0.0;
        for (int i=0;i+1<n;i++)
            maxcidadao += dist(x[i],y[i],x[i+1],y[i+1])/vc;

        bool da=false;
        double ini=0.0, fim = maxcidadao;
        for (int tt=0;tt<128;tt++) {
            double t = (ini+fim)/2.0;
            double xc, yc;
            // acha cidadao
            poscidadao(t, xc, yc);
            // acha tempo shrek
            double shrek = dist(xs,ys,xc,yc);
            shrek = shrek/vs;
            if (cmpf(shrek,t)<=0) {
                da=true;
                fim = t;
            } else
                ini = t;
        }
        if (!da) printf("impossivel\n");
        else printf("%.2lf\n",ini);
    }

    return 0;
}
