n=int(input())
a=list(map(int,input().split()))
t=0
mp={}
ans=0
mp[0]=1
for i in range(n):
    t+=a[i]
    d=t%3
    ans+=mp.get(d,0)
    mp[d]=mp.get(d,0)+1
print(ans)