#include<cstdio>
#include<map>
#define max(a,b) a>b ? a:b
using namespace std;
int main(void)
{
  int N,i,root;
  long long int c = 0, val = 0;
  map<int,long long int> list;
  scanf("%d",&N);
  while(N--)
  {
    int right = 0, left = 0;
    scanf("%d",&i);
    list[i] = 0;
    if(list.size()==1)
    { 
      root = i;
      printf("%d\n",0);
      continue;
    }
    map<int,long long int>::iterator it = list.find(i);
    map<int,long long int>::iterator it_copy = it;
    if(i>root)
    {
      if(++it != list.end())
        right = it->second;
      left = (--it_copy)->second;
    }
    else
    {
      right = (++it)->second;
      if(it_copy != list.begin())
        left = (--it_copy)->second;
    }
    val = max(right,left);
    val += 1;
    list[i] = val;
    c = c+val;
    printf("%lld\n",c);
  }
} 
