#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int c_sum = 0, b_sum = 0, s_sum = 0;

struct vec_comp_c{
bool operator() (pair<int,int> p1,pair<int,int> p2) {

return (c_sum-p1.second)<(c_sum-p2.second);
}
}comp_c;

struct vec_comp_b{
bool operator() (pair<int,int> p1,pair<int,int> p2) {

return (b_sum-p1.second)<(b_sum-p2.second);
}
}comp_b;
struct vec_comp_s{
bool operator() (pair<int,int> p1,pair<int,int> p2) {

return (s_sum-p1.second)<(s_sum-p2.second);
}
}comp_s; 
int main()
{
  int N,i=0;
  int c2,s2,b2;
  int c_bag, s_bag, b_bag;
  vector<pair<int,int> > c,s,b;
  scanf("%d",&N);
  while(N--)
  {
    scanf("%d",&c2);
    scanf("%d",&s2);
    scanf("%d",&b2);
    c.push_back(make_pair(i,c2));
    s.push_back(make_pair(i,s2));
    b.push_back(make_pair(i,b2));
    c_sum += c2; b_sum += b2; s_sum += s2;
    i++;
  }
  sort(c.begin(),c.end(),comp_c);
  sort(s.begin(),s.end(),comp_s);
  sort(b.begin(),b.end(),comp_b);
  
  vector<string> perms;
  perms.push_back("000");perms.push_back("001");perms.push_back("002");perms.push_back("010");
  perms.push_back("011");perms.push_back("020");perms.push_back("021");perms.push_back("022");
  perms.push_back("100");perms.push_back("101");perms.push_back("102");perms.push_back("110");
  perms.push_back("111");perms.push_back("112");perms.push_back("121");perms.push_back("122");
  perms.push_back("200");perms.push_back("201");perms.push_back("210");perms.push_back("211");
  perms.push_back("220");perms.push_back("221");perms.push_back("222");perms.push_back("012");
  perms.push_back("120");perms.push_back("202");perms.push_back("212");
  string opt;
  int cost, min_cost = -1;
  for(int i = 0;i<perms.size();i++)
  {
  if(c[perms[i].at(0)-48].first == s[perms[i].at(1)-48].first||c[perms[i].at(0)-48].first == b[perms[i].at(2)-48].first||b[perms[i].at(2)-48].first == s[perms[i].at(1)-48].first)
  continue;


    cost = (c_sum+b_sum+s_sum)-(c[perms[i].at(0)-48].second+s[perms[i].at(1)-48].second+b[perms[i].at(2)-48].second);
    if(min_cost<0 || cost<min_cost)
    {
      min_cost = cost;
      opt = perms[i];
    }

  }
      c_bag = c[opt.at(0)-48].first;
      s_bag = s[opt.at(1)-48].first;
      b_bag = b[opt.at(2)-48].first;
      printf("%d\n%d\n%d\n",c_bag,s_bag,b_bag);
  return 0;
}

