#include <cstdio>
#include <set>
#include <vector>
using namespace std;

struct comp 
{
bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
{
  return p1.second <= p2.second;
}
};

int main()
{
int t,N,a,b;
scanf("%d",&t);
while(t--)
{
  set<pair<int,int>,comp> act;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d %d",&a,&b);
    act.insert(make_pair(a,b));
  }
  multiset<pair<int,int>,comp>::iterator it = act.begin();
  if(act.size()==0)
  {
    printf("%d\n",0);
    continue;
  }
  /*
  for(;it!=act.end();it++)
  {
    printf("%d %d\n",it->first,it->second);
  }
  it = act.begin();
  */
  int end_time = it->second; 
  int activities = 1;
  it++;
  for(;it!=act.end();it++)
    if(it->first>=end_time)
    {
     end_time =  it->second;
     activities++;
    }
  printf("%d\n",activities);
}

  return 0;
}

