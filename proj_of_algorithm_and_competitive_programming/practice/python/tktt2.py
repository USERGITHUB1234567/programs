def find(t,a):
    i=0
    while(i<len(a)):
        if(a[i]==t): return i
    return -1
n=int(input())
a=[]
for i in range(0,n):
    x=int(input())
    a.append(x)
t=int(input())
f=find(t,a)
if(f==-1): print("not found")
else: print(f)