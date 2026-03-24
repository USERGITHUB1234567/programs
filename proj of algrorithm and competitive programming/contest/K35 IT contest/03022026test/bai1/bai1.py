import math
def div(a:int):
    d=[]
    for i in range(1,int(math.sqrt(a))+1):
        if a%i==0:
            d.append(i)
            s=int(math.sqrt(a))
            if(s*s!=a):d.append(int(a/i))
    d.sort()
    return d
n=int(input())
ans=10**1000
a=div(n)
#print(a)
for i in range(0,len(a)-1):
    ans=min(ans,a[i+1]-a[i])
print(ans)