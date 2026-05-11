import sys
def sumreplace(n:int)->int:
    return n if n<10 else sumreplace(n//10)+n%10
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    while(n>=10): n=sumreplace(n)
    print(n)