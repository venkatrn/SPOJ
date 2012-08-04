#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long LL;
string lab_str = "label";
string goto_str = "goto ";

void removeSpaces(string& s)
{
  if(s[0]!=' ')
    return;
  int pos = s.find_first_not_of(' ',0);
  if(pos!=string::npos&&pos!=0)
    s.erase(0,pos);
}

bool extractLabel(string s,string& label_name)
{
  int len = s.size();
  if(s[len-1]!=':')
    return false;
  label_name = s.substr(0,len-1);
  return true;
}
bool extractGoto(string s,string& label_name)
{
  int len = s.size();
  if(len<6 || !(s[0]=='g'&&s[1]=='o'&&s[2]=='t'&&s[3]=='o'&&s[4]==' '))
    return false;
  label_name = s.substr(5,len-6);
  return true;
}

int main()
{
  int T,N;
  scanf("%d\n",&T);
  for(int t=1;t<=T;t++)
  {
    map<string,int> line_nos;
    map<string,int> line_count;
    scanf("%d\n",&N);

    string line,label_name,goto_label;
    for(int i=0;i<N;i++)
    {
      line.clear();label_name.clear();goto_label.clear();
      char s[1010];
      fgets(s,1010,stdin);
      line = s;
      line.erase(line.length()-1,1);
      // printf("%s\n",line.c_str());
      removeSpaces(line);
      // printf("%s\n",line.c_str());
      if(extractLabel(line,label_name))
      {
        // printf("%s\n",label_name.c_str());
        line_nos[label_name] = i;
      }
      else if(extractGoto(line,goto_label))
      {
        // printf("%s\n",goto_label.c_str());
        if(line_count.find(goto_label)!=line_count.end())
          line_count[goto_label] = line_count[goto_label] + i - line_nos[goto_label] - 1;
        else
          line_count[goto_label] = i - line_nos[goto_label] - 1;
      }
    }
    LL sum=0;
    for(map<string,int>::iterator it=line_count.begin();it!=line_count.end();it++)
    {
      //   printf("%s %d\n",it->first.c_str(),it->second);
      sum += it->second;
    }
    printf("Scenario #%d: %lld\n",t,sum);
  }
  return 0;
}

