def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def lcm(a, b):
    return a // gcd(a, b) * b

def LCM(factors, mask):
    ret = 1
    
    for i in range(0, len(factors)):
        if (1 << i) & mask != 0:
            ret = lcm(ret, factors[i])

    return ret

def prime_factorize(n):
    ret = []
    
    i = 2
    x = n
    
    while (i <= x) and (i * i <= n):
        if x % i == 0:
            x = x // i
            if len(ret) == 0 or ret[-1] != i:
                ret.append(i)
        else:
            i += 1
    
    if x > 1:
        ret.append(x)
    
    return ret

def count_multiple(a, b, x):
    return b // x - (a-1) // x

def count_one(mask):
    ret = 0
    
    while mask > 0:
        ret += mask % 2
        mask = mask // 2
    
    return ret

def count_coprime(a, b, n):
    ret = 0
    factors = prime_factorize(n)
    
    for i in range(0, 1 << len(factors)):
        multiples = count_multiple(a, b, LCM(factors, i))
        if count_one(i) % 2 == 0:
            ret += multiples
        else:
            ret -= multiples
    
    return ret
    
T = int(input())

for i in range(1, T+1):
    A, B, N = map(int, input().split())
    result = count_coprime(A, B, N)
  
    print("Case #", end = '')
    print(i, end = '')
    print(": ", end = '')
    print(result)
    
