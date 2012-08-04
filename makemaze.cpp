#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int transx[] = {1,0,-1,0};
int transy[] = {0,1,0,-1};
int main()
{
int t,m,n;
scanf("%d",&t);
while(t--)
{
  scanf("%d %d\n",&m,&n);
  vector<char> A;
  vector<bool> visited;
  stack<int> s;
  A.resize(m*n);
  visited.resize(m*n);
  
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
     // scanf("%c",&A[j*m+i]);
  A[j*m+i] = getchar();
    if(i!=m-1)
  getchar();
  }
  /*
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
      printf("%c ",A[j*m+i]);
    printf("\n");
  }*/
  
  int sx,sy,gx,gy;
  vector<int> startx,starty;
  for(int i=0;i<m;i++)
    if(A[i]=='.')
    {
      startx.push_back(i);
      starty.push_back(0);
    }
  if(n!=1)
  for(int i=0;i<m;i++)
    if(A[m*(n-1)+i]=='.')
    {
      startx.push_back(i);
      starty.push_back(n-1);
    }
  for(int i=1;i<n-1;i++)
    if(A[m*i]=='.')
    {
      startx.push_back(0);
      starty.push_back(i);
    }
  if(m!=1)
  for(int i=1;i<n-1;i++)
    if(A[m*i+(m-1)]=='.')
    {
      startx.push_back(m-1);
      starty.push_back(i);
    }

  if(startx.size()!=2 || starty.size()!=2)
  {
    printf("invalid\n");
    continue;
  }
  sx = startx[0];sy=starty[0];
  gx = startx[1];gy=starty[1];
  if(sx==gx && sy==gy)
  {
    printf("invalid\n");
    continue;
  }

  s.push(m*sy+sx);
  int st,xs,ys,xnew,ynew;
  bool flag = 0;
  while(s.size()!=0)
  {
    st = s.top();
    s.pop();
    xs = st%m;
    ys = st/m;
    visited[ys*m+xs] = 1;
    if(xs==gx && ys==gy)
    {
      printf("valid\n");
      flag = 1;
      break;
    }
    for(int k=0;k<4;k++)
    {
      xnew = xs+transx[k];
      ynew = ys+transy[k];
      if(xnew>=m||ynew>=n||xnew<0||ynew<0||A[m*ynew+xnew]=='#')
        continue;
      if(visited[ynew*m+xnew]==true)
        continue;
      s.push(m*ynew+xnew);
    }
  }
if(flag==0)
  printf("invalid\n");
}
  return 0;
}

