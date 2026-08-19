inf=10**1000
n=int(input())
a=list(map(int,input().split()))
mp={}
t=0
ans=0

for i in range(n):
    if a[i]%2:t-=1
    else:t+=1
    #print(t)
    d=mp.get(t,inf)
    if t==0: 
        ans=max(ans,i+1)
        continue
    if d!=inf: ans=max(ans,i-d)
    else: mp[t]=i
print(ans)