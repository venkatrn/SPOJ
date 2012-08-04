#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;

int right_shift(int a)
{
  a = a/10;
  return a;
}
bool isSwappable(int n,int d1, int& d2)
{
  int a = n;
  for(int i=1;i<d1;i++)
    a = right_shift(a);
  int d1_val = a%10;
  a = n;
  int test_dig;
  for(int i=1;i<d1;i++)
  {
    test_dig = a%10;
    // printf("Test: %d\n",test_dig);
    if(test_dig>d1_val)
    {
      d2 = i;
      return true;
    }
    a = right_shift(a);
  }
  return false;
}

int swap(int n,int d1,int d2)
{
  int d1_val,d2_val;
  int a = n;
  for(int i=1;i<d1;i++)
    a = right_shift(a);
  d1_val = a%10;
  a = n;
  for(int i=1;i<d2;i++)
    a = right_shift(a);
  d2_val = a%10;
  int new_num = n - d1_val*(pow(10.0,d1-1)-pow(10.0,d2-1)) - d2_val*(pow(10.0,d2-1)-pow(10.0,d1-1));
  return new_num;

}
int main()
{
  int n;
  scanf("%d",&n);
  int a = n;
  int num_digits;
  while(a!=0)
  {
    num_digits++;
    a = right_shift(a);
  }
  // printf("Digits: %d\n",num_digits);
  int swapped_digit_pos;
  for(int digit = 2;digit<=num_digits;digit++)
  {
    if(isSwappable(n,digit,swapped_digit_pos))
    {
      int new_num = swap(n,digit,swapped_digit_pos);
      printf("%d\n",new_num);
      return 0;
    }
  }
  printf("Fail.Next num doesnt exist\n");
  return 0;
}

