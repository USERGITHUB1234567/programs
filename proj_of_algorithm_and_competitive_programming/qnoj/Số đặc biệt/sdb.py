import math
maxn=1000006
sum=[0]*maxn
def sieve():
    for i in range(1,maxn//2):
        for j in range(i*2,maxn-1,i):
            sum[j]+=i
n=int(input())
sieve()
cnt=0
for i in range(1,n+1):
    if sum[i]>i:cnt+=1
#print(sum[1000000])
print(cnt)