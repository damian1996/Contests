import random as r
import string

N = 20000000 #r.randint(1, 20000000)
typ = r.randint(1,4)
s = []
if typ == 1 or typ == 3: # max palindromy
    if(typ == 1):
        print(0)
    if(typ == 3):
        print(N)
    for i in range(N//2):
        c = r.choice(string.ascii_letters[:10])
        s.append(c)
    for i in range(N//2):
        print(s[i], end = '')
    if(N % 2 == 1):
        print('c', end = '')
    for i in range(N//2):
        print(s[len(s) - 1 - i], end = '')
    print()

else: # max losowe
    if(typ == 2):
        print(0)
    if(typ == 4):
        print(N)
    for i in range(N):
        print(r.choice(string.ascii_letters[:10]), end = '')
    print()
#(ulimit -v 4096; ./program)
