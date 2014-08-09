#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map<string, int> M;
vector<int> v[30000];
char aux[32], aux2[32];
int par[30000];
bool visited[30000];

bool dfs(int u) {
    if (visited[u]) return false;
    visited[u]=true;
    for (int i=0;i<v[u].size();i++) {
        if (par[v[u][i]]!=-1 and par[v[u][i]]!=u) {
           if (dfs(par[v[u][i]])) {
                par[u] = v[u][i];
                par[v[u][i]] = u;
                return true;
           }
        } else if (par[v[u][i]] == -1) {
            par[u] = v[u][i];
            par[v[u][i]] = u;
            return true;
        }
    }
    return false;
}

int main() {

    for (int i=0;i<30000;i++)
        v[i].clear();

    int m=0;
    M.clear();
    for (char a='a';a<='z';a++)
    for (char b='a';b<='z';b++)
    for (char c='a';c<='z';c++) {
        sprintf(aux,"%c%c%c",a,b,c);
        string s = aux;
        M[s] = m++;
    }

    // vertices 0 a m sao esses ai em cima
    int n = m; // tamanho do grafo
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;i++) {
        int t;
        scanf("%d %s",&t, aux);
        n += t;
        for (int ia=0;aux[ia];ia++)
        for (int ib=ia+1;aux[ib];ib++)
        for (int ic=ib+1;aux[ic];ic++) {
            char a = aux[ia];
            char b = aux[ib];
            char c = aux[ic];
            sprintf(aux2,"%c%c%c",a,b,c);
            string s = aux2;
            int v2 = M[s];
            // faz aresta de [n-t,n-1] pra v2
            for (int j=n-t;j<n;j++) {
                v[j].push_back(v2);
                v[v2].push_back(j);
            }
        }
    }

    memset(par,0xff,sizeof(par));
    //1os deles , passo inicial gulosao
    int resp = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<v[i].size();j++)
            if (par[i] == -1 and par[v[i][j]] == -1) {
                par[i] = v[i][j];
                par[v[i][j]] = i;
                resp++;
                break;
            }
    //iku de verade!
    for (int i=0;i<n;i++) if (par[i] == -1) {
        memset(visited,false,n*sizeof(bool));
        if (dfs(i))
            resp++;
    }
    if (resp == n-m)
        printf("Possivel\n");
    else
        printf("Impossivel\n");

    return 0;
}
