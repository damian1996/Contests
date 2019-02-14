long pthFactor(long n, long p) {
    auto sqr = sqrt(n) + 1;
    if(p == 0 || p == 1) return p;
    int p_cnt = 1;
    stack<long> big_factors;
    big_factors.push(n);
    for(int i=2; i<sqr; ++i) {
        if(n%i==0) {
            if(p == (++p_cnt)) return i;
            auto bigger_factor = n/i;
            if(bigger_factor != i) big_factors.push(bigger_factor);
        }
    }
    while(!big_factors.empty()) {
        if(p == (++p_cnt)) return big_factors.top();
        big_factors.pop();
    }
    return 0;
}