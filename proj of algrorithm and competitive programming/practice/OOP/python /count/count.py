n=input()
a=n.split()
'''for i in range(0,n):
    x=int(input())
    a.append(x)
print(a)'''
for i in a:
    if(a.count(i)==1):
        print(i)
