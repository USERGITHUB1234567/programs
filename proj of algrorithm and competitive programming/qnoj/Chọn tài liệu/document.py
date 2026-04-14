import sys
n,t=map(int,sys.stdin.readline().split())
a=list(map(int,sys.stdin.readline().split()))
l,r,s=0,0,0
ans=0
while r<n:
    if a[r]>t:
        r+=1
        l=r
        s=0
        continue
    s+=a[r]
    while s>t and l<r:
        s-=a[l]
        l+=1
    ans=max(ans,r-l+1)
    r+=1
print(ans)