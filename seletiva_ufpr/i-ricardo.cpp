#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <unistd.h>

#define ponteiro unsigned long long int

using namespace std;

ponteiro p1, p2, p3, ptr1, ptr2;
map<ponteiro,ponteiro> ant, prox;

int main() {

    int c=0;
    while(scanf("%llx %llx %llx",&p1,&p2,&p3) != EOF) {
        ponteiro eu = p1;
        ant[eu] = p2;
        prox[eu] = p3;
        if (c==0) ptr1 = eu;
        else if (c==1) ptr2 = eu;
        c++;
    }
    vector<ponteiro> removidos;
    ponteiro aux = ptr1;
    while (aux != ptr2) {
        removidos.push_back(aux);
        aux = prox[aux];
    }
    removidos.push_back(aux);

    aux = ptr1;
    while (ant.find(ant[aux]) != ant.end())
        aux = ant[aux];

    if (ant.find(prox[ptr2]) != ant.end()) ant[prox[ptr2]] = ant[ptr1];
    if (prox.find(ant[ptr1]) != prox.end())   prox[ant[ptr1]] = prox[ptr2];

    //agora aux eh o primeiro da lista
    while (prox.find(aux) != prox.end()) {
        printf("%llx %llx %llx\n",aux,ant[aux],prox[aux]);
        aux = prox[aux];
    }
    printf("\n");
    for (int i=0;i<(int)removidos.size();i++) {
        printf("%llx\n",removidos[i]);
    }

    return 0;
}
