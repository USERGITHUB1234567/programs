import math
def scp(n:int)->bool:
    s=int(math.sqrt(n))
    return n==s*s
def check(a:int,b:int,c:int)->bool:
    return scp(a*b) and scp(a*c) and scp(b*c)
n=int(input())
def trau():
    ans=0
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            for k in range(j+1,n+1):
                if(check(i,j,k)): 
                    ans+=1
                    print(i,j,k)
    print(ans)
trau()
