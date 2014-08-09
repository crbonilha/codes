#include <cstdio>
#include <cstring>
#include <set>

#define MOD 1000000007

using namespace std;

int n, first;
multiset<int>::iterator Si;

int main() {

    scanf("%d",&n);
    multiset<int> menores, maiores; // menores eh <=, irl
    int soma = 0;
    scanf("%d",&first);
    int med = first;
    menores.insert(first);
    soma = (soma + med)%MOD;
    for (int i=1;i<n;i++) {
        int t;
        scanf("%d",&t);
        if (t <= med) menores.insert(t);
        else maiores.insert(t);

        if (menores.size() == maiores.size() + 2) {
            Si = menores.end(); Si--;
            maiores.insert(*Si);
            menores.erase(Si);
        } else if (menores.size() < maiores.size()) {
            Si = maiores.begin();
            menores.insert(*Si);
            maiores.erase(Si);
        }
        Si = menores.end(); Si--;
        med = *Si;
        soma = (soma + med)%MOD;
    }
    printf("%d\n",soma);

    return 0;
}
