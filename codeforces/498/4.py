from sys import stdin, stdout

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
        if (s1[i] != s2[i]) and (s1[n-i-1] == s2[n-i-1]):
            cnt += 1
        elif (s1[i] == s2[i]) and (s1[n-i-1] != s2[n-i-1]):
            cnt += 1
        elif (s1[i] != s2[i]) and (s1[n-i-1] != s2[n-i-1]):
            if (s1[i] == s1[n-i-1]) and (s2[i] == s2[n-i-1]):
                continue
            elif (s1[i] == s2[n-i-1]) and (s2[i] == s1[n-i-1]):
                continue
            elif (s1[i] == s1[n-i-1]):
                if s2[i] != s2[n-i-1]:
                    cnt += 2
                else:
                    cnt += 1
            elif (s2[i] == s2[n-i-1]):
                cnt += 1
            elif (s1[n-i-1] == s2[i]) or (s1[i] == s2[n-i-1]):
                cnt += 1
            else:
                cnt += 2
    p(cnt)
if __name__ == "__main__":
    main()
