#include <cstdio>

int main()
{
int a,b,c,d,e,f;
int num_correct, score;
int i = 1;
while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)!=EOF)
{
  num_correct = 0;
  score = 0;
  if(a!=0)
  {
  num_correct ++; 
  score += a + (d-1)*1200;
  }
  if(b!=0)
  {
  num_correct ++; 
  score += b + (e-1)*1200;
  }
  if(c!=0)
  {
  num_correct ++; 
  score += c + (f-1)*1200;
  }
  printf("team %d: %d, %d\n",i++,num_correct,score);
}

  return 0;
}

