// Complete the maxMoney function below.
int maxMoney(int n, long k) {
    double sol = (-1.0 + sqrt(1+8*k)) / 2.0;
    long long result = ((n+1LL)*n)/2LL;
    if(ceil(sol) == floor(sol)) {
        result = result - 1;
    }
    return result % 1000000007;
}

/*
# Complete the maxMoney function below.
def maxMoney(n, k):
    sol = (-1.0 + math.sqrt(1 + 8*k)) / 2.0
    result = ((n+1)*n)//2
    if math.ceil(sol) == math.floor(sol):
        result = result - 1
    return int(result) % 1000000007
*/



