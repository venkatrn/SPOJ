#include <cstdio>
#include <cstring>

int main()
{
  char a[5001];
  int *p, len;
  while(1)
  {
    scanf("%s",a);
    if(a[0]=='0')
      break;
    len = strlen(a)+1;
    if(len==1)
    {
      printf("%d\n",1);
      continue;
    }
    p = new int[len];
    p[0] = 1;
    p[1] = 1;
    for(int k=2;k<len;k++)
    {
      if(a[k-1]=='0')
        p[k] = p[k-2];
      else if(a[k-2]>'0'&& (a[k-2]-48)*10+(a[k-1]-48)<=26)
        p[k] = p[k-1]+p[k-2];
      else
        p[k] = p[k-1];
    }

    printf("%d\n",p[len-1]);
  }
  return 0;
}

