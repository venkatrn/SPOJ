#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
bool palindrome(long long int n)
{
  long long int rev = 0, orig = n;

  while(n)
  {
    rev = 10*rev + n%10;
    n = n/10;
  }
  return rev == orig;
}
void mirror(int& digits,long long int i,int n,long long int& newNum, long long int& inc, int& mid)
{
  stringstream ss;
  ss << i;
  string a = ss.str();
  ss.str("");
  string lh,rh;
  digits = a.length();
  if(digits&1)
  {
    inc = (long long int)pow((double)10,(digits-1)/2);
    lh = a.substr(0,(digits-1)/2) ;
    rh = lh;
    reverse(rh.begin(),rh.end());
    ss << lh + a[(digits-1)/2] + rh;  
    ss >> newNum; 
    mid = a[(digits-1)/2]-48;
  }
  else
  {
    inc = (long long int)(1.1*pow((double)10,digits/2));
    lh = a.substr(0,(digits)/2) ;
    rh = lh;
    reverse(rh.begin(),rh.end());
    ss << lh + rh;  
    ss >> newNum; 
    mid = a[(digits)/2]-48;
  }
  // printf("dig:%d newNum:%lld inc:%lld mid:%d\n",digits,newNum,inc,mid);
}
long long int roundUp(long long int i, int digits)
{
  int inc = pow(double(10),digits/2+1);
  long long int newNum = (i/inc+1)*inc;
  //printf("i:%lld, pre:%d, newNum:%lld\n",i,pre,newNum);
  return newNum;
}
long long int nextPalindrome(long long int i)
{
  int dig,n,mid;
  long long int inc, newNum;
  mirror(dig,i,n,newNum,inc,mid);
  if(newNum > i)
    return newNum;
  else
  {
    if(mid!=9)
      return newNum + inc;
  }
  return nextPalindrome(roundUp(i,dig));
}
int main()
{

  int t;
  long long int N,j;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld",&N);
    long long int c = 0;
    long long int i;
    if(N==1)
    {
      printf("%d\n",0);
      continue;
    }
    for(i=1;i<N/2;)
    {
      j = N - i;
      if(palindrome(j)==1)
      {
        c += 2;
        // printf("%lld %lld\n",i,j);
      }
      i = nextPalindrome(i);
      //       printf("%lld\n",i);
    }
    if(palindrome(N/2)==1)
    {
      j = N - N/2;
      if(palindrome(j)==1)
      {
        if(j==N/2)
          c += 1;
        else 
          c += 2;
        //  printf("%lld %lld\n",i,j);
      }
    }
    printf("%lld\n",c);
  }
  return 0;
}

