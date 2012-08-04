#include <cstdio>
#include <vector>
#include <cmath>
#define vv(t) vector<vector<t> >
using namespace std;
typedef long long LL;

LL MOD = 1000000000;

int n;
vv(LL) s0;
int B[11],C[11];
int K,N;


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

int fibo(int N)
{
  if(N<=K)
    return B[N-1];
  n = K;
  N = N-K;
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
 for(int i=0;i<K;i++)
   a[0][i] = C[i];
 for(int i=1;i<K;i++)
   a[i][i-1] = 1;
 // for(int i=0;i<n;i++)
   // for(int j=0;j<n;j++)
     // c[i][j] = 0;
  for(int i=0;i<K;i++)
     c[i][i] = 1;
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

  mat_mul(c,s0,b,n,n,1);
  // print_mat(b);
  if(b[0][0]<0)
    b[0][0]+=MOD;
  return b[0][0];
}

int main()
{

  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&K);
    for(int i=0;i<K;i++)
      scanf("%d",&B[i]);
    for(int i=0;i<K;i++)
      scanf("%d",&C[i]);
    scanf("%d",&N);
  n = K;
  s0.resize(n);
  for(int i=0;i<n;i++)
    s0[i].resize(1);
  for(int i=0;i<K;i++)
    s0[i][0] = B[K-i-1];

    int ans = fibo(N)%MOD;
    if(ans<0)
      ans += MOD;
    printf("%d\n",ans);
  }
  return 0;
}

