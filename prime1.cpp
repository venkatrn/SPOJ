#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

bool isPrime(LL n)
{
  if(n==1)
    return false;
  if(n==2)
    return true;
  if(!bool(n&1))
    return false;
  LL ub = sqrt(n);
  for(LL i=3;i<=ub;i+=2)
    if(!(n%i))
      return false;
  return true;
}

int main()
{
  int t;
  LL m,n;
  scanf("%d",&t);
  vector<LL> all_primes;
  vector<bool> marked;
  LL num_pointer;

  while(t--)
  {
    all_primes.clear();
    marked.clear();
    scanf("%lld %lld",&m,&n);
    marked.resize(n-m+1);

    num_pointer = 2;
    LL ub = sqrt(n);
    while(num_pointer<=ub)
    {
      LL start = 2;
      if(num_pointer<m)
        start=ceil((double)m/(double)num_pointer);
      if(!isPrime(num_pointer))
      {
        num_pointer++;
        continue;
      }
      // printf("Num: %lld, prime: %d\n",num_pointer,isPrime(num_pointer));
      for(LL j=start*num_pointer;j<=n;j=num_pointer*start)
      {
        marked[j-m]=true;
        start+=1;
      }
      num_pointer++;
    }

    if(m==1)
      marked[0] = true;

    for(int i=0;i<marked.size();i++)
      if(!marked[i])
        printf("%lld\n",i+m);
    printf("\n");
  }
  return 0;
}
