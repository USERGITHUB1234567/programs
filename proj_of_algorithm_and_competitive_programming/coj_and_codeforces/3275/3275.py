import sys,math
mod=100000000
a=[[0,1],[1,1]]
def mul(a,b):
    c=[[0,0],[0,0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])
    return c
def pow(a,n):
    c=[[1,0],[0,1]]
    while n:
        if n&1:
            c=mul(c,a)
        a=mul(a,a)
        n>>=1
    return c
def f(n):
    if n==0:
        return 0
    return pow(a,n-1)[1][1]
n,m=map(int,sys.stdin.readline().split())
print(math.gcd(f(n),f(m))%mod)
