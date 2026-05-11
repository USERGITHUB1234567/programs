import string
s=input()
t=input()
n=len(s)
m=len(t)
i=0
cnt=0
while i <= n - m:
    j=0
    ck=True
    while j<m:
        if(s[i+j]!=t[j]):
            ck=False
            break
        else:
            j+=1
    cnt+=ck
    i+=1
print(cnt)