import sys,math
a,b=map(int,sys.stdin.readline().split())
ans=0
for i in range(1,int(math.sqrt(min(a,b)))+1):

    if not(a%i) and not(b%i): 
        ans+=1
        j=min(a,b)//i
        if not(max(a,b)%j): ans+=1
print(ans)