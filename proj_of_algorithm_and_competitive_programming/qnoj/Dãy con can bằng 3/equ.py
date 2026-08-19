import sys
n=int(sys.stdin.readline())
s=sys.stdin.readline().strip()
mp={}
cur=0
ans=0
mp[0]=1
for i in range(n):
    t=int(s[i])
    cur+=(t-1)
    d=mp.get(cur,0)
    ans+=d
    mp[cur]=d+1
print(ans)