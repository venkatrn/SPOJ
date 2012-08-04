#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int N,x,y;
  cin >> N;
  // Read Inputs
  while(N--)
  {
    cin >> x >> y;
    if(x<0 || y<0 || abs(floor(x)-x)!=0 || abs(floor(y)-y)!=0)
      cout << "No Number" << endl;

    if(x==y)
    {
      if(x%2==0)
        cout << 2*x << endl;
      else
        cout << 2*x - 1 << endl;
    }
    else if(y==x-2)
    {
      if(x%2==0)
        cout << 2*(x-1) << endl;
      else
        cout << 2*x - 3 << endl;
    }
    else
      cout << "No Number" << endl;
  }
  return 0;
}

