#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;

int count(char a[][3], char t)
{
  int c = 0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(a[i][j]==t)
        c++;
  return c;
}
bool win(char a[][3], char t)
{
  if(a[0][0]==t&&a[0][1]==t&&a[0][2]==t)
    return true;
  if(a[1][0]==t&&a[1][1]==t&&a[1][2]==t)
    return true;
  if(a[2][0]==t&&a[2][1]==t&&a[2][2]==t)
    return true;
  if(a[0][0]==t&&a[1][0]==t&&a[2][0]==t)
    return true;
  if(a[0][1]==t&&a[1][1]==t&&a[2][1]==t)
    return true;
  if(a[0][2]==t&&a[1][2]==t&&a[2][2]==t)
    return true;
  if(a[0][0]==t&&a[1][1]==t&&a[2][2]==t)
    return true;
  if(a[2][0]==t&&a[1][1]==t&&a[0][2]==t)
    return true;
  return false;
}
int main()
{
  int T;
  scanf("%d",&T);
  char a[3][3];
  char dummy;
  int countx,counto;
  for(int t=T;t>0;t--)
  {
  //  printf("%d\n",t);
    bool flag = 0;
    for(int j=0;j<3;j++)
      scanf("%s",a[j]);

/*    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        printf("%c",a[i][j]);
      printf("\n");
    }
    */

    countx = count(a,'X');
    counto = count(a,'O');
   // printf("countx: %d, counto: %d\n",countx,counto);
    if(countx<counto||countx-counto>1)
    {
      printf("no\n");
      flag = 1;
    }
    if(win(a,'X')&&countx==counto)
    {
      printf("no\n");
      flag = 1;
    }
    if(win(a,'O')&&countx>counto)
    {
      printf("no\n");
      flag = 1;
    }
    if(flag==0)
      printf("yes\n");
  //  printf("%d\n",t);
    if(t!=0)
      scanf("%c",&dummy);
  }
  return 0;
}

