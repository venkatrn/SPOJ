#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define max(a,b) a>b ? a:b
using namespace std;

int edist(string s1, string s2)
{
  int m = s1.length(), n = s2.length();
  vector<vector<int> > c;
  c.resize(2);
  for(int i=0;i<2;i++)
    c[i].resize(n+1);
  for(int i=0;i<2;i++)
    c[i][0] = i;
  for(int j=0;j<=n;j++)
    c[0][j] = j;
  for(int i=1;i<=m;i++)
  {
    c[i&1][0] = i;
   // c[1-(i&1)][0] = i-1;
    for(int j=1;j<=n;j++)
      if(s1[i-1]==s2[j-1])
        c[i&1][j] = c[1-(i&1)][j-1];
      else
      {
        c[i&1][j] = min(c[1-(i&1)][j]+1,c[i&1][j-1]+1);
        c[i&1][j] = min(c[i&1][j],c[1-(i&1)][j-1]+1);
      }
  }
  /*
  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
      printf("%d ",c[i][j]);
    printf("\n");
  }
  */
  return c[m&1][n];
}

int main()
{
  int t;
  string s1,s2;
  scanf("%d",&t);
  while(t--)
  {
    char str1[2010],str2[2010];
    s1.clear();
    s2.clear();
    scanf("%s",str1);
    s1 = str1;
    scanf("%s",str2);
    s2 = str2;
    printf("%d\n",edist(s1,s2));
  }
  return 0;
}

