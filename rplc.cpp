#include <cstdio>

using namespace std;
typedef long long LL;

int main()
{
int T;
int N,x[1000000];
int ptr;
scanf("%d",&T);
for(int t=1;t<=T;t++)
{
LL run_sum = 1;
scanf("%d",&N);
for(int i=0;i<N;i++)
  scanf("%d",&x[i]);
ptr = N-1;
while(ptr>=0&&x[ptr]>0)
  ptr--;

while(ptr>=0)
{
  run_sum -= x[ptr];
  if(run_sum<0)
    run_sum = 1;
  ptr--;
}

printf("Scenario #%d: %lld\n",t,run_sum);

}
  return 0;
}

