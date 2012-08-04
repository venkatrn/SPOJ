#include <cstdio>
#include <vector>
#include <cmath>
#define MOD 123456789
#define vv(t) vector<vector<t> >
using namespace std;
typedef long long LL;

void print_mat(vv(LL) x)
{
  for(int i=0;i<x.size();i++)
  {
    for(int j=0;j<x[0].size();j++)
      printf("%lld ",x[i][j]);
    printf("\n");
  }
    
}

void mat_mul(vv(LL) a, vv(LL) b, vv(LL)& c, int m,int k,int n)
{
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
      c[i][j] = 0;
      for(int t=0;t<k;t++)
        c[i][j] = (c[i][j] + (a[i][t]*b[t][j])%MOD)%MOD;
    }
 // print_mat(c);
}
void mat_copy(vv(LL)& a,vv(LL) b)
{
  for(int i=0;i<a.size();i++)
    for(int j=0;j<a[0].size();j++)
      a[i][j] = b[i][j];
}
int main()
{
  int t;
  LL N;
  int n = 4;
 // LL a[n][n],b[n][n],c[n][n];
 
  vv(LL) s0;
  s0.resize(n);
  for(int i=0;i<n;i++)
    s0[i].resize(1);
  s0[0][0] = 8;
  s0[1][0] = 3;
  s0[2][0] = 2;
  s0[3][0] = 1;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld",&N);

    if(N==1)
    {
      printf("3\n");
      continue;
    }
    else if(N==2)
    {
      printf("8\n");
      continue;
    }

  vector<vector<LL> > a,b,c;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for(int i=0;i<n;i++)
  {
    a[i].resize(n);
    b[i].resize(n);
    c[i].resize(n);
  }
  a[0][0] = a[0][1] = a[1][0] = a[2][2] = a[2][3] = a[3][3] = 1;
  a[0][2] = -4;
  a[0][3] = 9;
  a[1][1] = a[1][2] = a[1][3] = a[2][0] = a[2][1] = a[3][0] = a[3][1] = a[3][2] = 0;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        c[i][j] = 0;
    c[0][0] = c[1][1] = c[2][2] = c[3][3] = 1;
    N = N-2;

    while(N)
    {
      if(N%2==1)
      { mat_mul(c,a,b,n,n,n);
       mat_copy(c,b);
      }
        mat_mul(a,a,b,n,n,n);
      mat_copy(a,b);
        N>>=1;
    }
   // print_mat(c);

    mat_mul(c,s0,b,n,n,1);
    if(b[0][0]<0)
      b[0][0]+=MOD;
    printf("%lld\n",b[0][0]);
  }
  return 0;
}

