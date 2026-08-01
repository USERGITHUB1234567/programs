from array import *
from statistics import *
a=array('i',[])
for i in range(1,10):
    x=int(input())
    a.append(x)
    #print(i)
for i in a:
    print(i)
print(mean(a))