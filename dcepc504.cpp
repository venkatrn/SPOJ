#include <cstdio>

int setBits(long long int v)
{
  int c;
  for(c=0;v;c++)
    v &= v-1;
  return c;
}
int main()
{
int N,t;
long long int K;
scanf("%d",&t);
while(t--)
{
  scanf("%d %lld",&N,&K);
  if(setBits(K-1)&1)
    printf("Female\n");
  else 
    printf("Male\n");
}
  return 0;
}

