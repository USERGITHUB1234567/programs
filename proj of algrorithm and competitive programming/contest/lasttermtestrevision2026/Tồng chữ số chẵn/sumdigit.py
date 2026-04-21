import sys
s=sys.stdin.readline().strip()
ans=0
for i in range(len(s)):
    t=int(s[i])
    if(not (t&1)) :ans+=t
print(ans)