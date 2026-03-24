n,s=map(int,input().split())
a=[0]+list(map(int,input().split()))
a+=a[1:]
l=1
r=0
t=0
ans=10**1000
while r<len(a)-1:
    r+=1
    t+=a[r]
    while r-l+1>n:
        t-=a[l]
        l+=1
    while l<=r and t-a[l]>=s:
        t-=a[l]
        l+=1
    if(t>=s): ans=min(ans,r-l+1)
if(ans==10**1000): print(-1)
else: print(ans)
