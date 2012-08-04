#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
  long long N;
  // Read Inputs
  while(true)
  {
  scanf("%lld",&N);
  if(N==0)
    break; 
  printf("%lld\n",N*(N+1)*(2*N+1)/6);
  }
  return 0;
}

