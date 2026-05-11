import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n=int.bit_count(int(sys.stdin.readline()))
    if n&1==1:print("odd")
    else:print("even")