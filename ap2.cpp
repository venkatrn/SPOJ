#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;

int main()
{
int t;
LL x0,x1,s;
scanf("%d",&t);
while(t--)
{
scanf("%lld %lld %lld",&x0,&x1,&s);
LL n = (2*s)/(x0+x1);
LL d = (x1-x0)/(n-5);
LL a = x0-2*d;

printf("%lld\n",n);
printf("%lld",a);
for(LL i=2;i<=n;i++)
  printf(" %lld",a+(i-1)*d);
printf("\n");
}
  return 0;
}

