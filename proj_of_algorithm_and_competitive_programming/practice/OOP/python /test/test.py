'''n=[int(x)for x in input().split()]
print(n)
a=[]
mx=0
mn=1e18
for i in n:
    mn=min(mn,i)
    mx=max(mx,i)
    a.append(i*i)
print(mn)
print(mx)
print(a)'''
b=(1,2,3,)
print(b[0])
'''for i in b:
    print(i)'''
print(b[-1])
print(b[0:4])
