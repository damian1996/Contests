#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define N 100000
#define M 500000

struct variable
{
    char sign;
    int number;
};

struct variable val[M+1];
struct variable val2[M+1];
vector<variable> G[2*M+1];
vector<variable> G2[2*M+1];
int visited[2*M+1];
int sss[2*M+1];
stack<int> S;

void dfsFirst(int i)
{
    int child;
    visited[i] = true;
    vector<variable>::iterator it;
    for(it=G[i].begin(); it != G[i].end(); ++it)
    {
        child = (*it).number*2;
        if((*it).sign=='-')
        {
            if(!visited[child-1])
                dfsFirst(child-1);
        }
        else
        {
            if(!visited[child])
                dfsFirst(child);
        }
    }
    S.push(i);
}

void dfsSecond(int v, int counter)
{
    int child;
    visited[v] = true;
    sss[v] = counter;
    vector<variable>::iterator it;
    for(it=G2[v].begin(); it != G2[v].end(); ++it)
    {
        child = (*it).number*2;
        if((*it).sign=='-')
        {
            if(!visited[child-1])
                dfsSecond(child-1, counter);
        }
        else
        {
            if(!visited[child])
                dfsSecond(child, counter);
        }
    }
}

bool sat(int n)
{
    int counter = 1;

    for(int i=1; i<=2*n; i++)
    {
        if(!visited[i])
        {
            dfsFirst(i);
        }
    }

    for(int i=1; i<=2*n; i++)
        visited[i] = false;

    while(!S.empty())
    {
        int t = S.top();
        S.pop();
        if(!visited[t])
        {
            dfsSecond(t, counter);
            counter += 1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(sss[2*i-1]==sss[2*i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int z, n, m;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        cin >> n >> m;
        for(int i=1; i<=m; i++)
        {
          cin >> val[i].sign >> val[i].number >> val2[i].sign >> val2[i].number;
          struct variable tmp1;

          tmp1.sign = (val[i].sign=='-')?'+':'-';
          tmp1.number = val[i].number;

          if(tmp1.sign=='-')
              G[((tmp1.number)*2)-1].push_back(val2[i]);
          else
              G[(tmp1.number)*2].push_back(val2[i]);
          if(val2[i].sign=='-')
              G2[((val2[i].number)*2)-1].push_back(tmp1);
          else
              G2[(val2[i].number)*2].push_back(tmp1);

          tmp1.sign = (val2[i].sign=='-')?'+':'-';
          tmp1.number = val2[i].number;

          if(tmp1.sign=='-')
              G[((tmp1.number)*2)-1].push_back(val[i]);
          else
              G[(tmp1.number)*2].push_back(val[i]);
          if(val[i].sign=='-')
              G2[((val[i].number)*2)-1].push_back(tmp1);
          else
              G2[(val[i].number)*2].push_back(tmp1);
        }

        bool satisfiability = sat(n);
        if(satisfiability)
        {
            cout << "TAK" << endl;
            for(int i=1; i<=n; i++)
            {
                if(sss[2*i]<sss[2*i-1])
                    cout << "0 ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
        else
            cout << "NIE" << endl;

        for(int i=1; i<=2*n; i++)
        {
            G[i].clear();
            G2[i].clear();
            visited[i] = false;
        }
    }
    return 0;
}
