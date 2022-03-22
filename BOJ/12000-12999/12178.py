T = int(input())
multifactorial = []

def lower_bound(target):
    lo = 0
    hi = len(multifactorial)
    
    while lo < hi:
        mid = (lo + hi) // 2
        
        if multifactorial[mid] < target:
            lo = mid + 1
        else:
            hi = mid
    
    return lo

def calc_multifactorial(n):
    val = 1;
    
    for i in range(9000, 1, -n):
        val *= i
        
    digit_cnt = 0;
    
    while val > 0:
        digit_cnt += 1
        val = val // 10
        
    return digit_cnt

for i in range(1, 9000):
    multifactorial.append(calc_multifactorial(i));
  
multifactorial.reverse();

for t in range(1, T+1):
    D = int(input())
    ans = 8998 - lower_bound(D) + 2
    
    print("Case #", end="")
    print(t, end="")
    print(": ", end="")
    
    if (ans == 9000):
        print("...")
    else:
        print("IT'S OVER 9000", end="")
        for i in range(ans):
            print("!", end="")
        print()
