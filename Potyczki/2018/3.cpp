#include <cstdio>
typedef long long LL;
typedef double ld;
const LL mod = 1000000007;
const LL mod2 = 1086217963;
const LL p = 122949823;
const LL p2 = 104393321;

int main() {
    long long n;
    int c;
    auto xd = scanf("%lld\n", &n);
    c = getchar();
    long long hash1 = c, hash2 = c, hash1bis = c, hash2bis = c, pot = p, pot2 = p2;
    while(1) {
        c = getchar();
        if(c == EOF) break;
        hash1 = (hash1 + ((c) * pot) % mod) % mod;
        hash2 = ((c) + (hash2 * p) % mod) % mod;
        hash1bis = (hash1bis + ((c) * pot2) % mod2) % mod2;
        hash2bis = ((c) + (hash2bis * p2) % mod2) % mod2;
        pot = (pot*p) % mod;
        pot2 = (pot2*p2) % mod2;
    }
    if(hash1 == hash2 && hash1bis == hash2bis) printf("TAK\n");
    else printf("NIE\n");
    return 0;
}