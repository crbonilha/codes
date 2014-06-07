#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int *v;
int main(void)
{
  int N;
  scanf("%d",&N);
  v=(int *)malloc(4*N);
  for(int i=0;i<N;i++)
    scanf("%d",&(v[i]));

  sort(v,v+N);
  int num;
  while(scanf("%d",&num)==1)
    printf("%s\n",binary_search(v,v+N,num)?"sim":"nao");

  return 0;
}
