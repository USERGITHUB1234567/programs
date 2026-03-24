n=int(input())
a=[]
for i in range(0,n):
    x=int(input())
    a.append(x)
t=int(input())
l=0
r=len(a)-1
a.sort
while(l<r):
    m=(l+r)//2
    if(a[m]==t):
        print(m)
        break
    elif(a[m]<t):
        l=m+1
    else:
        r=m-1
else:
    print("not found")