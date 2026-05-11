import sys
n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
ans=0
mn=a[0]
for i in range(n):
    ans=max(ans,a[i]-mn)
    mn=min(mn,a[i])
print(ans)