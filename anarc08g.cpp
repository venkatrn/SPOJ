#include <cstdio>
#include <vector>

using namespace std;
int main()
{
  int N,test_case=1;
  while(1){
    scanf("%d",&N);
    if(N==0)
      break;
    vector<int> row_sum, col_sum;
    row_sum.resize(N);
    col_sum.resize(N);
    int sum=0,final_amount=0;
    int t;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
      {
        scanf("%d",&t);
        row_sum[i] += t;
        col_sum[j] += t;
        sum += t;
      }
    
    for(int i=0;i<N;i++)
    { t = col_sum[i] - row_sum[i];
      if(t<0)
        final_amount += -t;
    }
    printf("%d. %d %d\n",test_case,sum,final_amount);
    test_case++;
  }
  return 0;
}

