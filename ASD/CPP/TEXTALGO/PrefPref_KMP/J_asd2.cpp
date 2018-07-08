#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define N 20000001
#define INFTY 10000000
int KMP[N+1];
int pref[N+1];
vector< pair <int,int> > mantra;
vector<int> result;

void prefPref(int *pref, string word, int len)
{
    pref[0] = 0;
    pref[1] = 0;
    int i = 2;
    int t = 0;
    while(i<len)
    {
        if(t<0) t=0;
        while(word[1+t]==word[i+t])
        {
            t++;
            if((i+t) >= len)
                break;
        }
        pref[i] = t;
        int k=1;
        while(k<=t && pref[1+k] != pref[i]-k)
        {
            pref[i+k] = min(pref[1+k], pref[i]-k);
            k++;
            if((i+k) >= len)
                break;
        }
        t -= k;
        i += k;
    }
}

string revStr(string pat, string text)
{
  string data2;
  reverse(text.begin(), text.end());
  reverse(pat.begin(), pat.end());
  data2 = "@" + pat + "#" + text;
  return data2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int z, patLen, textLen;
    string pattern, data, text, data2;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        mantra.clear();
        result.clear();
        cin >> patLen >> pattern;
        cin >> textLen >> text;
        data = "@" + pattern + "#" + text;
        data2 = revStr(pattern, text);
        int len = data.size(), cnt=0;
        prefPref(KMP, data2, len);
        prefPref(pref, data, len);
        reverse(KMP+patLen+2, KMP+len);

              if(pref[patLen+2]==patLen)
              {
                mantra.push_back(make_pair(patLen+2, 1));
                mantra.push_back(make_pair(patLen+2+1, -1));
              }

        for(int i=patLen+2; i<len-1; i++)
        {
            if(KMP[i]+pref[i+1]>=patLen)
            {
               mantra.push_back(make_pair(i-KMP[i]+1, 1));
               mantra.push_back(make_pair(i+pref[i+1]-patLen+2, -1));
            }
        }
        sort(mantra.begin(), mantra.end());
        vector < pair<int,int> >::iterator it = mantra.begin();
        for(int i=patLen+2; i<len; i++)
        {
                if(it == mantra.end())
             break;
          if(i==(*it).first)
          {
            while((*it).first==i)
            {
              cnt+=(*it).second;
              ++it;
                        if(it == mantra.end())
              break;
            }
            if(cnt>0)
              result.push_back(i-patLen-2);
          }
          else
          {
            if(cnt>0)
              result.push_back(i-patLen-2);
          }
        }
        cout << result.size() << " ";
        for(int &e : result)
          cout << e << " ";
        cout << endl;
    }
    return 0;
}
