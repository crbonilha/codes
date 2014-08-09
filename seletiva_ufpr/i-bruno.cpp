#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
  unsigned long long ptr1,ptr2,tmp,ant,prox,inicio,fim;
  pair<unsigned long long, unsigned long long> ptr1_st, ptr2_st,tmp_st;

  map< unsigned long long, pair<unsigned long long,unsigned long long> > endmap;

  scanf("%llx %llx %llx",&ptr1, &ptr1_st.first,&ptr1_st.second);
  scanf("%llx %llx %llx",&ptr2, &ptr2_st.first,&ptr2_st.second);
  endmap[ptr1]=ptr1_st;
  endmap[ptr2]=ptr2_st;

  while(scanf("%llx %llx %llx",&tmp, &tmp_st.first, &tmp_st.second)==3)
  {
#ifdef __VERIFICA__
    if (endmap.find(tmp)!=endmap.end())
      fprintf(stderr,"Endereco de NO redefinido: %llx\n",tmp);
#endif
    endmap[tmp]=tmp_st;
  }

  //remover o caminho PTR1<->PTR2 da lista
  ant=ptr1_st.first;
  prox=ptr2_st.second;
  endmap[ant].second=prox;
  endmap[ptr2_st.second].first=ant;

  //encontrar o inicio da lista
  inicio=ant;
  while(endmap.find(endmap[inicio].first)!= endmap.end())
    inicio=endmap[inicio].first;

  //imprimir a lista com os elementos removidos
  tmp=inicio;
  while(endmap.find(tmp)!= endmap.end())
  {
    prox=endmap[tmp].second;
    printf("%llx %llx %llx\n",tmp, endmap[tmp].first,prox);
    tmp=prox;
  }

  printf("\n");
  tmp=ptr1;
  fim=endmap[ptr2].second;

  while(tmp!=fim)
  {
    prox=endmap[tmp].second;
    //printf("%llx %llx %llx\n",tmp, endmap[tmp].first,prox);
    printf("%llx\n",tmp);
    tmp=prox;
  }

  return 0;
}
