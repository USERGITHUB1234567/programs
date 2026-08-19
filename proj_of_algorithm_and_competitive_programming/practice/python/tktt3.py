def find(x,a,l,r):
    for i in range(l,r):
        if a[i] == x:
            return i
    return -1
a=[]
n=int(input())
for i in range(0,n):
    x=int(input())
    a.append(x)
t=int(input())
if(find(t,a,0,len(a))!=-1): print(find(t,a,0,len(a)))
else: print("not found")
