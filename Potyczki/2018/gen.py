import random as r

N = 1000000
print(N)
for i in range(N-1):
    number = r.randint(1, N-2)
    print("%i" % number, end = " ")
number = r.randint(1, 5000)
print(number)