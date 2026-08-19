def check(c):
    d1,d2,d3=c[0]>0,c[1]>0,c[2]>0
    return d1+d2+d3
n,k=map(int,input().split())
a=list(map(int,input().split()))
a=[0]+a
l,r,cnt=0,0,[0,0,0]
ans=0
#print(len(a))
while r<n:
    r+=1
    cnt[a[r]-1]+=1
    while check(cnt)>k:
        l+=1
        cnt[a[l]-1]-=1
    #print(l,r,check(cnt))
    if check(cnt)==k:ans=max(ans,r-l)
    #print(a[r])
print(ans)