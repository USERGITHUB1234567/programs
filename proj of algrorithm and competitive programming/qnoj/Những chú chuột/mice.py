import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    a,b=list(map(int,sys.stdin.readline().split())),list(map(int,sys.stdin.readline().split()))
    a.sort()
    b.sort()
    ans=0
    for i in range(n):
        ans=max(ans,abs(a[i]-b[i]))
    print(ans)