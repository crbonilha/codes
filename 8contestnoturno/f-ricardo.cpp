// O grafo deve ser composto por componente conexas completas. Se for, a
// resposta eh o numero de componentes; se nao, impossivel.

#include <cstdio>
#include <cstring>

using namespace std;

char M[1024][1024];
int n;
int verts,ares;
bool visited[1024];

void dfs(int u) {
    visited[u] = true;
    verts++;
    for (int i=0;i<n;i++)
        if (M[u][i]=='1') {
            ares++;
            if (!visited[i])
                dfs(i);
        }
}

int main() {

    while(scanf("%d",&n) and n) {
        for (int i=0;i<n;i++)
            scanf("%s",M[i]);

        memset(visited,false,sizeof(visited));
        bool ok=true;
        int res=0;
        for (int i=0;i<n;i++) if (!visited[i]) {
            res++;
            verts=ares=0;
            dfs(i);
            if (ares != verts*(verts-1)) {
                ok=false;
                break;
            }
        }
        if (ok)
            printf("%d\n",res);
        else
            printf("impossivel\n");
    }

    return 0;
}
