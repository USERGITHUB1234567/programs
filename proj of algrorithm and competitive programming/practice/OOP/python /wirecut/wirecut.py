n=int(input())
t=int(input())
cnt=0
while n/2>=t:
    cnt+=1
    n/=2
print(cnt)