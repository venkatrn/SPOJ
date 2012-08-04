#include <cstdio>
#include <queue>
#include <vector>
#include <set>
using namespace std;
bool color(int u,int v, vector<int>& node_list)
{
  if(node_list[u]==-1)
  {
    node_list[u] = 0;
  }
  if(node_list[v]==-1)
  {
    node_list[v] = 1-node_list[u];
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
  int m,u,v,n,k,t;
  scanf("%d",&t);
  for(k=1;k<=t;k++)
  {
    bool flag = 0;
    scanf("%d %d",&n,&m);
    vector<int> node_list(n,-1);
    vector<vector<int> > adj_list;
    queue<int> q;
    vector<bool> processed;
    set<int> rem_set;
    adj_list.resize(n);
    processed.resize(n);
    for(int i=0;i<n;i++)
      rem_set.insert(i);

    for(int i=0;i<m;i++)
    {
      scanf("%d %d",&u,&v);
      adj_list[u-1].push_back(v-1);
      adj_list[v-1].push_back(u-1);
    }
    q.push(0);
    while(q.size()!=0)
    {
    while(q.size()!=0)
    {
      u = q.front();
      q.pop();
      if(processed[u])
        continue;
      for(int i=0;i<adj_list[u].size();i++)
      {
        v = adj_list[u][i];
      if(!color(u,v,node_list))
      {
        printf("Scenario #%d:\nSuspicious bugs found!\n",k);
        flag = 1;
        break;
      }
      if(processed[v] == 0)
      q.push(v);
      }
      if(flag == 1)
        break;
      processed[u] = 1;
      rem_set.erase(rem_set.find(u));
    }
    if(flag == 1)
      break;
    /*for(int i=0;i<n;i++)
      if(processed[i]==0)
      {
        q.push(i);
        break;
      }*/
    if(rem_set.empty())
      break;
    set<int>::iterator it = rem_set.begin();
    if(it!=rem_set.end())
    {
      q.push(*it);
    }

    }
    if(flag == 0)
      printf("Scenario #%d:\nNo suspicious bugs found!\n",k);
  }
  return 0;
}

