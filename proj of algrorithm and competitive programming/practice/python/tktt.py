def find(x,a):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1
a=[]
n=int(input())
for i in range(0,n):
    x=int(input())
    a.append(x)
t=int(input())
if(find(t,a)!=-1): print(find(t,a))
else: print("not found")
