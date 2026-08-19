n,q=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
q=100-q
def ceil(n):
    m=int(n)
    if n-m>0: return m+1
    return n
def cals1(a):
    ans=0
    while len(a)>0:
        if len(a)<3:
            while len(a)>0:
                ans+=a[len(a)-1]
                a.pop()
            continue
        ans+=a[len(a)-1]
        a.pop()
        ans+=a[len(a)-1]
        a.pop()
        a.pop()
    print(ans)
'''class soup2:
    f=[0]*n
    def cal(li):
        return 0
    def solve():
        for i in range(0,n):'''
'''def soup2():
    mn=list([0]*n for _ in range(0,n))
    f,pre=[0]*n,[0]*n
    for i in range(0,n):
        m=10**1000
        for j in range(i,n):
            m=min(m,a[j])
            mn[i][j]=m
            mn[j][i]=m
    pre[0]=a[0]
    for i in range(1,n):
        pre[i]=pre[i-1]+a[i]
    for i in range(0,n):
        b=[]
        for j in range (i,-1,-1):
            b.append(a[j])
            sum
            sum2
            if i>0: 
                sum=pre[j]-pre[i-1]
                sum2=pre[i-1]
            else: 
                sum=pre[j]
                sum2=0
            if i-j<2:'''
def soupfull():
    a.sort()
    if len(a)<3:
        ans=0
        for i in range(0,len(a)):
            ans+=a[i]*q/100
        print(ans)
        return
    f=[10**100]*n
    f[0],f[1],f[2]=a[0]*q/100,(a[1]*q/100)+f[0],min((a[0]+a[1]+a[2])*q/100,a[1]+a[2])
    for i in range(3,n):
        f[i]=min(f[i-3]+a[i]+a[i-1],f[i-1]+a[i]*q/100)
    print(int(f[n-1]))
if q==0:cals1(a)
else:soupfull()

'''
7 10
300 200 200 300 100 300 200

8 20
100 4000 200 500 600 800 900 4900
'''