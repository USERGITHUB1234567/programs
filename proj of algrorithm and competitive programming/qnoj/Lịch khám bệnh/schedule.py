import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n,x=map(int,sys.stdin.readline().split())
    print(max(0,(n-1)*(10-x)))