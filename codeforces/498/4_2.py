from sys import stdin, stdout
from collections import defaultdict

def p(s):
    stdout.write(str(s) + '\n')

def ps(s):
    stdout.write(s + '\n')

def r():
    return stdin.readline()

def swap1(s, i, j):
    lst  = list(s)
    lst[i], lst[j] = lst[j], lst[i]
    return ''.join(lst)

def swap2(s, i, j):
    return ''.join((s[:i], s[j], s[i+1:j], s[i], s[j+1:]))

def swap3(s1, s2, i):
    lst1 = list(s1)
    lst2 = list(s2)
    lst1[i], lst2[i] = lst2[i], lst1[i]
    return (''.join(lst1), ''.join(lst2))

#arr = [int(x) for x in stdin.readline().split()]
def main():
    n = int(r())
    s1 = r()
    s2 = r()
    cnt = 0
    k = (int(n/2)+1) if (n % 2 == 1) else int(n/2)
    for i in range(k):
        if i == n-i-1:
            if s1[i] != s2[i]:
                cnt += 1
                break
        d = defaultdict(lambda: 0)
        d[s1[i]] += 1
        d[s2[i]] += 1
        d[s1[n-i-1]] += 1
        d[s2[n-i-1]] += 1
        if len(d) == 4:
            cnt += 2
        elif len(d) == 3:
            cnt += 1 + (s1[i] == s1[n-i-1])
        elif len(d) == 2:
            cnt += (d[s1[i]] != 2)

    p(cnt)
if __name__ == "__main__":
    main()
