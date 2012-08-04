#include <cstdio>
#include <map>
using namespace std;
map<int,bool> node_list;

bool color(int u,int v)
{
  if(node_list.find(u)==node_list.end())
  {
    node_list[u] = 0;
  }
  if(node_list.find(v)==node_list.end())
  {
    node_list[v] = !(node_list[u]);
  }
  else
  {
    if(node_list[u]==node_list[v])
      return false;
  }
  return true;
}
int main()
{
int m,n,u,v;
scanf("%d %d",&n,&m);
for(int i=0;i<m;i++)
{
  scanf("%d %d",&u,&v);
  if(!color(u,v))
  {
    printf("NO");
    return 0;
  }
}
printf("YES");
 return 0;
}

