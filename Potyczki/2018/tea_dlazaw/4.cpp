#include <cstdio>
#include <vector>
#include <algorithm>
#include "message.h"
#include "teatr.h"
using namespace std;
typedef long long LL;

LL merge(int L, int mid, int R, vector<LL>& seq, vector<LL>& temp) {
    int i = L, j = mid, k = L;
    LL res = 0;
    while((i <= mid - 1) && j <= R) {
        if(seq[i] <= seq[j]) 
            temp[k++] = seq[i++];
        else {
            temp[k++] = seq[j++];
            res = res + (mid - i);
        }
    }
    while(i <= mid - 1) temp[k++] = seq[i++];
    while(j <= R) temp[k++] = seq[j++];
    for(i = L; i <= R; i++) seq[i] = temp[i];
    return res;
}

LL mergesort(int L, int R, vector<LL>& seq, vector<LL>& temp) {
    LL res = 0;
    if(R > L) {
        int mid = (R+L)/2;
        res = mergesort(L, mid, seq, temp);
        res += mergesort(mid+1, R, seq, temp);
        res += merge(L, mid+1, R, seq, temp);
    }
    return res;
}

LL computeMax(int n, int m, int t) {
    int maxi = 0;
    for(int i = m*t; (i < (m + 1) * t) && (i < n); i++) {
        maxi = max(maxi, GetElement(i));
    }
    if(m != 99) {
        PutInt(99, maxi);
        Send(99);        
    } else {
        for(int i=0; i<99; i++) {
            Receive(i);
            maxi = max(maxi, GetInt(i));
        }
    }
    return (long long) maxi;
}

int main() {
    LL n, m, t, non;
    n = GetN();
    t = (n+99)/100;
    m = MyNodeId();
    non = NumberOfNodes();
    LL maxi = computeMax(n, m, t);
    LL beg = m*n/non;
    LL end = (m+1)*n/non;
    
    if(maxi > 5LL) {
        if(m == 99) {
            vector<LL> temp(n);
            vector<LL> seq(n);
            for(int i=0; i<n; i++) {
                seq[i] = GetElement(i);
            }
            LL result = mergesort(0, n-1, seq, temp);
            printf("%lld\n", result);
        }
    } else {
        // algo z prefix sumami
        LL cnt[6] = {0, 0, 0, 0, 0, 0};
        LL fullCnt[6] = {0, 0, 0, 0, 0, 0};
        LL result_per_instance = 0LL;
        for(int i = beg; i < end; i++) {
            int el = GetElement(i);
            cnt[el]++;
            for(int j=el+1; j<=5; j++) {
                result_per_instance += cnt[j];
            }
        }
        for(int i=1; i<=5; i++) {
            fullCnt[i] = cnt[i];
            cnt[i] = cnt[i] + cnt[i-1];
        }
        
        if(m != 99) {
            for(int i=1; i<=5; i++) PutLL(99, cnt[i]);
            PutLL(99, result_per_instance);
            Send(99);
        } else {    
            for(int i=98; i>=0; i--) {
                Receive(i);
                LL received[6] = {0, 0, 0, 0, 0, 0};
                for(int j=1; j<=5; j++) received[j] = GetLL(i);
                for(int j=1; j<=4; j++) {
                    result_per_instance += (fullCnt[j]*(received[5] - received[j]));
                }
                for(int j=1; j<=5; j++) {
                    fullCnt[j] += (received[j] - received[j-1]);
                }                
                result_per_instance += GetLL(i);
            }
            printf("%lld\n", result_per_instance);
        }
    }
    return 0;
}
