#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
  unsigned long long ptr1,ptr2,tmp;
  pair<unsigned long long, unsigned long long> ptr1_st, ptr2_st,tmp_st;

  map< unsigned long long, pair<unsigned long long,unsigned long long> > endmap;

  scanf("%llx %llx %llx",&ptr1, &ptr1_st.first,&ptr1_st.second);
  scanf("%llx %llx %llx",&ptr2, &ptr2_st.first,&ptr2_st.second);
  endmap[ptr1]=ptr1_st;
  endmap[ptr2]=ptr2_st;

  while(scanf("%llx %llx %llx",&tmp, &tmp_st.first, &tmp_st.second)==3)
    endmap[tmp]=tmp_st;

  bool sana=true;
  tmp=ptr1;
  tmp_st=ptr1_st;
  while(tmp!=ptr2)
  {
    pair<unsigned long long,unsigned long long> next_st = endmap[tmp_st.second];
    if(next_st.first== tmp)
    {
      tmp=tmp_st.second;
      tmp_st=next_st;
    }
    else
    {
      sana=false;
      break;
    }
  }
  printf("%s\n", sana?"sana":"insana");
  return 0;
}
