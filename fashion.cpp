#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)

{
  int t,N,sum;
  scanf("%d",&t);
  while(t--)
  {
    vector<int> a,b;
    sum = 0;
    scanf("%d",&N);
    a.resize(N);
    b.resize(N);
    for(int i = 0;i<N;i++)
      scanf("%d",&a[i]);
    for(int i = 0;i<N;i++)
      scanf("%d",&b[i]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<N;i++)
      sum += a[i]*b[i];
    printf("%d\n",sum);
  }
  return 0;
}

