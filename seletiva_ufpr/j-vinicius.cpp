#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MOD 1000000007

int n,v,a,b;
priority_queue<int,vector<int>,greater<int> > phi;
priority_queue<int> plow;

int main(){

  scanf("%d",&n);
  int res = 0;
  while(scanf("%d",&v)==1){

    // both empty
    if(plow.size()==0 and phi.size()==0){
      plow.push(v);
      goto calc;
    }

    // hi empty
    if(phi.size()==0){
      plow.push(v);
      phi.push(plow.top());
      plow.pop();
      goto calc;
    }

    a = plow.top();
    b = phi.top();
    if(v<b){
      plow.push(v);
      if(plow.size()>phi.size()+1){
        phi.push(plow.top());
        plow.pop();
      }
    } else{
      phi.push(v);
      if(phi.size()>plow.size()+1){
        plow.push(phi.top());
        phi.pop();
      }
    }

    calc:;
    int mediana = (phi.size()>plow.size()) ? phi.top() : plow.top();
    res = (res+mediana)%MOD;
  }
  printf("%d\n",res);

  return 0;
}
