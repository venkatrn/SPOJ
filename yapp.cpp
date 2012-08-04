#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
int t;
long long int N;
long long int ans;
scanf("%d",&t);
while(t--)
{
  scanf("%lld",&N);
  ans = 2;
  if(N==1)
  {
    printf("%d\n",1);
    continue;
  }
  N -= 2;
  long long int p = 2;
  while(N)
  {
    if(N&1)
    ans = (ans*p)%1000000007;
    p = (p*p)%1000000007;
    N>>=1;
  }

printf("%lld\n",ans);
}
  return 0;
}

