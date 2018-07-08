#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
//#include <tuple>

const int N = 5000;
struct shop
{
  int start;
  int end;
  int cost;
  bool operator< (const shop &c2)
  {
    if(cost < c2.cost)
      return true;
    else
      return false;
    /*else if(cost==c2.cost)
    {
      if(start < c2.start)
        return true;
      else if(start == c2.start)
      {
        if(end < c2.end)
          return true;
        else
          return false;
      }
      else
        return false;
    }
    else
      return false;
    */
  }
};
bool sortStart(const shop &c1, const shop &c2)
{
  if(c1.start < c2.start)
    return true;
  else if(c1.start==c2.start)
  {
    if(c1.end < c2.end)
      return true;
    /*else if(c1.end == c2.end)
    {
      if(c1.cost < c2.cost)
        return true;
      else
        return false;
    }*/
    else
      return false;
  }
  else
    return false;
}
typedef pair<int, int> myPair;

struct tupla
{
  int en;
  int begin;
  int id;
  bool operator< (const tupla &c2) const
  {
    if(en < c2.en)
      return true;
    else if(en==c2.en)
    {
      if(begin < c2.begin)
        return true;
      else if(begin == c2.begin)
      {
        if(id < c2.id)
          return true;
        else
          return false;
      }
      else
        return false;
    }
    else
      return false;
  }
};
/*struct mypairComp{
  bool operator()(myPair const& lhs, myPair const& rhs){
    if(lhs.first < rhs.first)
      return true;
    else if(lhs.first == rhs.first)
    {
      if(lhs.second < rhs.second)
        return true;
      else
        return false;
    }
    else
      return false;
  }
};*/

struct shop input[N+1];
vector<shop> result;
bool taskFour()
{
  vector<shop>::iterator itvv;
  sort(result.begin(), result.end(), sortStart);
  vector<shop>::iterator itv;
  set< tupla > s;
  set< tupla >::iterator it;
  set< tupla >::iterator ite;
  bool testSet = false;
  bool testEnd = false;
  int id = 0;
  itv = result.begin();
  int i = (*itv).start;
  while(1)
  {
    while(((*itv).start == i) && testSet==false)
    {
      if(itv != (--result.end()))
      {
        tupla elem = {(*itv).end, (*itv).start, id};
        s.insert(elem);
        ++itv;
        id++;
      }
      else
      {
        tupla elem = {(*itv).end, (*itv).start, id};
        s.insert(elem);
        testSet = true;
        break;
      }
    }
    if(!s.empty())
    {
      ite = s.begin();
      if((*ite).en <=i)
      {
        return false;
      }
      else
      {
        s.erase(ite);
        i++;
      }
    }
    else
    {
      if(testEnd==true)
        return true;
      if(itv != (--result.end()))
      {
        i = (*itv).start;
      }
      else
      {
        i = (*itv).start;
        testEnd =  true;
      }
    }
  }
}
int main()
{
   ios_base::sync_with_stdio(0);
   int z, n, m, v, w, spec;
   vector<shop>::iterator vec;
   cin >> z;
   for(int zz=0; zz<z; zz++)
   {
     result.clear();
     cin >> n;
     for(int i=0; i<n; i++)
     {
       cin >> input[i].start >> input[i].end >> input[i].cost;
     }
     sort(input, input+n);
     //for(int i=n-1; i>=0; i--)
        //cout << input[i].start << " " << input[i].end << " " << input[i].cost << endl;
     for(int i=n-1; i>=0; i--)
     {
       result.push_back(input[i]);
       if(taskFour())
       {
         continue;
       }
       else
       {
         for(vec = result.begin(); vec!=result.end(); ++vec)
           if(((*vec).start == input[i].start) && ((*vec).cost == input[i].cost) && ((*vec).end == input[i].end))
           {
             result.erase(vec);
             break;
           }
       }
     }
     vector<shop>::iterator itv;
     long long suma = 0;
     for(itv=result.begin(); itv!=result.end(); ++itv)
        suma += (*itv).cost;
     cout << suma << endl;
   }
   return 0;
}
