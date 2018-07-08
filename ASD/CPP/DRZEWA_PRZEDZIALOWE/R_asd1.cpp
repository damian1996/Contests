#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 262144
#define INF 10000001
struct card
{
    int up, down;
};
struct node
{
    bool val00, val01, val10, val11;
    int left, right;
};
struct card cards[MAX+1];
struct node tree[2*MAX];
void set_bools(int i, int l, int r)
{
    bool tmp1, tmp2, tmp3, tmp4;
    tmp1 = (tree[2*i].val00 && tree[2*i+1].val00 && cards[l].up<=cards[r].up);
    tmp2 = (tree[2*i].val01 && tree[2*i+1].val00 && cards[l].down<=cards[r].up);
    tmp3 = (tree[2*i].val00 && tree[2*i+1].val10 && cards[l].up<=cards[r].down);
    tmp4 = (tree[2*i].val01 && tree[2*i+1].val10 && cards[l].down<=cards[r].down);
    tree[i].val00 = (tmp1 || tmp2 || tmp3 || tmp4);

    tmp1 = (tree[2*i].val00 && tree[2*i+1].val01 && cards[l].up<=cards[r].up);
    tmp2 = (tree[2*i].val01 && tree[2*i+1].val01 && cards[l].down<=cards[r].up);
    tmp3 = (tree[2*i].val00 && tree[2*i+1].val11 && cards[l].up<=cards[r].down);
    tmp4 = (tree[2*i].val01 && tree[2*i+1].val11 && cards[l].down<=cards[r].down);
    tree[i].val01 = (tmp1 || tmp2 || tmp3 || tmp4);

    tmp1 = (tree[2*i].val10 && tree[2*i+1].val00 && cards[l].up<=cards[r].up);
    tmp2 = (tree[2*i].val11 && tree[2*i+1].val00 && cards[l].down<=cards[r].up);
    tmp3 = (tree[2*i].val10 && tree[2*i+1].val10 && cards[l].up<=cards[r].down);
    tmp4 = (tree[2*i].val11 && tree[2*i+1].val10 && cards[l].down<=cards[r].down);
    tree[i].val10 = (tmp1 || tmp2 || tmp3 || tmp4);

    tmp1 = (tree[2*i].val10 && tree[2*i+1].val01 && cards[l].up<=cards[r].up);
    tmp2 = (tree[2*i].val11 && tree[2*i+1].val01 && cards[l].down<=cards[r].up);
    tmp3 = (tree[2*i].val10 && tree[2*i+1].val11 && cards[l].up<=cards[r].down);
    tmp4 = (tree[2*i].val11 && tree[2*i+1].val11 && cards[l].down<=cards[r].down);
    tree[i].val11 = (tmp1 || tmp2 || tmp3 || tmp4);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    for(int i=1; i<=MAX; i++)
    {
        cards[i].down = INF;
        cards[i].up = INF;
    }
    int z, m, sets, n, power, swap1, swap2;
    int pot[19];
    pot[0] = 1;
    for(int i=1; i<19; i++)
    {
        pot[i] = pot[i-1]*2;
    }
    cin >> sets;
    for(z=0; z<sets; z++)
    {
        cin >> n;
        for(int i=1; i<19; i++)
        {
            if(n>pot[i-1] && n<=pot[i])
            {
                power = pot[i];
                break;
            }
        }
        for(int i=1; i<=power; i++)
        {
          if(i<=n)
            cin >> cards[i].up >> cards[i].down;
          tree[i+power-1].val00 = true;
          tree[i+power-1].val01 = false;
          tree[i+power-1].val10 = false;
          tree[i+power-1].val11 = true;
          tree[i+power-1].left = i;
          tree[i+power-1].right = i;
        }
        for(int k=power-1; k>0; --k)
        {
            tree[k].left = tree[2*k].left;
            tree[k].right = tree[2*k+1].right;
            int l = (tree[k].right+tree[k].left-1)/2;
            set_bools(k, l, l+1);
        }
        cin >> m;
        for(int c=0; c<m; c++)
        {
            cin >> swap1 >> swap2;
            int temp1 = cards[swap1].up, temp2 = cards[swap1].down;
            cards[swap1].up = cards[swap2].up;
            cards[swap1].down = cards[swap2].down;
            int x = (swap1+power-1)/2;
            while(x>0)
            {
                int temp = (tree[x].left+tree[x].right-1)/2;
                set_bools(x, temp, temp+1);
                x = x/2;
            }
            cards[swap2].up = temp1;
            cards[swap2].down = temp2;
            x = (swap2+power-1)/2;
            while(x>0)
            {
                int temp = (tree[x].left+tree[x].right-1)/2;
                set_bools(x, temp, temp+1);
                x = x/2;
            }
            if(tree[1].val00 || tree[1].val01 || tree[1].val10 || tree[1].val11)
                cout << "TAK" << endl;
            else cout << "NIE" << endl;
        }
        for(int i=1; i<=power; i++)
        {
            cards[i].up = INF;
            cards[i].down = INF;
        }
    }
    return 0;
}
