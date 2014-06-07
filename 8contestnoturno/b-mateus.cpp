#include <bits/stdc++.h>

using namespace std;

#define left (node * 2 + 1)
#define right (node * 2 + 2)
#define mid ((ini + fim)/2)
#define pb push_back
#define mp make_pair
typedef long long lint;

const int tmax = (int)1e5 + 100;

struct seg {
  lint sum;
  lint flag;
};

seg T[31][tmax * 4];
int ini_val[tmax];

void init(int pos, int node = 0, int ini = 0, int fim = tmax - 1) {
  if (ini == fim) {
    T[pos][node].sum = ((ini_val[ini] >> pos)&1);
    T[pos][node].flag = 0LL;
  } else {
    init(pos,left,ini,mid);
    init(pos,right,mid+1,fim);
    T[pos][node].sum = T[pos][left].sum + T[pos][right].sum;
  }
} 

void doLazy(int pos, int node, int ini, int fim) {
  
  if (T[pos][node].flag) {
    T[pos][node].sum = (fim - ini + 1) - T[pos][node].sum;
    if (ini != fim) {
      T[pos][left].flag ^= T[pos][node].flag;
      T[pos][right].flag ^= T[pos][node].flag;
    }
    T[pos][node].flag = 0LL;
  }
}

void update(int i, int j, int pos, int node = 0, int ini = 0, int fim = tmax - 1) {
  doLazy(pos, node, ini, fim);
  if (i > fim || j < ini || ini > fim || i > j) return;
  if (i <= ini && j >= fim) {
    T[pos][node].flag ^= 1;
    doLazy(pos, node, ini, fim);
    return;
  }
  update(i,j,pos,left,ini,mid);
  update(i,j,pos,right,mid+1,fim);
  T[pos][node].sum = T[pos][left].sum + T[pos][right].sum;
}

lint get(int i, int j, int pos, int node = 0, int ini = 0, int fim = tmax - 1) {
  doLazy(pos, node, ini, fim);
  if (i > fim || j < ini || ini > fim) return 0LL;
  if (i <= ini && j >= fim) return T[pos][node].sum;
  return get(i,j,pos,left,ini,mid) + get(i,j,pos,right,mid+1,fim);
}

void initSegTree() {
  for (int i = 0; i < 30; i++) {
    init(i);
  }
}

lint getRangeValue(int a, int b) {
  
  lint val = 0LL;
  lint pow_two = 1LL;
  for (int i = 0; i < 30; i++) {
    val += pow_two * get(a, b, i);
    pow_two <<= 1LL;
  }
  return val;
}

void updateRange(int a, int b, lint c) { 

  for (int i = 0; i < 30; i++) {
    if ((c>>i)&1)
      update(a,b,i);
  }
}

vector < int > graph[tmax];
int inicio[tmax], fim[tmax];
int contador;
int real_vals[tmax];

void dfs(int node, int parent) {
  inicio[node] = contador++;
  ini_val[contador - 1] = real_vals[node];
  for (int i = 0; i < graph[node].size(); i++) {
    int no = graph[node][i];
    if (no != parent)
      dfs(no, node);
  }
  fim[node] = contador - 1;
}

#define ROOT 0
char query[30];
int main() {
  int N,M;
  scanf("%d %d", &N, &M);
  memset(ini_val, 0, sizeof(ini_val));
  for (int i = 0; i < N; i++) {
    int ai;
    scanf("%d", &ini_val[i]);
    real_vals[i] = ini_val[i];
  }
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--,b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  contador = 0;
  dfs(ROOT, -1);
  initSegTree();
  for (int i = 0; i < M; i++) {
    scanf(" %s", query);
    if (query[0] == 'S') {
      int x;
      scanf("%d", &x);
      x--;
      printf("%lld\n", getRangeValue(inicio[x], fim[x]));
    } else {
      int x;
      lint valor;
      scanf("%d %lld", &x, &valor);
      x--;
      updateRange(inicio[x], fim[x], valor);
    }
  }
  return 0;
}
