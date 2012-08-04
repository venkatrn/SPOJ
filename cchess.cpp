#include<cstdio>
#include<vector>
#include<set>

using namespace std;

int transX[] = {1,2,1,2,-1,-2,-1,-2};
int transY[] = {2,1,-2,-1,2,1,-2,-1};

struct state_t
{
  int x;
  int y;
  int g;
  bool closed;
};

struct key_comp
{
  bool operator() (const state_t* s1,const state_t* s2) const
  {
    return s1->g < s2->g;
  }
};

state_t states[8*8];

void getSuccs(state_t* s,vector<state_t*>& succs, vector<int>& costs)
{
  int s_x = s->x, s_y = s->y, new_x, new_y;
  for(int i=0;i<8;i++)
  {
    new_x = s_x + transX[i];
    new_y = s_y + transY[i];
    if(new_x>=0 && new_y>=0 && new_x<8 && new_y<8)
    {
      succs.push_back(&states[new_y*8+new_x]);
      costs.push_back(new_x*s_x + new_y*s_y);
    }
  }
}

int main(void)
{
  int a,b,c,d;
  while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
  {
    if(!(a>=0 && b>=0 && c>=0 && d>=0 && a<8 && b<8 && c<8 && d<8))
    {
      printf("%d\n",-1);
      continue;
    }
    bool flag = 0;
    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
      {
        states[i*8+j].x = j;
        states[i*8+j].y = i;
        states[i*8+j].g = -1;
        states[i*8+j].closed = false;
      }

    multiset<state_t*,key_comp> queue;
    queue.clear();
    states[b*8+a].g = 0;
    queue.insert(&states[b*8+a]);

    while(!queue.empty())
    {
      state_t* s = *queue.begin();
      queue.erase(queue.begin());
      //if(s->closed == true)
       // printf("What ?!\n");
      s->closed = true;
      //printf("%d %d %d\n", s->x, s->y, s->g);
      if(s->x ==c && s->y == d)
      {
        printf("%d\n",s->g);
        flag = 1;
        break;
      }
      vector<state_t*> succs; 
      vector<int> costs;
      getSuccs(s,succs,costs);
      for(int i=0;i<succs.size();i++)
      {
        if(succs[i]->closed == false)
        if(succs[i]->g == -1 || s->g + costs[i] < succs[i]->g)
        {
          //multiset<state_t*>::iterator it = queue.find(succs[i]);
          multiset<state_t*>::iterator it = queue.begin();
          for(;it!=queue.end();it++)
          {
            if((*it)->x == succs[i]->x && (*it)->y == succs[i]->y)
              break;
          }
          if(it!=queue.end())
          {
            //if(succs[i] != *it) 
              //printf("Dumbo: %0x %0x\n", succs[i], *it);
            //printf("Size: %d\n", queue.size());
            //printf("Erasing %d %d %d %d\n", succs[i]->x,succs[i]->y, (*it)->x, (*it)->y);
            queue.erase(it);
            //printf("Size After: %d\n",queue.size());
          }
          succs[i]->g = s->g + costs[i];
          queue.insert(succs[i]);
        }
      }
    }
    if(flag == 0)
      printf("%d\n",-1);
  }
  return 0;
}
