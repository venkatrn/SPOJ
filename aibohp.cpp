#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

#define max(a,b) a>b ? a:b
using namespace std;

int lcs(string s1, string s2)
{
  int m = s1.length(), n = s2.length();
  vector<vector<int> > c;
  c.resize(2);
  for(int i=0;i<2;i++)
    c[i].resize(n+1);
  for(int i=0;i<2;i++)
    c[i][0] = 0;
  for(int j=0;j<=n;j++)
    c[0][j] = 0;
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      if(s1[i-1]==s2[n-j])
        c[i&1][j] = c[1-(i&1)][j-1]+1;
      else
        c[i&1][j] = max(c[1-(i&1)][j],c[i&1][j-1]);
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
  string s,s_rev;
  scanf("%d",&t);
  while(t--)
  {
    char str[6100];
    s.clear();
    s_rev.clear();
    scanf("%s",str);
    s = str;
    s_rev = s;
   // reverse(s_rev.begin(),s_rev.end());
    printf("%d\n",(int)s.length()-lcs(s,s_rev));
  }
  return 0;
}

