import sys
sys.setrecursionlimit(15000)
def karatsuba(x , y):
    print("\nX:" + x + "         Y:" + y)
    
    xl = x[0:len(x)//2]
    xr = x[len(x)//2:len(x)]
    yl = y[0:len(y)//2]
    yr = y[len(y)//2:len(y)]
    print("xl:" + xl + "  xr:" + xr + "  yl:" + yl + "  yr:"  + yr)
    len_max = max(len(x), len(y))
    if (min(len(xl), len(xr), len(yl), len(yr)) > 2 ):     
        a = karatsuba(xl, yl)
        d = karatsuba(xr, yr)
        e = karatsuba(str(int(xl) + int(xr)) , str(int(yl) + int(yr))) - a - d
        ans = a * (10**(len_max)) + e * (10**(len_max//2)) + d
        return ans     

    else:
        a = int(xl) * int(yl)
        d = int(xr) * int(yr)
        e = (int(xl) + int(xr)) * (int(yl) + int(yr)) - a - d
        ans = a * (10**(len_max)) + e * (10**(len_max//2)) + d
        return ans


if __name__ == "__main__":
    
    ans = karatsuba("3141592653589793238462643383279502884197169399375105820974944592", "2718281828459045235360287471352662497757247093699959574966967627")
    print("Answer:" ,  ans)
    print("Normal Answer:",3141592653589793238462643383279502884197169399375105820974944592 * 2718281828459045235360287471352662497757247093699959574966967627)