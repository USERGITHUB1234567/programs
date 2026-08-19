k,d,a,b=map(int,input().split())
week=[0,0,a,a,a,a,a,b,b,a,a,a,a,a,b,b]
v=a*5+b*2
ans=v*(d//7)
w=d%7
for i in range(k,k+w):
    ans+=week[i]
    #print(week[i])
print(ans)
