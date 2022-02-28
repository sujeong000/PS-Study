def GCD(a, b):
  if b == 0:
    return a
  else:
    return GCD(b, a%b)

def LCM(a, b):
  return a * b // GCD(a, b)

def count_one(mask):
    cnt = 0
    
    for i in range(0, 7):
        if mask & (1 << i) != 0:
            cnt += 1
    
    return cnt

def LCMs(mask):
    ret = 1;
    
    for i in range(0, 7):
        if mask & (1 << i) != 0:
            ret = LCM(ret, arr[i])
    
    return ret

N = int(input())
arr = [11, 111, 11111, 1111111, 11111111111, 1111111111111, 11111111111111111]

ret = N;

for i in range(0, (1 << 7)):
    if count_one(i) % 2 == 0:
        ret -= N // LCMs(i)
    else:
        ret += N // LCMs(i)
            
print(ret)
