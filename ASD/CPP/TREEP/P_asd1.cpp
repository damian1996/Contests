#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAXELM 100000

struct node
{
  int key;
  int priority;
  int left;
  int right;
  int size;
  bool rev;
};

struct node treap[MAXELM+1];

int revChld(int a, int b)
{
  if(a != -1) {
  if(treap[a].rev)
    treap[a].rev = false;
  else
    treap[a].rev = true;
  }
  if(b != -1) {
  if(treap[b].rev)
    treap[b].rev = false;
  else
    treap[b].rev = true;
  }
}
int updateSize(int a)
{
  if(treap[a].left==-1 && treap[a].right)
      treap[a].size = treap[treap[a].right].size + 1;
  else if(treap[a].right==-1 && treap[a].left)
      treap[a].size = treap[treap[a].left].size + 1;
  else if(treap[a].right==-1 && treap[a].left==-1)
      treap[a].size = 1;
  else
      treap[a].size = treap[treap[a].left].size + treap[treap[a].right].size + 1;
}
int merge(int u, int v)
{
    if(u==-1 && v!=-1)
      return v;
    if(u!=-1 && v==-1)
      return u;
    if(u==-1 || v==-1)
      return -1;

    if(treap[u].priority > treap[v].priority)
    {
      if(treap[u].rev)
      {
        swap(treap[u].right, treap[u].left);
        treap[u].rev = false;
        revChld(treap[u].right, treap[u].left);
      }
      //updateSize(treap[u]);
      treap[u].right = merge(treap[u].right, v); //v);
      updateSize(treap[u].key);
      return u;
    }
    else
    {
      if(treap[v].rev)
      {
        swap(treap[v].right, treap[v].left);
        treap[v].rev = false;
        revChld(treap[v].right, treap[v].left);
      }
      //updateSize(treap[u]);
      treap[v].left = merge(u, treap[v].left);
      updateSize(treap[v].key);
      return v;
    }
}

void split(int u, int k, int &rootL, int &rootR)
{
  if(treap[u].rev)
  {
    swap(treap[u].right, treap[u].left);
    treap[u].rev = false;
    revChld(treap[u].right, treap[u].left);
  }
    if(treap[u].left!=-1 && treap[treap[u].left].size >= k)
    {
      rootR = u;
      //updateSize(treap[u]);
      split(treap[u].left, k, rootL, treap[u].left);
      //treap[u].left = b;
      updateSize(treap[u].key);
      // a,u
    }
    else if(treap[u].right!=-1 && ((treap[u].left==-1 && k>1) || (treap[u].left!=-1 && treap[treap[u].left].size+1<k)))
    {
      rootL = u;
      //updateSize(treap[u]);
      split(treap[u].right, k-(treap[treap[u].left].size+1), treap[u].right, rootR);
      //rootL = treap[u];
      //treap[u].right = rootL;
      updateSize(treap[u].key);
      //(u,b);
    }
    else
    {
        rootL = treap[u].key;
        rootR = treap[u].right;
        treap[u].right = -1;
        updateSize(treap[u].key);
      return;
    }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  srand(32);
  int z, sets, n, q, v, u;
  cin >> sets;
  for(z=0; z<sets; z++)
  {
    int rootL, rootR;
    vector<int> priorities;
    cin >> n >> q;
    for(int i=1; i<=n; i++)
      priorities.push_back(i);
    random_shuffle( priorities.begin(), priorities.end() );
    vector<int>::iterator it = priorities.begin();
    for(int i=1; i<=n; i++)
    {
      treap[i].key = i;
      treap[i].left = -1;
      treap[i].right = -1;
      treap[i].rev = false;
      treap[i].size = 1;
    }
    treap[1].priority = *it;
    treap[1].size = 1;
    ++it;
    treap[2].priority = *it;
    treap[2].size = 1;
    ++it;
    int root = merge(1, 2);
    for(int i=3; i<=n; i++)
    {
      treap[i].priority = *it;
      root = merge(root, i);
      ++it;
    }

    for(int i=0; i<q; i++)
    {
      cin >> u >> v;
      int rootL = -1, rootR = -1, root2L = -1, root2R = -1;
      if(u!=1)
      {
        split(root, u-1, rootL, rootR);
        split(rootR, v-u+1, root2L, root2R);
      }
      else
          split(root, v-u+1, root2L, root2R);

      int tmp1 = treap[root2L].key , tmp2=treap[root2L].key;
      if(treap[root2L].rev)
      {
        swap(treap[root2L].right, treap[root2L].left);
        treap[root2L].rev = false;
        revChld(treap[root2L].right, treap[root2L].left);
      }
      while(treap[tmp1].left != -1)
      {
        tmp1 = treap[tmp1].left;
        if(treap[tmp1].rev)
        {
          swap(treap[tmp1].right, treap[tmp1].left);
          treap[tmp1].rev = false;
          revChld(treap[tmp1].right, treap[tmp1].left);
        }
      }
      while(treap[tmp2].right != -1)
      {
        tmp2 = treap[tmp2].right;
        if(treap[tmp2].rev)
        {
          swap(treap[tmp2].right, treap[tmp2].left);
          treap[tmp2].rev = false;
          revChld(treap[tmp2].right, treap[tmp2].left);
        }
      }
      cout << tmp1 << " " << tmp2 << endl;
      if(treap[root2L].rev)
        treap[root2L].rev = false;
      else
        treap[root2L].rev = true;

      int e = merge(root2L, root2R);
      root = merge(rootL, e);
    }
  }
  return 0;
}
