import sys
maxn=10000007
a=[0]*maxn
cur,i=1,1
while(cur<maxn):
    a[cur]=1
    i+=1
    cur+=i
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    print(1 if a[n]==1 else 0)