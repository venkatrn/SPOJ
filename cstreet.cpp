#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <utility>

using namespace std;
typedef long long LL;


int main()
{
int t,p,n,m,a,b,c;
scanf("%d",&t);
while(t--)
{

scanf("%d\n%d\n%d",&p,&n,&m);
multimap<int,pair<int,int> > G;
vector<int> tree_id;
tree_id.resize(n+1);
for(int i = 1;i<=n;i++)
  tree_id[i] = i;

LL total_weight = 0;

for(int i=0;i<m;i++)
{
  scanf("%d %d %d",&a,&b,&c);
  G.insert(make_pair(c,make_pair(a,b)));
}

multimap<int,pair<int,int> >::iterator it;
for(it = G.begin();it!=G.end();it++)
{
  if(tree_id[it->second.second]==tree_id[it->second.first])
    continue;
  int new_id = tree_id[it->second.first];
  int old_id = tree_id[it->second.second];
  for(int j=1;j<=n;j++)
    if(tree_id[j]==old_id)
      tree_id[j] = new_id;

  total_weight += it->first;
 // printf("%d %d\n",it->second.first,it->second.second);
}

printf("%lld\n",total_weight*p);
}
  return 0;
}

