#include <cstdio>
#include <map>
using namespace std;

map<long long int,long long int> memorize;
long long int coins(long long int N)
{
  if(memorize.find(N)!=memorize.end())
    return memorize[N];

    long long int sum = 0;
      if(N/4+N/3+N/2>N)
      {
        sum += coins(N/4);
        sum += coins(N/3);
        sum += coins(N/2);
      }
      else
      {
        sum += N;
      }
      memorize[N] = sum;
      return sum;
}
int main(void)

{
 long long int N,sum;
  while(scanf("%lld",&N)!=EOF)
  {
    if(N==EOF)
      break;
    sum = coins(N);
  printf("%lld\n",sum);
  }
  return 0;
}

